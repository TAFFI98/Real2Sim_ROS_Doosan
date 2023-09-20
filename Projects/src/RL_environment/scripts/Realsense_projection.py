#!/usr/bin/env python
from sensor_msgs.msg import CameraInfo
import yaml
import rospy
from sensor_msgs.msg import Image
import pickle
import numpy as np
from pyquaternion import Quaternion
from pyquaternion import Quaternion
from scipy.spatial.transform import Rotation as R
import copy
import cv2
import json
import pyrealsense2 as tf
from cv_bridge import CvBridge, CvBridgeError

class Realsense_projection:

  def __init__(self):
    print("Initializing Realsense Class .....")
    self.bridge = CvBridge()	

    # -------------------- REALSENSE IMAGE SUBSCIBER ------------------#
    self.suscriber_image = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
    self.orientation_camera = [-180 , 0, 0 ] # X;Y;Z Euler Angles
    self.position_camera = [0.017,0.512, 0.489]
    self._intrinsics, self._extrinsics, self.transformation_matrix  = self.init_realsense_model(self.orientation_camera,self.position_camera)

  def init_realsense_model(self, orientation_camera, position_camera):
    """
    Initialization of the camera intrisic , extrinsic and trasformation matrix parameters.
    """

    orientation_camera_matrix_ = self.euler_to_rotation_matrix(orientation_camera[0], orientation_camera[1], orientation_camera[2])
    orientation_camera_matrix  = [element for array in orientation_camera_matrix_ for element in array]
    _intrinsics = tf.intrinsics()
    _intrinsics.width = 640
    _intrinsics.height = 480
    _intrinsics.ppx =  320.0
    _intrinsics.ppy = 240.0
    _intrinsics.fx = 462.1379699707031
    _intrinsics.fy = 462.1379699707031
    _intrinsics.model  =  tf.distortion.brown_conrady 
    _intrinsics.coeffs = [0,0,0,0,0]
    _extrinsics = tf.extrinsics()
    _extrinsics.translation = position_camera
    _extrinsics.rotation = orientation_camera_matrix


    position = np.multiply(np.asarray([position_camera[0],position_camera[1],position_camera[2]]),np.array([[1000,1000,1000]], np.float32))
    upper_matrix = np.concatenate((orientation_camera_matrix_, position.T), axis=1)
    lower_matrix = np.array([[0,0,0,1]])
    tranformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)
    return _intrinsics, _extrinsics, tranformation_matrix
    
  def euler_to_rotation_matrix(self,roll_deg, pitch_deg, yaw_deg):
    """
    Convert Euler angles (roll, pitch, yaw) in degrees to a 3x3 rotation matrix.

    Args:
    roll_deg (float): Rotation angle around the X-axis (in degrees).
    pitch_deg (float): Rotation angle around the Y-axis (in degrees).
    yaw_deg (float): Rotation angle around the Z-axis (in degrees).

    Returns:
    np.ndarray: A 3x3 rotation matrix.
    """
    # Convert degrees to radians
    roll = np.radians(roll_deg)
    pitch = np.radians(pitch_deg)
    yaw = np.radians(yaw_deg)

    # Calculate sine and cosine values for each angle
    cos_roll = np.cos(roll)
    sin_roll = np.sin(roll)
    cos_pitch = np.cos(pitch)
    sin_pitch = np.sin(pitch)
    cos_yaw = np.cos(yaw)
    sin_yaw = np.sin(yaw)

    # Compute the rotation matrix
    rotation_matrix = np.array([
        [cos_yaw * cos_pitch, cos_yaw * sin_pitch * sin_roll - sin_yaw * cos_roll, cos_yaw * sin_pitch * cos_roll + sin_yaw * sin_roll],
        [sin_yaw * cos_pitch, sin_yaw * sin_pitch * sin_roll + cos_yaw * cos_roll, sin_yaw * sin_pitch * cos_roll - cos_yaw * sin_roll],
        [-sin_pitch, cos_pitch * sin_roll, cos_pitch * cos_roll]
    ])
    return rotation_matrix

  def image_callback(self, image_msg):
      """
      Callback to read the Realsense image from '/camera/color/image_raw' topic
      """             
      try:
          self.cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")
          #print("Image received")
      except CvBridgeError as e:
          rospy.logerr(e)
          return
		
  def image_show(self):
      """
      Show image in OpenCV
      """             
      cv2.namedWindow('Camera Image')
      cv2.imshow("Camera Image",self.cv_image)
      cv2.waitKey(1)

  def image_saving(self, filename):
      """
      Save image
      Args:
          filename : Path to save image
      """              
      print("Saving image...")
      cv2.imwrite(filename , self.cv_image)
      print("Image saved!")

  def transform_from_global_to_camera_frame(self, global_position):
      """
      Transform trajectory from global to camera ref frame
      """
      self.n_points = global_position.shape[0]
      global_position_camera = np.empty((self.n_points,4))
      for i in range(self.n_points):
        global_position_camera[i,:] = np.matmul(self.transformation_matrix,global_position[i,:])
      self.global_position_camera = global_position_camera[:,0:3]

  def project_to_image(self):
    """
      Project trajectory from camera ref frame to pixels
    """
    data = rospy.wait_for_message('/camera/color/image_raw', Image, timeout=5)
    image_dec = np.zeros((self._intrinsics.height, self._intrinsics.width, 3), dtype='uint8') 
    cv_image_processed = self.cv_image
    for point in range(self.n_points):
        x, y, z = self.global_position_camera[point,0], self.global_position_camera[point,1] , self.global_position_camera[point,2] 
        [u,v] = tf.rs2_project_point_to_pixel(self._intrinsics, [x, y, z])  
        if (u >= 0 and v >= 0) and (u < self._intrinsics.width and v < self._intrinsics.height):
            cv2.circle(cv_image_processed, (int(u),int(v)), radius=2, color=(0, 0, 255), thickness=-1)
            image_dec[int(v),int(u),:] = np.array([255,255,255])    
  
    return cv_image_processed
