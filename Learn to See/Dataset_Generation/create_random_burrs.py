import cv2
import numpy as np
import matplotlib.pyplot as plt
import random2

def split(a, n):
    n = min(n, len(a)) # don't create empty buckets
    k, m = divmod(len(a), n)
    return (a[i*k+min(i, m):(i+1)*k+min(i+1, m)] for i in range(n))

def random_burrs(nom_ex, burrs_ex, color):



    # Select randomly which nominal profile to use
    nominal = random2.choice(nom_ex)
    
    # binary_nominal_shape
    _, nominal_shape = cv2.threshold(cv2.cvtColor(nominal.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                            cv2.THRESH_OTSU)

    # opening morphology to get rid of background noise
    kernel = np.ones((2,2),np.uint8)
    nominal_shape = cv2.morphologyEx(nominal_shape, cv2.MORPH_OPEN, kernel)    
    burrs_list = []
    
    # Turn burrs into binary imgs
    for burr in burrs_ex:
        _, bin_burr = cv2.threshold(cv2.cvtColor(burr.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                                cv2.THRESH_OTSU)
        bin_burr = cv2.bitwise_not(bin_burr)
        burrs_list.append(bin_burr)
        
    # Create a new type of burrs (more regular/straight ones)
    contours_nom, hierarchy = cv2.findContours(nominal_shape.copy(), cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    height, width = nominal_shape.shape[:2]
    background = np.zeros((height, width), np.uint8)
    contour_nom = cv2.drawContours(background.copy(), contours_nom, 0, (255, 255, 255), 15)

    contour_pixels = np.argwhere(contour_nom == 255)
    contour_pixels = contour_pixels[contour_pixels[:, 1].argsort()] # sort along y
    # Chose random interval in contour

    sub_contours = list(split(contour_pixels,  10)) # pixels coord of sub-contours

       
    for cont in sub_contours:

        new_contour = np.zeros((height, width), np.uint8)
        for point in cont:
            x = point[0]
            y = point[1]
            new_contour[x,y] = 255 
            
        new_reg_burr = cv2.add(background.copy(), new_contour)
    
        burrs_list.append(new_reg_burr)
    
    '''# to show the finalm list of burrs
    for burr in burrs_list:
        # Show it
        plt.title('burrs')
        plt.imshow(burr, cmap='gray')
        plt.show()'''


    height, width = nominal.shape[:2]
    background = np.zeros((height, width), np.uint8)
    max_n_burrs = 5

    new_burrs = background.copy()

    for i in range(0,random2.randint(1,max_n_burrs)):
        
        bin_burr = random2.choice(burrs_list)
                   
        # Binary burrs
        new_burrs = new_burrs + bin_burr

    # New sole with burrs
    burr_rgb = cv2.cvtColor(new_burrs.copy(), cv2.COLOR_GRAY2RGB)
    white = np.array([255,255,255])
    mask = cv2.inRange(burr_rgb, white-10, white) #base
    burr_rgb[mask!=0] = color
    contours_burr, hierarchy = cv2.findContours(new_burrs, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    burr_rgb = cv2.drawContours(burr_rgb, contours_burr, -1, (124, 124, 124), 10)
    new_w_burrs = np.minimum(nominal.copy() + burr_rgb, nominal.copy())
    
    # binary_nominal_shape
    _, new_w_burrs_bin = cv2.threshold(cv2.cvtColor(new_w_burrs.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                            cv2.THRESH_OTSU)
    
    # find the contours of new sole w burrs to thin out the burrs
    contours_sole, hierarchy = cv2.findContours(new_w_burrs_bin, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    thinning_coeff = random2.randint(1,15)
    thin_out_w_burrs = cv2.drawContours(new_w_burrs.copy(), contours_sole, -1, (255,255,255), thinning_coeff)
    
    '''# Show it
    plt.title('thin out')
    plt.imshow(thin_out_w_burrs)
    plt.show()'''
    
    thinned_burrs = thin_out_w_burrs - nominal.copy()
    
    '''# Show it
    plt.title('thinned Burrs')
    plt.imshow(thinned_burrs)
    plt.show()'''
    
    new_w_burrs = np.minimum(nominal.copy() + thinned_burrs, nominal.copy())
    
    '''# Show it
    plt.title('New w Burrs')
    plt.imshow(new_w_burrs)
    plt.show()'''
    
    # binary_nominal_shape
    _, new_w_burrs_bin = cv2.threshold(cv2.cvtColor(new_w_burrs.copy(), cv2.COLOR_RGB2GRAY), 250, 255, cv2.THRESH_BINARY_INV+
                                            cv2.THRESH_OTSU)

    new_burrs = cv2.subtract(new_w_burrs_bin, nominal_shape)
    
    # opening morphology to get rid of background noise
    kernel = np.ones((2,2),np.uint8)
    new_burrs = cv2.morphologyEx(new_burrs, cv2.MORPH_OPEN, kernel)    
    
    '''# Show it
    plt.title('New Burrs')
    plt.imshow(new_burrs, cmap="gray")
    plt.show()'''



    return nominal, new_w_burrs, new_burrs
