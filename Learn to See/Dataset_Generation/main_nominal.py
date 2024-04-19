# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 13:12:10 2023

@author: martin
"""


import numpy as np
import cv2

import matplotlib.pyplot as plt
from extract_nom import extract_nominal

### IMAGE PRE-PROCESSING ###

# UPLOAD IMAGES

# Read the input images (test images and nominal images must be same dimension)
# Load nominal images
base = cv2.imread("models_burrs_base/base_10.png") #base_10
base = cv2.cvtColor(base, cv2.COLOR_BGR2RGB)
height, width, channels = base.shape


nominal = cv2.imread("models_burrs_base/base_0.png") #nominal
nominal = cv2.cvtColor(nominal, cv2.COLOR_BGR2RGB)
nominal = cv2.resize(nominal, (width, height))

# shape of sole 10
sole_10_path = "models_burrs_base/modelli_burrs_irregolari/start/10.png"
shape = cv2.imread(sole_10_path) #shape of sole 10
shape = cv2.resize(base, (width, height))

# white background
white_bg = cv2.imread("models_burrs_base/white_background.png")
white_bg = cv2.resize(white_bg, (width, height))

# Extract nominal
nom_final = extract_nominal(nominal,base,shape,white_bg)

name = 'models_burrs_base/new_nom.png'
cv2.imwrite(name, nom_final)

'''# show it
plt.title('New_nominal')
plt.imshow(nom_final)
plt.show()'''


