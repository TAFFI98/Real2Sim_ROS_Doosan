
#!/usr/bin/ python3
''' Authors: 
> Martin Molinaro: email="martin.molinaro@mail.polimi.it"
'''

import sys
import os
import cv2
import numpy as np

# -------------------- DEBUG PRINTING SETTINGS -------------------- #
# ANSI escape codes for text color
BOLD = '\033[1m'
RED = '\033[91m'
GREEN = '\033[92m'
YELLOW = '\033[93m'
BLUE = '\033[94m'
CYAN = '\033[36m'
LIGHT_CYAN = '\033[96m'
MAGENTA = '\033[35m'
RESET = '\033[0m'  # Reset to default color

class MyCameraNode(): 

    def __init__ (self, CAMERA_INDEX, CAMERA_RESOL=(640, 480)):
        self.camera_index = CAMERA_INDEX
        self.resol = CAMERA_RESOL

    def capture_image(self):
        # Open the specified camera
        cap = cv2.VideoCapture(self.camera_index)

        # Check if the camera opened successfully
        if not cap.isOpened():
            print(RED + "Error: Could not open camera." + RESET)
            return
        
        # Set the desired image shape
        cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.resol[0])
        cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.resol[1])


        # Capture an image
        ret, frame = cap.read()

        if not ret:
            print(RED + "Error: Failed to capture image." + RESET)
            
        print(GREEN + "Image captured from real camera" + RESET)

        # Release the camera
        cap.release()

        return frame