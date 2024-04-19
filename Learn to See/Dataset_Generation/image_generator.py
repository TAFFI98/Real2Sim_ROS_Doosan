#---import the modules---
import numpy as np
import cv2
import random2

from tensorflow.keras.preprocessing.image import ImageDataGenerator





def image_gen(image_data, burr_data):

    # convert binary img into rgb (3D array)
    burr_data = cv2.cvtColor(burr_data, cv2.COLOR_GRAY2RGB)
    
    # convert into a 4-D array of 1 element of 3D array representing the image
    images_data = np.expand_dims(image_data, axis=0)
    burrs_data = np.expand_dims(burr_data, axis=0)

    # create image data augmentation generator
    datagen_img = ImageDataGenerator(width_shift_range=0.0005,
                                height_shift_range=0.05,
                                horizontal_flip=True,
                                vertical_flip=True,
                                rotation_range=100)
    
    datagen_burrs = ImageDataGenerator(width_shift_range=0.0005,
                                height_shift_range=0.05,
                                horizontal_flip=True,
                                vertical_flip=True,
                                rotation_range=100)
    
    # Provide the same seed and keyword arguments to the fit and flow methods
    seed = random2.randint(1,100)
    datagen_img.fit(images_data, augment=False, seed=seed)
    datagen_burrs.fit(burrs_data, augment=False, seed=seed)

    # prepare the iterator; flow() takes in a 4D array and returns
    # an iterator containing a batch of images
    train_generator_img = datagen_img.flow(images_data, batch_size=1, seed=seed)
    train_generator_burrs = datagen_burrs.flow(burrs_data, batch_size=1, seed=seed)
   
    return train_generator_img, train_generator_burrs

