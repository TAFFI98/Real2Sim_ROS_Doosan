'''In the pix2pix cGAN, you condition on input images and generate corresponding output images. cGANs were first proposed in Conditional Generative Adversarial Nets (Mirza and Osindero, 2014)

The architecture of your network will contain:

A generator with a U-Net-based architecture.
A discriminator represented by a convolutional PatchGAN classifier (proposed in the pix2pix paper).'''

## Import tensorflow and other libraries ##
import tensorflow as tf

import os
import pathlib
import time
import datetime
import cv2
import numpy as np




class GAN_Pix2Pix:
    def __init__(self, img_path ):
        ## Process the image to input the generator ##
        self.img_path = img_path 
        # Input image must be 256x256 in size
        self.IMG_WIDTH = 256
        self.IMG_HEIGHT = 256

        # Input and output images channel dimension
        self.INPUT_CHANNELS = 3
        self.OUTPUT_CHANNELS = 1



    def load(self, image_file):
        # Read and decode an image file to a uint8 tensor
        image = tf.io.read_file(image_file)
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
    
    def load_image(self, image_file):
        image, inp_width, inp_height = self.load(image_file)
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

    # Generator complete definition
    def Generator(self):
        downsample = self.downsample
        upsample = self.upsample
        inputs = tf.keras.layers.Input(shape=[256, 256, self.INPUT_CHANNELS])

        down_stack = [
            downsample(64, 4, apply_batchnorm=False),  # (batch_size, 128, 128, 64)
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
        ]

        initializer = tf.random_normal_initializer(0., 0.02)
        last = tf.keras.layers.Conv2DTranspose(self.OUTPUT_CHANNELS, 4,
                                                strides=2,
                                                padding='same',
                                                kernel_initializer=initializer,
                                                activation='tanh')  # (batch_size, 256, 256, 3)

        x = inputs

        # Downsampling through the model
        skips = []
        for down in down_stack:
            x = down(x)
            skips.append(x)

        skips = reversed(skips[:-1])

        # Upsampling and establishing the skip connections
        for up, skip in zip(up_stack, skips):
            x = up(x)
            x = tf.keras.layers.Concatenate()([x, skip])

        x = last(x)

        return tf.keras.Model(inputs=inputs, outputs=x)


    ## DISCRIMINATOR ##
    def Discriminator(self):

        downsample = self.downsample
        upsample = self.upsample
        initializer = tf.random_normal_initializer(0., 0.02)

        inp = tf.keras.layers.Input(shape=[256, 256, self.INPUT_CHANNELS], name='input_image')
        tar = tf.keras.layers.Input(shape=[256, 256, self.OUTPUT_CHANNELS], name='target_image')

        x = tf.keras.layers.concatenate([inp, tar])  # (batch_size, 256, 256, INPUT_CHANNELS+OUTPUT_CHANNELS)

        down1 = downsample(64, 4, False)(x)  # (batch_size, 128, 128, 64)
        down2 = downsample(128, 4)(down1)  # (batch_size, 64, 64, 128)
        down3 = downsample(256, 4)(down2)  # (batch_size, 32, 32, 256)

        zero_pad1 = tf.keras.layers.ZeroPadding2D()(down3)  # (batch_size, 34, 34, 256)
        conv = tf.keras.layers.Conv2D(512, 4, strides=1,
                                        kernel_initializer=initializer,
                                        use_bias=False)(zero_pad1)  # (batch_size, 31, 31, 512)

        batchnorm1 = tf.keras.layers.BatchNormalization()(conv)

        leaky_relu = tf.keras.layers.LeakyReLU()(batchnorm1)

        zero_pad2 = tf.keras.layers.ZeroPadding2D()(leaky_relu)  # (batch_size, 33, 33, 512)

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

        checkpoint_dir = '/root/catkin_ws/learn_to_see_gan/trained_gan_checkpoint/'
        checkpoint = tf.train.Checkpoint(generator_optimizer=generator_optimizer,
                                        discriminator_optimizer=discriminator_optimizer,
                                        generator=generator,
                                        discriminator=discriminator)
        
        checkpoint.restore(tf.train.latest_checkpoint(checkpoint_dir)).expect_partial()

        trained_gen = generator
        trained_discr = discriminator

        return trained_gen, trained_discr

    def Decode_image(self, img_path): 
        model_gen, model_discr = self.Trained_GAN()
        input_img, inp_width, inp_height = self.load_image(img_path)
        decoded = model_gen(input_img, training=True)
        decoded = self.resize(decoded[0],inp_width, inp_height)

        return decoded


