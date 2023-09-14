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


class Cartestian_to_pixel:
  def __init__(self, camera_model_path, camera_global_pose, local_coord_path, global_coord_path, img_path ):
    
    self.camera_model_path = camera_model_path
    self.camera_global_pose = camera_global_pose
    self.local_coord_path = local_coord_path
    self.global_coord_path = global_coord_path
    self.img_path = img_path 

    self.camera_model = self.init_camera_model(self.camera_model_path)
    self.camera_optical_frame_mm = self.define_camera_optical_frame(self.camera_global_pose)
    self.camera_optical_frame_m = self.define_camera_optical_frame(self.camera_global_pose, mm=False)
    self.local_traj = self.define_local_position_traj(self.local_coord_path )
    self.transformation_matrix = self.define_tansformation_matrix_global_to_camera_frame(self.global_coord_path)
    self.global_traj =  self.define_global_position_traj(self.transformation_matrix, self.local_traj)
  
  def init_camera_model(self, camera_model_path):
      # Construct camera model from YAML
      with open(camera_model_path, 'rb') as f:
          camera_info = yaml.load(f, Loader=yaml.FullLoader)
          ci = CameraInfo()
          ci.header.frame_id = camera_info["header"]['frame_id']
          ci.width = camera_info['width']
          ci.height = camera_info['height']
          ci.distortion_model = camera_info['distortion_model']
          ci.D = camera_info['D']
          ci.K = camera_info['K']
          ci.P = camera_info['P']
          ci.R = camera_info['R']
          camera_model = PinholeCameraModel()
          camera_model.fromCameraInfo(ci)

      return camera_model

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

  def define_camera_optical_frame(self, camera_global_pose, mm = True):
      camera_x = camera_global_pose[0]      # mm
      camera_y = camera_global_pose[1]      # mm
      camera_z = camera_global_pose[2]      # mm
      camera_Rx = camera_global_pose[3]     # deg
      camera_Ry = camera_global_pose[4]     # deg
      camera_Rz = camera_global_pose[5]     # deg
      if mm == True:
        camera_optical_frame_mm = sm.SE3(camera_x, camera_y, camera_z) * sm.SE3.Rx(camera_Rx, unit='deg') * sm.SE3.Ry(camera_Ry, unit='deg') * sm.SE3.Rz(camera_Rz, unit='deg')
        return camera_optical_frame_mm
      else:
        camera_optical_frame_m = sm.SE3(camera_x*0.001, camera_y*0.001, camera_z*0.001) * sm.SE3.Rx(camera_Rx, unit='deg') * sm.SE3.Ry(camera_Ry, unit='deg') * sm.SE3.Rz(camera_Rz, unit='deg')
        return camera_optical_frame_m
      
  def define_local_position_traj(self, local_coord_path):
    
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
  
  def define_global_position_traj(self, transformation_matrix, local_traj):
        global_traj = np.empty((local_traj.shape[0], 4))
        for i in range(local_traj.shape[0]):
          global_traj[i,:]= np.matmul(transformation_matrix,local_traj[i,:])
        return global_traj
  
  def create_pointcloud(self, array_of_points_coordinates, mm = True):
    if mm ==True: 
      pc = o3d.geometry.PointCloud()
      pc.points = o3d.utility.Vector3dVector(array_of_points_coordinates)   
    else:
      pc = o3d.geometry.PointCloud()
      pc.points = o3d.utility.Vector3dVector(array_of_points_coordinates*0.001) 
    return  pc
  
  def project_to_image(self, cam_model, pcd, img_path):
    image = cv2.imread(img_path)
    points = np.asarray(pcd.points)
    image_dec = np.zeros((cam_model.height, cam_model.width, 3), dtype='uint8') 
    for point in points:
        x, y, z = point        
        (u,v) = cam_model.project3dToPixel((x, y, z))
        if (u >= 0 and v >= 0) and (u < cam_model.width and v < cam_model.height):
            cv2.circle(image, (int(u),int(v)), radius=2, color=(0, 0, 255), thickness=-1)
            image_dec[int(v),int(u),:] = np.array([255,255,255])    
    return image, image_dec
  
  def transform_pc_from_global_to_camera_frame(self, pc, camera_optical_frame):
        pc_transform = copy.deepcopy(pc)
        pc_transform.transform(camera_optical_frame.inv().A)
        return pc_transform