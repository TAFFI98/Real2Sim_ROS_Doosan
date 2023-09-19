from pathlib import Path
import cv2
from Cartesian_to_pixel import Cartestian_to_pixel
from Realsense_projection import Realsense_projection


def main(camera_model_path, camera_global_pose, local_coord_path, global_coord_path, img_path, show_images = True, output_path = None):
    
    # Initialize class for 3D to pixel projection
    Cartesian_to_pixel = Cartestian_to_pixel(camera_model_path, camera_global_pose, local_coord_path, global_coord_path, img_path)
    
    # Define the camera parameters and optical frame 
    cam_model = Cartesian_to_pixel.camera_model
    cam_model_realsense = Cartesian_to_pixel.camera_model
    camera_optical_frame_mm = Cartesian_to_pixel.camera_optical_frame_mm
    camera_optical_frame_m = Cartesian_to_pixel.camera_optical_frame_m
    
    # Define the pointcloud with the 3D points of the burrs 
    global_traj_mm = Cartesian_to_pixel.create_pointcloud(Cartesian_to_pixel.global_traj[:,0:3])
    global_traj_m = Cartesian_to_pixel.create_pointcloud(Cartesian_to_pixel.global_traj[:,0:3], mm =False)

    # Transform the 3D points from global frame to the camera frame
    traj_camera_frame = Cartesian_to_pixel.transform_pc_from_global_to_camera_frame(global_traj_mm, camera_optical_frame_mm)
    
    # Create Projected image and the decoder image
    projected_image, decoder_img  = Cartesian_to_pixel.project_to_image(cam_model, traj_camera_frame, img_path)
    
    if show_images == True:
        Cartesian_to_pixel.visualise_coordinate_frames(camera_optical_frame_m)
        Cartesian_to_pixel.visualise_points_and_coordinate_frames(global_traj_m, camera_optical_frame_m)
        cv2.imshow('Projected image',projected_image)
        cv2.waitKey(0)
        cv2.imshow('Decoder image',decoder_img)
        cv2.waitKey(0)

    if output_path != None:
        img_name = Path(img_path).stem
        cv2.imwrite(output_path + '%s_projected.png'%(img_name), projected_image)
        cv2.imwrite(output_path + '%s_decoder.png' %(img_name), decoder_img)


def main_Realsense(img_path, local_coord_path, global_coord_path, show_images = True, output_path = None):
    
    # Initialize class for 3D to pixel projection
    RS_projection = Realsense_projection(img_path, local_coord_path, global_coord_path)
    
    # Define the camera parameters and optical frame 
    camera_optical_frame_mm = RS_projection.camera_optical_frame_mm
    camera_optical_frame_m = RS_projection.camera_optical_frame_m
    
    # Define the pointcloud with the 3D points of the burrs 
    global_traj_mm = RS_projection.create_pointcloud(RS_projection.global_traj[:,0:3])
    global_traj_m = RS_projection.create_pointcloud(RS_projection.global_traj[:,0:3], mm =False)

    # Transform the 3D points from global frame to the camera frame
    traj_camera_frame = RS_projection.transform_pc_from_global_to_camera_frame(global_traj_mm, camera_optical_frame_mm)
    
    # Create Projected image and the decoder image
    projected_image, decoder_img  = RS_projection.project_to_image(traj_camera_frame, img_path)
    
    if show_images == True:
        RS_projection.visualise_coordinate_frames(camera_optical_frame_m)
        RS_projection.visualise_points_and_coordinate_frames(global_traj_m, camera_optical_frame_m)
        cv2.imshow('Projected image',projected_image)
        cv2.waitKey(0)
        cv2.imshow('Decoder image',decoder_img)
        cv2.waitKey(0)

    if output_path != None:
        img_name = Path(img_path).stem
        cv2.imwrite(output_path + '%s_projected.png'%(img_name), projected_image)
        cv2.imwrite(output_path + '%s_decoder.png' %(img_name), decoder_img)

if __name__ == '__main__':

    #---------------rosrun tf tf_echo world camera_frame --- TO GET THE EXTRISIC PARAMETERS OF THE CAMERA-------------------#
    
    #------------------USING THE PINEHOLE MODEL--------------#
    '''
    camera_x = -17      # mm
    camera_y = 513      # mm
    camera_z = 489      # mm
    camera_Rx = -179.954       # deg
    camera_Ry = 0     # deg
    camera_Rz = -0.046     # deg

    camera_global_pose = [camera_x, camera_y, camera_z, camera_Rx, camera_Ry, camera_Rz]
    camera_model_path = '/root/catkin_ws/dataset_learn_to_see/dataset_config/camera.json'
    
    for sole_number in range(22,23):
        for index in range(0,3):
            local_coord_path = '/root/catkin_ws/dataset_learn_to_see/dataset_config/suola_%s.txt' % (sole_number)
            global_coord_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.json' % (sole_number, index)
            img_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.png' % (sole_number, index)
            output_path = '/root/catkin_ws/dataset_learn_to_see/'
            print(global_coord_path)
            main(camera_model_path, camera_global_pose, local_coord_path, global_coord_path, img_path, show_images = True, output_path = output_path)
    '''

    #------------------USING THE REALSENSE MODEL--------------#
    for sole_number in range(2,3):
        for index in range(1,3):
            local_coord_path = '/root/catkin_ws/dataset_learn_to_see/dataset_config/suola_%s.txt' % (sole_number)
            global_coord_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.json' % (sole_number, index)
            img_path = '/root/catkin_ws/dataset_learn_to_see/img_sole_%s_%s.png' % (sole_number, index)
            output_path = '/root/catkin_ws/dataset_learn_to_see/'
            print(global_coord_path)
            main_Realsense(img_path, local_coord_path, global_coord_path, show_images = True, output_path = output_path)