import cv2
import numpy as np
import argparse
import matplotlib.pyplot as plt

def remove_bg(img, white):
    white_background = np.copy(white)
    # Convert to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    _, binary = cv2.threshold(gray, 250, 255, cv2.THRESH_BINARY_INV +
                                      cv2.THRESH_OTSU)
    
    contours, hierarchy = cv2.findContours(binary, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    image = cv2.drawContours(white_background, contours, 0, (0, 0, 0), -1) # to limit the max burr area
    # image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    # closing morphology to get rid of background noise
    kernel = np.ones((12,12),np.uint8)
    image = cv2.morphologyEx(image, cv2.MORPH_CLOSE, kernel)
    image = cv2.add(image, img)
    return image
