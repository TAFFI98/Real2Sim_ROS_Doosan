#---import the modules---
import cv2
import numpy as np
import math
from PIL import Image
from create_random_burrs import random_burrs
from image_generator import image_gen
from change_color import change_color
from show_image_list import show_image_list
import os
from tqdm import tqdm

# DATASET sizes
 # DATASET SIZE = rdm_burrs_set_size * img_gen_columns * img_gen_rows
rdm_burrs_set_size = 10
img_gen_columns = 2
img_gen_rows = img_gen_columns


# Load nominal images
nom_ex = []
path = 'models_burrs_base/nom_gen/'
files = os.listdir(path)
for i in tqdm(files):
    image = cv2.imread(path +'/'+i)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    nom_ex.append(image)
    

height, width, channels = image.shape

# Load example images with irregular burrs
burrs_ex = []
path = 'models_burrs_base/burrs_extracted/'
files = os.listdir(path)
for i in tqdm(files):
    image = cv2.imread(path +'/'+i)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    burrs_ex.append(image)

# create list to store images with random burrs
list_gen = [image]*(rdm_burrs_set_size)
# create list to store generated random binary burrs
list_burrs = [image]*(rdm_burrs_set_size)

rows = img_gen_rows
columns = img_gen_columns
image_no = 1
# generate images with random burrs (rdm_burrs_set_size as number of images)
final_img_list = []
final_burrs_list = []

width = 480 # final img width
height = 640 # final img height

color_code = 124
color = np.array([color_code,color_code,color_code]) #color of the sole
color_burrs = (color_code,color_code,color_code)

no_burrs_index = 10 # rdm_burrs_set_size/no_burrs_interval*4 = # of soles without burrs

no_burr = np.zeros((height, width), np.uint8)

for i in range(rdm_burrs_set_size):
    
    
    # Generate sole with random burrs
    nominal, list_gen[i], list_burrs[i] = random_burrs(nom_ex, burrs_ex, color)
    
    if i % no_burrs_index-1 == 0:
        # Generate sole without burrs
        list_gen[i] = nominal
        list_burrs[i] = no_burr
    
    
    # Generate images with different orientations and colors
    train_generator_img, train_generator_burrs = image_gen(list_gen[i], list_burrs[i])
        
    # creating and saving the batch of images generated
    for r in range(rows):
        for c in range(columns):
            # extract image from generated dataset
            image_batch = train_generator_img.next()
            image = image_batch[0].astype('uint8')
            burrs_batch = train_generator_burrs.next()
            burrs = burrs_batch[0].astype('uint8')
            
            
            # re-format from array to image
            im = Image.fromarray(image)
            nom = Image.fromarray(nominal)

            burrs = Image.fromarray(burrs)
            
            # changing the sole to random color
            im, nom = change_color(im, nom, color)

           
            # reformat from image to array
            image = np.array(im)
            burrs = np.array(burrs)
            
            h = height
            w = width
            image = cv2.resize(image, (h,w))
            #final_img_list.append(image)
            name = 'generated/image_train_' + str(image_no) + '.png'
            cv2.imwrite(name, image)
            
            

            burrs = cv2.resize(burrs, (h,w))
            #final_burrs_list.append(burrs)
            name = 'generated_binary_burrs/burrs_train_' + str(image_no) + '.png'
            cv2.imwrite(name, burrs)
            
            
    
            image_no += 1


'''# Show images

show_image_list(final_img_list, 
                num_cols=img_gen_columns*img_gen_rows,
                figsize=(20, 10),
                grid=False,
                title_fontsize=0)

show_image_list(final_burrs_list, 
                num_cols=img_gen_columns*img_gen_rows,
                figsize=(20, 10),
                grid=False,
                title_fontsize=0)'''