from pathlib import Path
import cv2
from Realsense_projection import Realsense_projection


def main_Realsense(img_path, local_coord_path, global_coord_path, show_images , output_path, stl_sole_path):
    
    # --------------Initialize class for 3D to pixel projection ---------#
    RS_projection = Realsense_projection(img_path, local_coord_path, global_coord_path, stl_sole_path)
    
    # --------------Project in 2D ---------#
    projected_image,decoder_img = RS_projection.project_to_image(img_path)
    
    if show_images == True:
        RS_projection.visual_3D()
        cv2.imshow('Projected image',projected_image)
        cv2.waitKey(0)
        cv2.imshow('Decoder image',decoder_img)
        cv2.waitKey(0)

    if output_path != None:
        img_name = Path(img_path).stem
        cv2.imwrite(output_path + '%s_projected.png'%(img_name), projected_image)
        cv2.imwrite(output_path + '%s_decoder.png' %(img_name), decoder_img)

if __name__ == '__main__':
    
    for sole_number in range(10,21):
        for index in range(0,4):

            # ----- Paths definition ----#
            local_coord_path = '/root/catkin_ws/dataset_learn_to_see/dataset_config/suola_%s.txt' % (sole_number)
            global_coord_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.json' % (sole_number, index)
            img_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.png' % (sole_number, index)
            stl_sole_path = '/root/catkin_ws/src/doosan-robot/sole/meshes/sole_%s.stl' % (sole_number)
            output_path = '/root/catkin_ws/dataset_learn_to_see/'

            # ----- Burr position projection on images ----#
            main_Realsense(img_path, local_coord_path, global_coord_path, show_images = True, output_path = output_path, stl_sole_path = stl_sole_path)