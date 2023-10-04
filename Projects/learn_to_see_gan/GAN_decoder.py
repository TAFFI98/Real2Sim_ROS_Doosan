from pathlib import Path
import cv2
import tensorflow as tf
import numpy as np
from gan_structure import GAN_Pix2Pix


def main_Gan(img_path, show_images , output_path):
    
    # --------------Initialize class for GAN decoder---------#
    GAN = GAN_Pix2Pix(img_path)
    
    # --------------Input image ---------#
    input_img = cv2.imread(img_path)

    # --------------Decoded image ---------#
    decoded_img = GAN.Decode_image(img_path)
    decoded_img = tf.keras.utils.array_to_img(decoded_img)
    decoded_img = np.array(decoded_img)

    if show_images == True:
        window_dim = 600
        cv2.namedWindow('Input_image',cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Input_image', window_dim,window_dim)
        cv2.imshow('Input_image',input_img)
        cv2.waitKey(0)
        cv2.namedWindow('Decoder_image',cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Decoder_image', window_dim,window_dim)
        cv2.imshow('Decoder_image',decoded_img)
        cv2.waitKey(0)

    if output_path != None:
        img_name = Path(img_path).stem
        cv2.imwrite(output_path + '%s_gan_decoder.png' %(img_name), decoded_img)

if __name__ == '__main__':
    
    for sole_number in range(10,21):
        for index in range(0,4):

            # ----- Paths definition ----#
            img_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.png' % (sole_number, index)
            output_path = '/root/catkin_ws/dataset_learn_to_see/'

            # ----- Burr position projection on images ----#
            main_Gan(img_path, show_images = True, output_path = output_path)