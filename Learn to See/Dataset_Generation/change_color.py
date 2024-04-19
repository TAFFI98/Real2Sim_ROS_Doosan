#---import the modules---
import numpy as np
import random2
import cv2
from PIL import Image, ImageEnhance


# custom function to change colors
def change_color(img, nom, color):
    image = img.convert("RGB")
    nom_image = nom.convert("RGB")




    # reformat from image to array
    image = np.array(image)
    nom_image = np.array(nom_image)

    color_variation = random2.randint(0,20)
    new_color = color - color_variation


    
    # First create a uniform color bw base and burrs
    thresh = 20 #small variation due to noise on base color
    mask = cv2.inRange(image, color-thresh, color+thresh) #base
    image[mask!=0] = color
    
    # Change the color to the new one
    mask_new = cv2.inRange(image, color, color)
    image[mask_new!=0] = new_color


    
    
    
    # Generate random Gaussian noise
    mean = 0
    stddev = 4
    noise = np.zeros(image.shape, np.uint8)
    cv2.randn(noise, mean, stddev)

    # Add noise to image
    image = cv2.add(image, noise)
    nom_image = cv2.add(nom_image, noise)


    # re-format from array to image
    image = Image.fromarray(image)
    nom_image = Image.fromarray(nom_image)

    # image brightness changer
    enhancer = ImageEnhance.Brightness(image)

    factor = random2.uniform(0.7,1.2)
    image = enhancer.enhance(factor)

    return image, nom_image



