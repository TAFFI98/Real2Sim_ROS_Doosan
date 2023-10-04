import open3d as o3d
import yaml
import pickle
import numpy as np
import spatialmath as sm
from scipy.spatial.transform import Rotation as R
import copy
import cv2
import json
import pyrealsense2 as tf

class Realsense_projection:
  def __init__(self, img_path, local_coord_path, global_coord_path, stl_sole_path):

    # ---- Initialization of annotation and images paths ---- #
    self.img_path = img_path 
    self.local_coord_path = local_coord_path # Annotation of burr position and tool orientation with respect to sole frame
    self.global_coord_path = global_coord_path # Annotation of sole camera frame position and orientation with respect to global frame
    self.sole_stl_path = stl_sole_path
    self.deburring_tool_path ='/root/catkin_ws/src/doosan-robot/dsr_description/meshes/gripper/deburring_tool/deburring_tool.stl'
        
    # ---- T_cam: Definition of the camera position and orientation in the world ref frame ---- #
    self.T_cam_m = self.define_T_cam(mm=False)
    self.T_cam_mm = self.define_T_cam(mm=True)
    # ---- Initialization of intrinsic and extrisic parameters of the camera ---- #
    self._intrinsics, self._extrinsics  = self.init_realsense_model(self.orientation_camera,self.position_camera)

    # ----T': TCP orientation in burr frame ---- #
    self.T_prime = self.define_T_prime()

    # ---- T_tcp_tool: Tool pose in TCP frame  ---- #
    self.T_tcp_tool_mm = self.define_T_tcp_tool(mm = True)
    self.T_tcp_tool_m = self.define_T_tcp_tool(mm = False)
    
    # ---- T_tool_tcp: TCP pose in Tool frame  ---- #
    self.T_tool_tcp_mm = np.linalg.inv(self.T_tcp_tool_mm)
    self.T_tool_tcp_m = np.linalg.inv(self.T_tcp_tool_m)
    
    # ---- T_sole : Transformation matrix from global reference frame to sole reference frame ---- #
    self.T_sole_m  = self.define_T_sole(self.global_coord_path, mm = False)
    self.T_sole_mm = self.define_T_sole(self.global_coord_path, mm = True)

    # ----  T_burr: Burr pose with respect to sole frame ---- #
    self.T_burr_m = self.define_T_burr(self.local_coord_path, mm = False)
    self.T_burr_mm = self.define_T_burr(self.local_coord_path, mm = True)

    # ---- Global_TCP_poses_trajectory ---- #
    self.global_TCP_poses_trajectory_mm = self.define_global_TCP_poses_trajectory(mm=True)
    self.global_TCP_poses_trajectory_m = self.define_global_TCP_poses_trajectory(mm=False)

    # ---- Global_Tool_poses_trajectory ---- #
    self.global_Tool_poses_trajectory_mm = self.define_global_Tool_poses_trajectory(mm =True)
    self.global_Tool_poses_trajectory_m = self.define_global_Tool_poses_trajectory(mm =False)

  def init_realsense_model(self, orientation_camera, position_camera):
      """
      Initialization of the camera intrisic , extrinsic  parameters.
      """
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

  def define_T_cam(self, mm = True):
      """
      Define camera optical frame with respect to the global one
      """
      self.orientation_camera  = R.from_euler("xyz", [-180 , 0, 0 ] , degrees=True)
      self.position_camera = [-0.017, 0.557, 0.292]
      camera_rotation_matrix = self.orientation_camera.as_matrix()    

      if mm == True:
        camera_position = np.multiply(np.array([self.position_camera]) ,np.array([[1000,1000,1000]], np.float32))
        upper_matrix = np.concatenate((camera_rotation_matrix, camera_position.T), axis=1)
        lower_matrix = np.array([[0,0,0,1]])
        camera_frame_mm = np.concatenate((upper_matrix, lower_matrix), axis=0)
        return camera_frame_mm
      else:
        camera_position = np.array([self.position_camera])         
        upper_matrix = np.concatenate((camera_rotation_matrix, camera_position.T), axis=1)
        lower_matrix = np.array([[0,0,0,1]])
        camera_frame_m = np.concatenate((upper_matrix, lower_matrix), axis=0)
        return camera_frame_m
  
  def define_T_tcp_tool(self, mm = False):
      """
      Define translation and rotation from tcp base to tool
      """
      if mm == True: 
        tcp_translation = np.array([[-12, 0, -166]]) 
      if mm == False: 
        tcp_translation = np.array([[-0.012, 0, -0.166]]) 

      tcp_rotation =  R.from_euler('xyz', [0, 0, -140.948], degrees=True).as_matrix()

      # ---- Transformation matrix definition ---- #
      upper_matrix = np.concatenate((tcp_rotation, tcp_translation.T), axis=1)
      lower_matrix = np.array([[0,0,0,1]])
      transformation_matrix_tcp_tool = np.concatenate((upper_matrix, lower_matrix), axis=0)

      return transformation_matrix_tcp_tool
  
  def define_T_prime(self):
      """
      Define TCP pose in burr ref frame
      """  
      tcp_translation = np.array([[0, 0, 0]])      
      tcp_rotation =  R.from_euler('XYZ', [ 180 , 0, -135], degrees=True).as_matrix()

      # ---- Transformation matrix definition ---- #
      upper_matrix = np.concatenate((tcp_rotation, tcp_translation.T), axis=1)
      lower_matrix = np.array([[0,0,0,1]])
      transformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)

      return transformation_matrix
     
  def define_T_burr(self, local_coord_path, mm):
      '''
      Define burr points position in sole reference frame (lcal_traj) and rotation matrix from sole frame to burr frame (rotation_matrix_O_O1)
      '''
      with open(local_coord_path, 'rb') as handle_1:
          data_1 = handle_1.read()
      local_obj = pickle.loads(data_1) #KEYS ARE: ['OX', 'OY', 'deltaX', 'deltaY', 'tx', 'ty', 'nx', 'ny']
      
      # --------- POSITION TRAJECTORY ----------- #
      n_points = local_obj['tx'].shape[0]
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
      
      # --------- ORIENTATION TRAJECTORY ----------- #
      tx, ty, nx, ny = local_obj['tx'], local_obj['ty'], local_obj['nx'],local_obj['ny']
      
      # ---- Rotation matrix from ref frame in the center of the sole and the one centered on the burr point ---#
      rotation_matrix_O_O1 = np.empty((n_points,3,3)) 
      for i in range(n_points):
          t = np.array([tx[i] , ty[i] , 0])
          n = np.array([nx[i] , ny[i] , 0])
          z = np.cross(t,n)
          rotation_matrix_O_O1[i,:,:] = np.column_stack((t, n, z))
      
      transformation_matrix = np.empty((n_points,4,4)) 
      for i in range(n_points):
          transformation_matrix[i,0:3,0:3] = rotation_matrix_O_O1[i,:,:]
          if mm == True:
            transformation_matrix[i,:,-1] = local_traj[i,:]
          if mm == False:
            transformation_matrix[i,:,-1] = local_traj[i,:] * np.array([0.001,0.001,0.001,1])
          transformation_matrix[i,-1,0:3] = np.array([[0,0,0]])
      return transformation_matrix

  def define_T_sole(self, global_coord_path, mm):
      '''
      Transformation matrix from global to sole reference frame
      '''
      with open(global_coord_path, 'r') as handle_2:
          data_2 = json.load(handle_2)

      global_obj = data_2 # KEYS ARE: ['position', 'orientation']
      
      # ---- Transformation matrix definition ---- #
      position_mm = np.multiply(np.expand_dims(np.asarray(global_obj['position']),axis=0),np.array([[1000,1000,1000]], np.float32))
      position_m = np.expand_dims(np.asarray(global_obj['position']),axis=0)

      orientation = np.asarray(global_obj['orientation'])
      orientation_quaternion  = R.from_quat([orientation[0], orientation[1], orientation[2], orientation[3]])
      rotation_matrix = orientation_quaternion.as_matrix()
      upper_matrix_mm = np.concatenate((rotation_matrix, position_mm.T), axis=1)
      upper_matrix_m = np.concatenate((rotation_matrix, position_m.T), axis=1)

      lower_matrix = np.array([[0,0,0,1]])
      if mm == True:
        return np.concatenate((upper_matrix_mm, lower_matrix), axis=0)
      if mm == False:
        return np.concatenate((upper_matrix_m, lower_matrix), axis=0)

  def define_global_TCP_poses_trajectory(self, mm):
      '''
      Define position and orientation of the Tool in the global ref. frame
      '''
      if mm == True: 
        return self.T_sole_mm @ self.T_burr_mm @ self.T_prime 
      if mm == False: 
        return self.T_sole_m @ self.T_burr_m @ self.T_prime 

  def define_global_Tool_poses_trajectory(self, mm):
      '''
      Define position and orientation of the TCP in the global ref. frame
      '''
      if mm == True: 
        return self.T_sole_mm @ self.T_burr_mm @ self.T_prime @ self.T_tcp_tool_mm
      if mm == False: 
        return self.T_sole_m @ self.T_burr_m @ self.T_prime @ self.T_tcp_tool_m

  def project_to_image(self, img_path):
      '''
      Project from camera ref. frame to pixel space
      '''
      n_points = self.global_TCP_poses_trajectory_m.shape[0]
      image = cv2.imread(img_path)
      image_dec = np.zeros((self._intrinsics.height, self._intrinsics.width, 3), dtype='uint8') 

      for point in range(n_points):
        traj_camera_frame = np.linalg.inv(self.T_cam_mm) @ self.global_TCP_poses_trajectory_mm
        x, y, z = traj_camera_frame[point,0:3,-1][0], traj_camera_frame[point,0:3,-1][1], traj_camera_frame[point,0:3,-1][2]
        [u,v] = tf.rs2_project_point_to_pixel(self._intrinsics, [x, y, z])      
        if (u >= 0 and v >= 0) and (u < self._intrinsics.width and v < self._intrinsics.height):
            cv2.circle(image, (int(u),int(v)), radius=2, color=(0, 0, 255), thickness=-1)
            image_dec[int(v),int(u),:] = np.array([255,255,255])    
      return image, image_dec
  
  def visual_3D(self):
      """
      Visualize camera frame, global frame and burr points
      """
      # Global ref frame
      base_link_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.2,(0, 0, 0))
      
      # Camera ref frame
      camera_optical_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      camera_optical_coord.transform(self.T_cam_m) 
      
      # Sole ref frame
      sole_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      sole_coord.transform(self.T_sole_m)
      
      # # Burr ref frame 
      burr_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.03,(0, 0, 0))
      burr_coord.transform(self.T_sole_m@ self.T_burr_m[100])
      
      # # Sole mesh
      mesh = o3d.io.read_triangle_mesh(self.sole_stl_path)
      scaled_mesh = o3d.geometry.TriangleMesh()
      scaled_mesh.vertices = o3d.utility.Vector3dVector(list(np.asarray(mesh.vertices) / 1000.0))
      scaled_mesh.triangles = mesh.triangles
      scaled_mesh.transform(self.T_sole_m)
      color_array = np.array([[0.5, 0.5, 0.5] ] * len(mesh.vertices))
      scaled_mesh.vertex_colors = o3d.utility.Vector3dVector(color_array)
      

      # # TCP
      tcp_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      tcp_coord.transform(self.global_TCP_poses_trajectory_m[100])
      
      # Deburring tool mesh 
      mesh_tool = o3d.io.read_triangle_mesh(self.deburring_tool_path)
      scaled_mesh_tool = o3d.geometry.TriangleMesh()
      scaled_mesh_tool.vertices = o3d.utility.Vector3dVector(list(np.asarray(mesh_tool.vertices) / 1000.0))
      scaled_mesh_tool.triangles = mesh_tool.triangles
      color_array = np.array([[0.8, 0.1, 0.1] ] * len(scaled_mesh_tool.vertices))
      scaled_mesh_tool.vertex_colors = o3d.utility.Vector3dVector(color_array)
      scaled_mesh_tool.transform(self.global_Tool_poses_trajectory_m[100])
      tool_coord = o3d.geometry.TriangleMesh.create_coordinate_frame(0.1,(0, 0, 0))
      tool_coord.transform(self.global_Tool_poses_trajectory_m[100])
      
      o3d.visualization.draw_geometries([base_link_coord, camera_optical_coord,sole_coord, scaled_mesh, burr_coord, tcp_coord, tool_coord, scaled_mesh_tool])

