'''This code implements a Covolutional Variational AutoEncoder(CVAE).
A VAE is a probabilistic take on the autoencoder, a model which takes high dimensional input data and compresses 
it into a smaller representation. Unlike a traditional autoencoder, which maps the input onto a latent vector, 
a VAE maps the input data into the parameters of a probability distribution, such as the mean and variance of a Gaussian.
This approach produces a continuous, structured latent space, which is useful for image generation.'''
''' 
Inspiration code: 
https://colab.research.google.com/github/tensorflow/docs/blob/master/site/en/tutorials/generative/cvae.ipynb#scrollTo=ITZuApL56Mny
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


class CVAE(tf.keras.Model):
    """Convolutional variational autoencoder."""

    def __init__(self, latent_dim, dropout_rate=0.5):
        super(CVAE, self).__init__()
        print('CVAE model created')
        self.latent_dim = latent_dim
        self.dropout_rate = dropout_rate
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
                tf.keras.layers.Flatten(),
                # No activation
                tf.keras.layers.Dense(self.latent_dim + self.latent_dim),
            ]

        )

        self.decoder = tf.keras.Sequential(
            [
                tf.keras.layers.InputLayer(input_shape=(self.latent_dim,)),
                tf.keras.layers.Dense(units=self.IMG_HEIGHT_VAE//16*self.IMG_WIDTH_VAE//16*256, activation='relu'), #(IMG_HEIGHT/16*IMG_WIDTH/16*256)
                tf.keras.layers.Reshape(target_shape=(self.IMG_HEIGHT_VAE//16, self.IMG_WIDTH_VAE//16, 256)), #(IMG_HEIGHT/16, IMG_WIDTH/16, 256)
                ConvTranspose(filters=128, kernelSize=3, activation='relu'), #(IMG_HEIGHT/8, IMG_WIDTH/8, 128)
                ConvTranspose(filters=64, kernelSize=3, activation='relu'), #(IMG_HEIGHT/4, IMG_WIDTH/4, 64)
                ConvTranspose(filters=64, kernelSize=3, activation='relu'), #(IMG_HEIGHT/2, IMG_WIDTH/2, 64)
                ConvTranspose(filters=32, kernelSize=3, activation='relu'), #(IMG_HEIGHT, IMG_WIDTH, 32)
                # No activation (filter=num_channels_out=1)
                tf.keras.layers.Conv2DTranspose(filters=1, kernel_size=3, strides=1, padding='same'), #(IMG_HEIGHT, IMG_WIDTH, 1),
            ]

        )

    @tf.function
    def sample(self, eps=None):
        if eps is None:
            eps = tf.random.normal(shape=(100, self.latent_dim))
        return self.decode(eps, apply_sigmoid=True)

    def encode(self, x):
        mean, logvar = tf.split(self.encoder(x), num_or_size_splits=2, axis=1)
        return mean, logvar

    def reparameterize(self, mean, logvar):
        eps = tf.random.normal(shape=mean.shape)
        return eps * tf.exp(logvar * .5) + mean

    def decode(self, z, apply_sigmoid=False):
        logits = self.decoder(z)
        if apply_sigmoid:
            probs = tf.sigmoid(logits)
            return probs
        return logits


class CVAE_trained:
    # MANAGING THE trained CVAE
    def __init__(self, latent_dim):

        # Input image must be 256x256 in size
        self.IMG_WIDTH = 320
        self.IMG_HEIGHT = 240
        # set the dimensionality of the latent space
        self.latent_dim = latent_dim


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

    def load_trained_cvae(self):

        optimizer = tf.keras.optimizers.Adam(learning_rate=1e-4)

        # model
        self.model = CVAE(self.latent_dim)
        # Create dummy latent dimensions for initialization
        dummy_latent = tf.ones((1, self.latent_dim))
        _ = self.model.decode(dummy_latent)  # Call the model with dummy input

        checkpoint_dir = '/root/catkin_ws/learn_to_see_gan/trained_cvae_checkpoint/'
        latest_checkpoint = tf.train.latest_checkpoint(checkpoint_dir)
        self.model.load_weights(latest_checkpoint)



    def Extract_latent(self, image_path=None,image_file=None):


        # Prepare the burr (processed image from the cgan decoded)
        burr, inp_width, inp_height = self.load_image(image_path=image_path,image_file=image_file)

        # load trained model
        self.load_trained_cvae()
        # Encode the image into a latent vector
        mean, logvar = self.model.encode(burr)
        latent = self.model.reparameterize(mean, logvar)
        cvae_decoded = self.model.sample(latent)
        cvae_decoded = self.resize(cvae_decoded[0],480, 640)
        cvae_decoded = tf.keras.utils.array_to_img(cvae_decoded)
        cvae_decoded = np.array(cvae_decoded, dtype=np.uint8)
        
        cv2.imwrite("/root/catkin_ws/learning_img_dataset/sole_wip_imgs/cvae_decoded.png", cvae_decoded)
        print('latent shape:', latent.shape)
        latent = tf.reshape(latent,[latent.shape[1],latent.shape[0]]).numpy()
        return latent