import open3d as o3d
from image_geometry import PinholeCameraModel
from sensor_msgs.msg import CameraInfo
import yaml
import pickle
import numpy as np
import spatialmath as sm
from pyquaternion import Quaternion
from scipy.spatial.transform import Rotation as R
import copy
import cv2
import json
import pyrealsense2 as tf

class Realsense_projection:
  def __init__(self, img_path, local_coord_path, global_coord_path):

    self.orientation_camera  = R.from_euler("xyz", [-179.954 , 0, -0.046 ], degrees=True)
    self.position_camera = [-0.017,0.513, 0.489]


    self._intrinsics, self._extrinsics  = self.init_realsense_model(self.orientation_camera,self.position_camera)

    self.img_path = img_path 
    self.local_coord_path = local_coord_path # burr with respect to sole camera frame
    self.global_coord_path = global_coord_path # sole camera frame with respect to global camera frame
    self.camera_optical_frame_mm = self.define_camera_optical_frame()
    self.camera_optical_frame_m = self.define_camera_optical_frame( mm=False)
    self.local_traj = self.define_local_position_traj(self.local_coord_path )
    self.transformation_matrix = self.define_tansformation_matrix_global_to_camera_frame(self.global_coord_path)
    self.global_traj =  self.define_global_position_traj(self.transformation_matrix, self.local_traj)




  def init_realsense_model(self, orientation_camera, position_camera):

    orientation_camera_matrix  = list(orientation_camera.as_matrix())
    orientation_camera_matrix  = [element for array in orientation_camera_matrix for element in array]


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

    return _intrinsics, _extrinsics

  def visualise_points_and_coordinate_frames(self, pcd, camera_optical_frame):
      base_link_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.5,(0, 0, 0))
      camera_optical_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      camera_optical_coord.transform(camera_optical_frame.A) 
      o3d.visualization.draw_geometries([pcd, base_link_coord, camera_optical_coord])

  def visualise_coordinate_frames(self,camera_optical_frame):
      base_link_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.5,(0, 0, 0))
      camera_optical_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      camera_optical_coord.transform(camera_optical_frame.A) 
      o3d.visualization.draw_geometries([ base_link_coord, camera_optical_coord])
  
  def define_camera_optical_frame(self, mm = True):
      camera_x = self.position_camera[0]      # mm
      camera_y = self.position_camera[1]      # mm
      camera_z = self.position_camera[2]      # mm 
      camera_Rx = self.orientation_camera.as_euler("xyz", degrees=True)[0]     # deg
      camera_Ry = self.orientation_camera.as_euler("xyz", degrees=True)[1]     # deg
      camera_Rz = self.orientation_camera.as_euler("xyz", degrees=True)[2]     # deg
      if mm == True:
        camera_optical_frame_mm = sm.SE3(camera_x*1000, camera_y*1000, camera_z*1000) * sm.SE3.Rx(camera_Rx, unit='deg') * sm.SE3.Ry(camera_Ry, unit='deg') * sm.SE3.Rz(camera_Rz, unit='deg')
        return camera_optical_frame_mm
      else:
        camera_optical_frame_m = sm.SE3(camera_x, camera_y, camera_z) * sm.SE3.Rx(camera_Rx, unit='deg') * sm.SE3.Ry(camera_Ry, unit='deg') * sm.SE3.Rz(camera_Rz, unit='deg')
        return camera_optical_frame_m

  def define_local_position_traj(self, local_coord_path):
      # burr points in sole reference frame
      with open(local_coord_path, 'rb') as handle_1:
          data_1 = handle_1.read()
      local_obj = pickle.loads(data_1)
      #KEYS ARE: ['OX', 'OY', 'deltaX', 'deltaY', 'tx', 'ty', 'nx', 'ny']
      OX, OY, OZ = local_obj['OX'], local_obj['OY'], 0 
      delta_X, delta_Y = local_obj['deltaX'],local_obj['deltaY']
      local_pos_origin = np.asarray([OX, OY, OZ,1.0])
      local_X_traj = delta_X + OX
      local_Y_traj = delta_Y + OY
      local_traj = np.empty((local_X_traj.shape[0], 4))
      for i in range(local_X_traj.shape[0]):
          local_traj[i,0]= local_X_traj[i]
          local_traj[i,1]= local_Y_traj[i]
          local_traj[i,2]= OZ
          local_traj[i,3]= 1.0
      local_traj = np.concatenate((np.expand_dims(local_pos_origin,axis =0), local_traj), axis=0)
      return local_traj
  
  def define_global_position_traj(self, transformation_matrix, local_traj):
        # burr points in global reference frame

        global_traj = np.empty((local_traj.shape[0], 4))
        for i in range(local_traj.shape[0]):
          global_traj[i,:]= np.matmul(transformation_matrix,local_traj[i,:])
        return global_traj

  def define_tansformation_matrix_global_to_camera_frame(self, global_coord_path):
      with open(global_coord_path, 'r') as handle_2:
          data_2 = json.load(handle_2)

      global_obj = data_2
      # KEYS ARE: ['position', 'orientation']
      position = np.multiply(np.expand_dims(np.asarray(global_obj['position']),axis=0),np.array([[1000,1000,1000]], np.float32))
      orientation = np.asarray(global_obj['orientation'])
      orientation = Quaternion(orientation[0], orientation[1], orientation[2], orientation[3])
      orientation_quaternion  = R.from_quat([orientation[0], orientation[1], orientation[2], orientation[3]])
      rotation_matrix = orientation_quaternion.as_matrix()
      upper_matrix = np.concatenate((rotation_matrix, position.T), axis=1)
      lower_matrix = np.array([[0,0,0,1]])
      transformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)
      
      return transformation_matrix

  def create_pointcloud(self, array_of_points_coordinates, mm = True):
    if mm ==True: 
      pc = o3d.geometry.PointCloud()
      pc.points = o3d.utility.Vector3dVector(array_of_points_coordinates)   
    else:
      pc = o3d.geometry.PointCloud()
      pc.points = o3d.utility.Vector3dVector(array_of_points_coordinates*0.001) 
    return  pc

  def transform_pc_from_global_to_camera_frame(self, pc, camera_optical_frame):
        # burrs in camera ref frame
        pc_transform = copy.deepcopy(pc)
        pc_transform.transform(camera_optical_frame.inv().A)
        return pc_transform


  def project_to_image(self, pcd, img_path):
    image = cv2.imread(img_path)
    points = np.asarray(pcd.points)
    image_dec = np.zeros((self._intrinsics.height, self._intrinsics.width, 3), dtype='uint8') 
    for point in points:
        x, y, z = point  
        [u,v] = tf.rs2_project_point_to_pixel(self._intrinsics, [x, y, z])      
        #(u,v) = cam_model.project3dToPixel((x, y, z))
        if (u >= 0 and v >= 0) and (u < self._intrinsics.width and v < self._intrinsics.height):
            cv2.circle(image, (int(u),int(v)), radius=2, color=(0, 0, 255), thickness=-1)
            image_dec[int(v),int(u),:] = np.array([255,255,255])    
    return image, image_dec