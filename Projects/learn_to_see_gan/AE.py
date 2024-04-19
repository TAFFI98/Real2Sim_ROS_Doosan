'''
Author: 
> Martin Molinaro: email="martin.molinaro@mail.polimi.it"
'''

## Import tensorflow and other libraries ##
import tensorflow as tf
from tensorflow.keras.layers import (InputLayer, Conv2D, Conv2DTranspose,
            BatchNormalization,ReLU, LeakyReLU, Dropout, MaxPooling2D, UpSampling2D,
            Reshape, GlobalAveragePooling2D, Layer, Conv2D, Dense, Flatten)
from tensorflow.keras.models import Model
import os
import pathlib
import time
import datetime
import cv2
import numpy as np



import warnings
warnings.filterwarnings("ignore")

def ConvLRelu(filters, kernelSize, strides=1):
    # Define Convolutional layer followed by LeakyReLU
    return tf.keras.Sequential([
        Conv2D(filters, kernelSize, strides=strides, padding='same'),
        LeakyReLU()
    ])
def ConvTranspose(filters, kernelSize, strides=1, dropout_rate=0.5, activation=None):
    # Define Convolutional Transpose layer followed by dropout
    return tf.keras.Sequential([
        tf.keras.layers.UpSampling2D(size=(2, 2)),
        tf.keras.layers.Conv2D(filters, kernelSize, strides=strides, padding='same', activation=activation),
        tf.keras.layers.Dropout(dropout_rate)
    ])


class CAE(tf.keras.Model):
    """Convolutional autoencoder."""

    def __init__(self):
        super(CAE, self).__init__()
        self.IMG_HEIGHT_VAE = 240
        self.IMG_WIDTH_VAE = 320
        self.inp_shape = (self.IMG_HEIGHT_VAE, self.IMG_WIDTH_VAE,  1)

        
        # Encoder structure
        self.encoder = tf.keras.Sequential(
            [

                tf.keras.layers.InputLayer(input_shape=self.inp_shape),
                ConvLRelu(filters=32, kernelSize=7, strides=2), #( IMG_HEIGHT/2,IMG_WIDTH/2, 32) # Use at thebeginning big kernels, since the shapes are fine. White pixels at the strict center would give more weight and only zeros around it would give it more weight as well
                ConvLRelu(filters=64, kernelSize=7, strides=2), #(IMG_HEIGHT/4, IMG_WIDTH/4, 128)
                ConvLRelu(filters=128, kernelSize=5, strides=2), #(IMG_HEIGHT/8, IMG_WIDTH/8, 128)
                ConvLRelu(filters=64, kernelSize=3), #(IMG_HEIGHT/8, IMG_WIDTH/8, 64)
                ConvLRelu(filters=128, kernelSize=5), #(IMG_HEIGHT/8, IMG_WIDTH/8, 128)
                ConvLRelu(filters=256, kernelSize=5, strides=2), #(IMG_HEIGHT/16, IMG_WIDTH/16, 256)
                ConvLRelu(filters=128, kernelSize=3), #(IMG_HEIGHT/16, IMG_WIDTH/16, 128)
                ConvLRelu(filters=256, kernelSize=5), #(IMG_HEIGHT/16, IMG_WIDTH/16, 256)
                ConvLRelu(filters=128, kernelSize=5), #(IMG_HEIGHT/16, IMG_WIDTH/16, 128)
                ConvLRelu(filters=64, kernelSize=3), #(IMG_HEIGHT/16, IMG_WIDTH/16, 64)
                ConvLRelu(filters=32, kernelSize=3), #(IMG_HEIGHT/16, IMG_WIDTH/16, 32)
                Conv2D(filters=1, kernel_size=3, strides=1, padding='same'), #(IMG_HEIGHT/16, IMG_WIDTH/16, 1)
                tf.keras.layers.Flatten()
            ]
        )
        self.latent_dim = self.IMG_HEIGHT_VAE//16 * self.IMG_WIDTH_VAE//16 # (from encoder last flattened layer of 15x20=300)

        self.decoder = tf.keras.Sequential(
            [
              InputLayer(input_shape=(self.IMG_HEIGHT_VAE//16* self.IMG_WIDTH_VAE//16*  1)),
              tf.keras.layers.Reshape(target_shape=(self.IMG_HEIGHT_VAE//16, self.IMG_WIDTH_VAE//16, 1)),
              ConvTranspose(filters=256, kernelSize=3, activation='relu'),
              ConvTranspose(filters=128, kernelSize=3, activation='relu'),
              ConvTranspose(filters=64, kernelSize=3, activation='relu'),
              ConvTranspose(filters=32, kernelSize=3, activation='relu'),
              Conv2DTranspose(filters=1, kernel_size=3, strides=1, padding='same')
            ]
        )

    def encode(self, x):
        return self.encoder(x)


    def decode(self, z):
        return self.decoder(z)


class AE_trained:
    # MANAGING THE trained AE
    def __init__(self):

        # Input image must be 256x256 in size
        self.IMG_WIDTH = 320
        self.IMG_HEIGHT = 240



    def load(self, image_path=None, image_file=None):
        # Read and decode an image file to a uint8 tensor
        if image_path != None:
            image = tf.io.read_file(image_path)
        if image_file != None:
            image = image_file
        image = tf.io.decode_png(image, channels=1)
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

    def load_trained_ae(self):

        optimizer = tf.keras.optimizers.Adam(learning_rate=1e-4)

        # model
        self.model = CAE()
        # Create dummy latent dimensions for initialization
        dummy_latent = tf.ones((1, self.model.latent_dim))
        _ = self.model.decode(dummy_latent)  # Call the model with dummy input

        checkpoint_dir = '/root/catkin_ws/learn_to_see_gan/trained_ae_checkpoint/'
        latest_checkpoint = tf.train.latest_checkpoint(checkpoint_dir)
        self.model.load_weights(latest_checkpoint)



    def Extract_latent(self, image_path=None,image_file=None):


        # Prepare the burr (processed image from the cgan decoded)
        burr, inp_width, inp_height = self.load_image(image_path=image_path,image_file=image_file)

        # load trained model
        self.load_trained_ae()
        # Encode the image into a latent vector
        latent = self.model.encode(burr)
        decoded = self.model.decode(latent)
        decoded = self.resize(decoded[0],480, 640)
        decoded = tf.keras.utils.array_to_img(decoded)
        decoded = np.array(decoded, dtype=np.uint8)
        
        cv2.imwrite("/root/catkin_ws/learning_img_dataset/sole_wip_imgs/ae_decoded.png", decoded)
        print('latent shape:', latent.shape)
        latent = tf.reshape(latent,[latent.shape[1],latent.shape[0]]).numpy()
        return latent