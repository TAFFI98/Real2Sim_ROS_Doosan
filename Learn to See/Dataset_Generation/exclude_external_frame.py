# -*- coding: utf-8 -*-
"""
Created on Thu Sep 21 13:22:49 2023

@author: martin
"""
import cv2


def external_contour(img, burrs):
    
    top_corner = (0,0)
    bottom_corner = (img.shape[1], img.shape[0])
    # Draw an external contour to avoid image exting the visual field
    burr = cv2.rectangle(burrs, pt1=top_corner, pt2=bottom_corner, color=(0,0,0), thickness=2)

    image = cv2.rectangle(img, pt1=top_corner, pt2=bottom_corner, color=(255,255,255), thickness=2)
 

    return image, burr

