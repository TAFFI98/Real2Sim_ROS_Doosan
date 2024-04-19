# -*- coding: utf-8 -*-
"""
Created on Sat Oct 28 18:09:14 2023

@author: martin
"""

import cv2
import numpy as np
import math
from PIL import Image

import os
from tqdm import tqdm

# Load example images with irregular burrs
image_no = 1
path1 = 'generated/'
path2= 'generated_binary_burrs/'

files = os.listdir(path2)

for i in tqdm(files):
    image = cv2.imread(path2 +'/'+i)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    path1b = 'train_img/image_train_' + str(image_no) + '.png'
    path2b = 'train_burrs/burrs_train_'  + str(image_no) + '.png'
    cv2.imwrite(path2b, image)
    image_no += 1