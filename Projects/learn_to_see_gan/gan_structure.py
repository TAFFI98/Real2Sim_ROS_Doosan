'''In the pix2pix cGAN, you condition on input images and generate corresponding output images. cGANs were first proposed in Conditional Generative Adversarial Nets (Mirza and Osindero, 2014)

The architecture of your network will contain:

A generator with a U-Net-based architecture.
A discriminator represented by a convolutional PatchGAN classifier (proposed in the pix2pix paper).'''
''' 
Inspiration code: 
https://colab.research.google.com/github/tensorflow/docs/blob/master/site/en/tutorials/generative/pix2pix.ipynb
Author: 
> Martin Molinaro: email="martin.molinaro@mail.polimi.it"
'''

## Import tensorflow and other libraries ##
import tensorflow as tf

import os
import pathlib
import time
import datetime
import cv2
import numpy as np
import thinning

import warnings
warnings.filterwarnings("ignore")


class GAN_Pix2Pix:
    def __init__(self, env_type="SIM"):

        # Input image must be 256x256 in size
        self.IMG_WIDTH = 512
        self.IMG_HEIGHT = 512
        

        # Input and output images channel dimension
        self.INPUT_CHANNELS = 3
        self.OUTPUT_CHANNELS = 1
        self.env_type = env_type


    def load(self, image_path=None, image_file=None):
        # Read and decode an image file to a uint8 tensor
        if image_path != None:
            image = tf.io.read_file(image_path)
        if image_file != None:
            image = image_file
        image = tf.io.decode_png(image, channels=3)
        inp_width = image.shape[0]
        inp_height= image.shape[1]
        image = tf.image.resize(image,(self.IMG_HEIGHT,self.IMG_WIDTH))
        image = tf.expand_dims(image, 0)
        # Convert images to float32 tensors
        image = tf.cast(image, tf.float32)

        return image, inp_width, inp_height
    
    def resize(self, image, height, width):
        image = tf.image.resize(image, [height, width],
                                        method=tf.image.ResizeMethod.NEAREST_NEIGHBOR)
        return image
    
    def normalize(self, image):
        image = (image / 255.0)
        
        return image
    
    def load_image(self, image_path=None, image_file=None):
        image, inp_width, inp_height = self.load(image_path=image_path,image_file=image_file)
        image = self.resize(image,self.IMG_HEIGHT, self.IMG_WIDTH)
        image = self.normalize(image)

        return image, inp_width, inp_height

    ## GENERATOR ##

    # Generator downsampler (encoder)


    def downsample(self, filters, size, apply_batchnorm=True):
        initializer = tf.random_normal_initializer(0., 0.02)

        result = tf.keras.Sequential()
        result.add(
            tf.keras.layers.Conv2D(filters, size, strides=2, padding='same',
                                    kernel_initializer=initializer, use_bias=False))

        if apply_batchnorm:
            result.add(tf.keras.layers.BatchNormalization())

        result.add(tf.keras.layers.LeakyReLU())

        return result

    # Generator upsampler (decoder)
    def upsample(self, filters, size, apply_dropout=False):
        initializer = tf.random_normal_initializer(0., 0.02)

        result = tf.keras.Sequential()
        result.add(
            tf.keras.layers.Conv2DTranspose(filters, size, strides=2,
                                            padding='same',
                                            kernel_initializer=initializer,
                                            use_bias=False))

        result.add(tf.keras.layers.BatchNormalization())

        if apply_dropout:
            result.add(tf.keras.layers.Dropout(0.5))

        result.add(tf.keras.layers.ReLU())

        return result

    def Generator(self):
        downsample = self.downsample
        upsample = self.upsample
        inputs = tf.keras.layers.Input(shape=[self.IMG_HEIGHT, self.IMG_WIDTH, self.INPUT_CHANNELS])


        down_stack = [

            downsample(32, 4, apply_batchnorm=False),  # (batch_size, 256, 256, 32)
            downsample(64, 4),  # (batch_size, 128, 128, 64)
            downsample(128, 4),  # (batch_size, 64, 64, 128)
            downsample(256, 4),  # (batch_size, 32, 32, 256)
            downsample(512, 4),  # (batch_size, 16, 16, 512)
            downsample(512, 4),  # (batch_size, 8, 8, 512)
            downsample(512, 4),  # (batch_size, 4, 4, 512)
            downsample(512, 4),  # (batch_size, 2, 2, 512)
            downsample(512, 4),  # (batch_size, 1, 1, 512)
        ]

        up_stack = [
            upsample(512, 4, apply_dropout=True),  # (batch_size, 2, 2, 1024)
            upsample(512, 4, apply_dropout=True),  # (batch_size, 4, 4, 1024)
            upsample(512, 4, apply_dropout=True),  # (batch_size, 8, 8, 1024)
            upsample(512, 4),  # (batch_size, 16, 16, 1024)
            upsample(256, 4),  # (batch_size, 32, 32, 512)
            upsample(128, 4),  # (batch_size, 64, 64, 256)
            upsample(64, 4),  # (batch_size, 128, 128, 128)
            upsample(32, 4),  # (batch_size, 256, 256, 64)
        ]

        initializer = tf.random_normal_initializer(0., 0.02)
        last = tf.keras.layers.Conv2DTranspose(self.OUTPUT_CHANNELS, 4,
                                                strides=2,
                                                padding='same',
                                                kernel_initializer=initializer,
                                                activation='tanh')

        x = inputs
        skips = []
        for down in down_stack:
            x = down(x)
            skips.append(x)
        
        skips = reversed(skips[:-1])
        

        latent_activations = []  # Store intermediate activations for each layer
        for up, skip in zip(up_stack, skips):
            x = up(x)
            x = tf.keras.layers.Concatenate()([x, skip])
            latent_activations.append(skip)  # Store the activation of this layer

        x = last(x)
        latent = latent_activations[0] #dim (1,2,2,512) = 2048

        return tf.keras.Model(inputs=inputs, outputs=[latent, x])


    ## DISCRIMINATOR ##
    def Discriminator(self):

        downsample = self.downsample
        upsample = self.upsample
        initializer = tf.random_normal_initializer(0., 0.02)

        inp = tf.keras.layers.Input(shape=[self.IMG_HEIGHT, self.IMG_WIDTH, self.INPUT_CHANNELS], name='input_image')
        tar = tf.keras.layers.Input(shape=[self.IMG_HEIGHT, self.IMG_WIDTH, self.OUTPUT_CHANNELS], name='target_image')

        x = tf.keras.layers.concatenate([inp, tar])  # (batch_size, 512, 512, INPUT_CHANNELS+OUTPUT_CHANNELS)

        down0 = downsample(self.IMG_WIDTH//8, 4, False)(x)  # (batch_size, 256, 256, 32)
        down1 = downsample(self.IMG_WIDTH//4, 4)(down0)  # (batch_size, 128, 128, 64)
        down2 = downsample(self.IMG_WIDTH//2, 4)(down1)  # (batch_size, 64, 64, 128)
        down3 = downsample(self.IMG_WIDTH, 4)(down2)  # (batch_size, 32, 32, 256)


        zero_pad1 = tf.keras.layers.ZeroPadding2D()(down3)  # (batch_size, 34, 34, 512)
        conv = tf.keras.layers.Conv2D(self.IMG_WIDTH*2, 4, strides=1,
                                        kernel_initializer=initializer,
                                        use_bias=False)(zero_pad1)  # (batch_size, 31, 31, 1024)

        batchnorm1 = tf.keras.layers.BatchNormalization()(conv)

        leaky_relu = tf.keras.layers.LeakyReLU()(batchnorm1)

        zero_pad2 = tf.keras.layers.ZeroPadding2D()(leaky_relu)  # (batch_size, 33, 33, 1024)

        last = tf.keras.layers.Conv2D(1, 4, strides=1,
                                        kernel_initializer=initializer)(zero_pad2)  # (batch_size, 30, 30, 1)

        return tf.keras.Model(inputs=[inp, tar], outputs=last)


   

    ## Load the trained network ##
    def Trained_GAN(self): 

        # Gan internal models
        generator = self.Generator()
        discriminator = self.Discriminator()

        generator_optimizer = tf.keras.optimizers.Adam(2e-4, beta_1=0.5)
        discriminator_optimizer = tf.keras.optimizers.Adam(2e-4, beta_1=0.5)

        # Load the correct checkpoint based on the simulation or real environment
        if self.env_type == "SIM":
            print("Loading GAN trained on SIM images")
            checkpoint_dir = '/root/catkin_ws/learn_to_see_gan/trained_gan_checkpoint/'
        elif self.env_type == "REAL":
            print("Loading GAN trained on REAL images...")
            checkpoint_dir = '/root/catkin_ws/learn_to_see_gan/trained_real_gan_checkpoint/'
        checkpoint = tf.train.Checkpoint(generator_optimizer=generator_optimizer,
                                        discriminator_optimizer=discriminator_optimizer,
                                        generator=generator,
                                        discriminator=discriminator)
        
        checkpoint.restore(tf.train.latest_checkpoint(checkpoint_dir)).expect_partial()

        trained_gen = generator
        trained_discr = discriminator

        return trained_gen, trained_discr

    def Decode_image(self, image_path=None,image_file=None): 
        model_gen, model_discr = self.Trained_GAN()
        input_img, inp_width, inp_height = self.load_image(image_path=image_path,image_file=image_file)
        latent, decoded = model_gen(input_img, training=True)
        decoded = self.resize(decoded[0],inp_width, inp_height)
        decoded = tf.keras.utils.array_to_img(decoded)
        print('latent shape:', latent.shape)
        latent = tf.reshape(latent,[latent.shape[3]*latent.shape[2]*latent.shape[1],latent.shape[0]])
        return latent, decoded
    
    def Extract_burr(self, input_img, decoded_img): # Extract the burr without small imperfections from decoder
        # Find the shape of the input_img
        _, input_shape = cv2.threshold(cv2.cvtColor(input_img, cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+ cv2.THRESH_OTSU)

        # Find the entire contour of the decoded burr
        _, decoded_bin = cv2.threshold(decoded_img, 250, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
        decoded_bin = cv2.bitwise_not(decoded_bin)
        contours, hierarchy = cv2.findContours(decoded_bin, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
        size_cont = 10
        decoded_contoured_big = cv2.drawContours(decoded_img.copy(), contours, -1, (255, 255, 255), size_cont)
        # Find contours in the bigger(with thick contours) decoded image
        contours_big, _ = cv2.findContours(decoded_contoured_big, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)


        # Find the contour with the largest area
        if contours_big:
            largest_contour = max(contours_big, key=cv2.contourArea)

            # Create a binary image with only the largest contour
            result = np.zeros_like(decoded_img)
            burr_big = cv2.drawContours(result, [largest_contour],-1, (255, 255, 255), -1)
             
            kernel = np.ones((size_cont, size_cont), np.uint8) 
            # Erode image to readjust the tjickness of the added contours 
            burr = cv2.erode(burr_big, kernel, iterations=1) 
            
        return burr
    
    def Extract_contour(self, input_img, decoded_img): # Extract the external contour (single pixel curve) of the burr
        
        decoded_img = self.Extract_burr(input_img, decoded_img) # processed decoded image(get rid of imperfections)
        # Find the shape of the input_img
        _, input_shape = cv2.threshold(cv2.cvtColor(input_img, cv2.COLOR_RGB2GRAY), 200, 255, cv2.THRESH_BINARY_INV+ cv2.THRESH_OTSU)

        # Find the entire contour of the decoded burr
        _, decoded_bin = cv2.threshold(decoded_img, 250, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
        decoded_bin = cv2.bitwise_not(decoded_bin)
        contours_burr, hierarchy = cv2.findContours(decoded_bin, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
        decoded_contoured = cv2.drawContours(decoded_img.copy(), contours_burr, -1, (255, 255, 255), 8)

        # Extract just the external contour of the burr
        decoded_ext_cont = cv2.subtract(decoded_contoured, input_shape)

        # Thinning the contour to achieve a constant thickness of 1 pixel
        #decoded_ext_cont = self.skeletonize(decoded_ext_cont)
        print('\nExtracting burr contour...')
        decoded_ext_cont  = thinning.fastThin(decoded_ext_cont) # a little bit better than skeletonize

        return decoded_img, decoded_ext_cont


    def skeletonize(self, img):
        """ OpenCV function to return a skeletonized version of img, a Mat object"""

        #  hat tip to http://felix.abecassis.me/2011/09/opencv-morphological-skeleton/

        img = img.copy() # don't clobber original
        skel = img.copy()

        skel[:,:] = 0
        kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (3,3))

        while True:
            eroded = cv2.morphologyEx(img, cv2.MORPH_ERODE, kernel)
            temp = cv2.morphologyEx(eroded, cv2.MORPH_DILATE, kernel)
            temp  = cv2.subtract(img, temp)
            skel = cv2.bitwise_or(skel, temp)
            img[:,:] = eroded[:,:]
            if cv2.countNonZero(img) == 0:
                break

        return skel
    



