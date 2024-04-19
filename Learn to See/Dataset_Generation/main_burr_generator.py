# -*- coding: utf-8 -*-
"""
Created on Sat Oct 28 13:49:47 2023

@author: martin
"""

# -*- coding: utf-8 -*-
"""
Created on Fri Sep  8 12:00:57 2023

@author: martin
"""


import numpy as np
import cv2

import matplotlib.pyplot as plt
import os
from tqdm import tqdm

### IMAGE PRE-PROCESSING ###

# UPLOAD IMAGES


# Load soles models

path = 'models_burrs_base/soles_models/'
files = os.listdir(path)
path_save = 'models_burrs_base/burrs_extracted/'
path_save_bin = 'models_burrs_base/burrs_extracted_bin/'

### create a nominal shape ###
base_1 = cv2.imread("models_burrs_base/soles_models/img_sole_n1_0.png")
base_1 = cv2.cvtColor(base_1, cv2.COLOR_BGR2RGB)
base_2 = cv2.imread("models_burrs_base/soles_models/img_sole_n2_0.png")
base_2 = cv2.cvtColor(base_2, cv2.COLOR_BGR2RGB)

# binary img
_, bin_1 = cv2.threshold(cv2.cvtColor(base_1, cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                        cv2.THRESH_OTSU)
_, bin_2 = cv2.threshold(cv2.cvtColor(base_2, cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                        cv2.THRESH_OTSU)
bin_burr_2 = cv2.subtract(bin_2, bin_1)

# subtract the burr from the rbg img (of sole 2)
contours, hierarchy = cv2.findContours(bin_burr_2, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
nominal = cv2.drawContours(base_2.copy(), contours, -1, (255, 255, 255), -1)

# binary_nominal_shape
_, nominal_shape = cv2.threshold(cv2.cvtColor(nominal.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                        cv2.THRESH_OTSU)

# opening morphology to get rid of background noise
kernel = np.ones((2,2),np.uint8)
nominal_shape = cv2.morphologyEx(nominal_shape, cv2.MORPH_OPEN, kernel)

'''# Show it
plt.title('nom bin')
plt.imshow(nominal_shape, cmap="gray")
plt.show()'''

path = 'models_burrs_base/soles_models/'
files = os.listdir(path)
save_path = 'models_burrs_base/burrs_extracted/burr_'
save_nom = 'models_burrs_base/nom_gen/nom_'
for i in tqdm(files):
    image = cv2.imread(path +'/'+i)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    _, bin_img = cv2.threshold(cv2.cvtColor(image, cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                            cv2.THRESH_OTSU)
    
    bin_burr = cv2.subtract(bin_img, nominal_shape)
    contours, hierarchy = cv2.findContours(bin_burr, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    # extract current nomnal (differentiate for shades depending on sole model)
    curr_nom_or = cv2.drawContours(image.copy(), contours, -1, (255, 255, 255), -1)
    _, curr_nom_shape = cv2.threshold(cv2.cvtColor(curr_nom_or.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                            cv2.THRESH_OTSU)
    curr_nom_shape = cv2.cvtColor(cv2.bitwise_not(curr_nom_shape), cv2.COLOR_GRAY2RGB)

    curr_nom = cv2.subtract(curr_nom_or.copy(), curr_nom_shape)
    curr_nom = curr_nom + curr_nom_shape
    
    # extract rgb burr
    burr_rgb = image - curr_nom_or


    # opening morphology to get rid of background noise
    kernel = np.ones((3,3),np.uint8)
    burr_rgb = cv2.morphologyEx(burr_rgb, cv2.MORPH_OPEN, kernel)
    
    name = save_path + i
    cv2.imwrite(name, burr_rgb)
    name = save_nom + i
    cv2.imwrite(name, curr_nom)


