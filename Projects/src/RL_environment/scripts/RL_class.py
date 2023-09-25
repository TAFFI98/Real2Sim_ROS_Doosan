#!/usr/bin/env python
import cv2
import numpy as np
import rospy
import threading
import time
import random
import sys
import os
import pickle
sys.dont_write_bytecode = True
sys.path.append( os.path.abspath(os.path.join("/root/catkin_ws/src/doosan-robot/common/imp")) ) # get import path : DSR_ROBOT.py 
from DSR_ROBOT import *

from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from gazebo_msgs.srv import GetLinkState ,SetLinkState
from gazebo_msgs.msg import ModelState, LinkState

from scipy.spatial.transform import Rotation as R
import tf.transformations as tr

import pyrealsense2 as tf
from pyquaternion import Quaternion

class MyRLEnvironmentNode(): 

        def __init__ (self, ROBOT_ID, ROBOT_MODEL, sole_number):
            print("Initializing MyRLEnvironmentNode.....")
            # --------------------  GROUND TRUTH BURR POSITION AND TOOL ORIENTATION ------------------#
            self.local_coord_path = '/root/catkin_ws/src/RL_environment/scripts/dataset_config/suola_%s.txt' % (sole_number) 

			# -------------------- IMAGE SUBSCRIBER  ------------------#
            self.suscriber_image = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
            self.bridge = CvBridge()	

            # -------------------- CLIENT TO GET THE SOLE POSITION IN GAZEBO ------------------#
            self.sole_n = sole_number
            self.model_coordinates = rospy.ServiceProxy('/gazebo/get_link_state', GetLinkState)			
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_position = self.sole_coordinates.link_state.pose.position
            self.sole_orientation = self.sole_coordinates.link_state.pose.orientation

            # -------------------- CLIENT TO RESET THE SOLE POSITION IN GAZEBO ------------------#
            self.set_model_coordinates = rospy.ServiceProxy('/gazebo/set_link_state', SetLinkState)
            
            # --------------------  VIRTUAL ROBOT CONNECTION ------------------#
            self.ROBOT_ID = ROBOT_ID
            self.ROBOT_MODEL = ROBOT_MODEL
            self.velx=[50, 50]
            self.accx=[100, 100]
            self.model_state = rospy.Subscriber('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, self.msgRobotState_cb )

            # --------------------  TRANSFORMATION MATRICES ------------------#
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

            print("Initialized MyRLEnvironmentNode!")

        def init_realsense_model(self, orientation_camera, position_camera):
            """
            Initialization of the camera intrisic , extrinsic  parameters.
            """
            orientation_camera_matrix  = list(self.quaternion_to_rotation_matrix(orientation_camera.as_quat()))
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
            self.position_camera = [-0.017,0.513, 0.489]
            camera_rotation_matrix = self.quaternion_to_rotation_matrix(self.orientation_camera.as_quat())   

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

            tcp_rotation =  self.quaternion_to_rotation_matrix(R.from_euler('xyz', [0, 0, -140.948], degrees=True).as_quat())

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
            tcp_rotation =  self.quaternion_to_rotation_matrix(R.from_euler('XYZ', [ 180 , 0, -135], degrees=True).as_quat())

            # ---- Transformation matrix definition ---- #
            upper_matrix = np.concatenate((tcp_rotation, tcp_translation.T), axis=1)
            lower_matrix = np.array([[0,0,0,1]])
            transformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)

            return transformation_matrix
		
        def image_callback(self, image_msg):
			# -------------------- Read image------------------#
			try:
				self.cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")
				#print("Image received")
			except CvBridgeError as e:
				rospy.logerr(e)
				return
			image_height, image_width, _ = self.cv_image.shape

        def msgRobotState_cb(self, msg):
            """
            Callback to define the current TCP pose
            """
            self.current_TCP_pos = [msg.current_posx[0],msg.current_posx[1],msg.current_posx[2],msg.current_posx[3],msg.current_posx[4],msg.current_posx[5]]

        def quaternion_to_rotation_matrix(self, quaternion):
            """
            Convert a quaternion to a 3x3 rotation matrix.

            Args:
            quaternion (list or np.ndarray): A 4-element list or NumPy array representing a quaternion
                                            in the format [x, y, z, w], where w is the scalar part,
                                            and x, y, z are the vector parts.

            Returns:
            np.ndarray: A 3x3 rotation matrix.
            """
            x, y, z, w = quaternion
            rotation_matrix = np.array([
                [1 - 2*y*y - 2*z*z, 2*x*y - 2*w*z, 2*x*z + 2*w*y],
                [2*x*y + 2*w*z, 1 - 2*x*x - 2*z*z, 2*y*z - 2*w*x],
                [2*x*z - 2*w*y, 2*y*z + 2*w*x, 1 - 2*x*x - 2*y*y]
            ])
            return rotation_matrix
		
        def rotation_matrix_to_quaternion(self,rot_matrix,threshold=1e-6):
            """
            Convert a 3x3 rotation matrix to a quaternion.

            :param rot_matrix: 3x3 rotation matrix
            :return: Quaternion in the format [w, x, y, z]
            """
            # Check if the input matrix is close to a valid rotation matrix
            if not np.allclose(np.dot(rot_matrix.T, rot_matrix), np.eye(3), atol=1e-8):
                raise ValueError("Input matrix is not numerically close to a valid rotation matrix.")
            """
            Convert a 3x3 rotation matrix to a quaternion.

            :param rot_matrix: 3x3 rotation matrix
            :param threshold: Threshold below which matrix elements are set to zero
            :return: Quaternion in the format [w, x, y, z]
            """
            # Round matrix elements to four decimal places
            rot_matrix = np.round(rot_matrix, 4)

            # Set matrix elements below the threshold to zero
            rot_matrix[np.abs(rot_matrix) < threshold] = 0

            # Check the determinant of the matrix
            det = np.linalg.det(rot_matrix)
            if det < 0:
                # If the determinant is negative, it's a reflection, so adjust it
                rot_matrix[0, :] *= -1
            print(rot_matrix)
            w = np.sqrt(1 + rot_matrix[0, 0] + rot_matrix[1, 1] + rot_matrix[2, 2]) / 2
            x = (rot_matrix[2, 1] - rot_matrix[1, 2]) / (4 * w)
            y = (rot_matrix[0, 2] - rot_matrix[2, 0]) / (4 * w)
            z = (rot_matrix[1, 0] - rot_matrix[0, 1]) / (4 * w)

            return [w, x, y, z]


        def get_current_sole_pose(self):
			rospy.wait_for_service('/gazebo/get_link_state')
			# -------------------- Get current position of the sole------------------#
			self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
			self.sole_z = self.sole_coordinates.link_state.pose.position.z
			self.sole_y = self.sole_coordinates.link_state.pose.position.y
			self.sole_x = self.sole_coordinates.link_state.pose.position.x
			self.sole_ori_x = self.sole_coordinates.link_state.pose.orientation.x
			self.sole_ori_y = self.sole_coordinates.link_state.pose.orientation.y
			self.sole_ori_z = self.sole_coordinates.link_state.pose.orientation.z
			self.sole_ori_w = self.sole_coordinates.link_state.pose.orientation.w
			self.sole_position = [self.sole_x,self.sole_y,self.sole_z]
			self.sole_orientation = [self.sole_ori_x,self.sole_ori_y,self.sole_ori_z,self.sole_ori_w]

			return self.sole_position , self.sole_orientation

        def set_new_sole_position(self):
            # -------------------- Set new position of the sole------------------#
            state = LinkState()
            state.link_name = "sole::sole_link"
            state.reference_frame = 'world'  

            # New sole position 
            random_soles_position_x = random.uniform( -0.15, 0.10) 
            random_soles_position_y = random.uniform( 0.4, 0.5) 
            random_soles_position_z = random.uniform(0.01, 0.01)

            # New sole orientation	
            random_angle = random.uniform(0, 6.28)
            my_quaternion =  R.from_euler('xyz',[0,0,random_angle]).as_quat()

            # pose
            state.pose.position.x = random_soles_position_x
            state.pose.position.y = random_soles_position_y
            state.pose.position.z = random_soles_position_z
            state.pose.orientation.x = my_quaternion[0]
            state.pose.orientation.y = my_quaternion[1]
            state.pose.orientation.z = my_quaternion[2]
            state.pose.orientation.w = my_quaternion[3]
            
            # twist
            state.twist.linear.x = 0
            state.twist.linear.y = 0
            state.twist.linear.z = 0
            state.twist.angular.x = 0
            state.twist.angular.y = 0
            state.twist.angular.z = 0
            print(' NEW SOLE POSE:')
            print(state.pose)
            rospy.wait_for_service('/gazebo/set_link_state')
            time.sleep(3.0)
            try:
                set_state = self.set_model_coordinates
                result = set_state(state)
                assert result.success is True
            except rospy.ServiceException:
                print("/gazebo/set_link_state service call failed") 

        def reset_robot_pose(self):
            """
            Resets the Robot pose to HOME position: q0
            """ 
            q0 = posj(0,0,0,0,0,0)
            movej(q0, vel=60, acc=30)

        def define_T_sole(self, sole_position, sole_orientation, mm):
            '''
            Transformation matrix from global to sole reference frame
            '''
            # ---- Transformation matrix definition ---- #
            position_mm = np.multiply(np.expand_dims(np.asarray(sole_position),axis=0),np.array([[1000,1000,1000]], np.float32))
            position_m = np.expand_dims(np.asarray(sole_position),axis=0)
            rotation_matrix = self.quaternion_to_rotation_matrix(sole_orientation)
            upper_matrix_mm = np.concatenate((rotation_matrix, position_mm.T), axis=1)
            upper_matrix_m = np.concatenate((rotation_matrix, position_m.T), axis=1)
            lower_matrix = np.array([[0,0,0,1]])
            if mm == True:
                return np.concatenate((upper_matrix_mm, lower_matrix), axis=0)
            if mm == False:
                return np.concatenate((upper_matrix_m, lower_matrix), axis=0)

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

        def define_global_TCP_poses_trajectory(self, mm):
            '''
            Define position and orientation of the Tool in the global ref. frame
            '''
            n_points = self.T_burr_mm.shape[0]
            
            global_TCP_poses = np.empty(self.T_burr_mm.shape)
            if mm == True: 
                for i in range(n_points):
                    global_TCP_poses[i,:,:] = np.dot(self.T_sole_mm, np.dot(self.T_burr_mm[i,:,:] , self.T_prime))

            if mm == False: 
                for i in range(n_points):
                    global_TCP_poses[i,:,:] = np.dot(self.T_sole_m, np.dot(self.T_burr_m[i,:,:] , self.T_prime))

            return global_TCP_poses

        def define_global_Tool_poses_trajectory(self, mm):
            '''
            Define position and orientation of the TCP in the global ref. frame
            '''
            n_points = self.T_burr_mm.shape[0]
            
            global_Tool_poses = np.empty(self.T_burr_mm.shape)
            if mm == True: 
                for i in range(n_points):
                    global_Tool_poses[i,:,:] = np.dot(self.T_sole_mm, np.dot(self.T_burr_mm[i,:,:], np.dot(self.T_prime, self.T_tcp_tool_mm)))

            if mm == False: 
                for i in range(n_points):
                    global_Tool_poses[i,:,:] = np.dot(self.T_sole_m, np.dot(self.T_burr_m[i,:,:], np.dot(self.T_prime, self.T_tcp_tool_m)))

            return global_Tool_poses
        
        def project_to_image(self):
            '''
            Project from camera ref. frame to pixel space
            '''
            n_points = self.global_TCP_poses_trajectory_m.shape[0]
            image_dec = np.zeros((self._intrinsics.height, self._intrinsics.width, 3), dtype='uint8') 

            for point in range(n_points):
                traj_camera_frame = np.dot(np.linalg.inv(self.T_cam_mm) , self.global_TCP_poses_trajectory_mm[point,:,:])
                x, y, z = traj_camera_frame[0:3,-1][0], traj_camera_frame[0:3,-1][1], traj_camera_frame[0:3,-1][2]
                [u,v] = tf.rs2_project_point_to_pixel(self._intrinsics, [x, y, z])      
                if (u >= 0 and v >= 0) and (u < self._intrinsics.width and v < self._intrinsics.height):
                    cv2.circle(self.cv_image, (int(u),int(v)), radius=2, color=(0, 0, 255), thickness=-1)
                    image_dec[int(v),int(u),:] = np.array([255,255,255])    
            return self.cv_image, image_dec

        def reset_evironment(self):
            """
            Resets the environment: New sole random position and orientation and robot in HOME pose
            """ 
            # -------------------- RESET SOLE POSITION ------------------#
            self.set_new_sole_position() 
            # -------------------- GET SOLE POSITION ------------------#
            rospy.wait_for_service('/gazebo/get_link_state')
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_position, self.sole_orientation = self.get_current_sole_pose()
            
            # -------------------- RESET ROBOT POSE ------------------#
            self.reset_robot_pose()

            # -------- Burr position and orientation with respect to sole reference frame annotation path--------- #
            self.local_coord_path = '/root/catkin_ws/src/RL_environment/scripts/dataset_config/suola_%s.txt' % (self.sole_n) 
            
            # ---- T_sole : Transformation matrix from global reference frame to sole reference frame ---- #
            self.T_sole_m  = self.define_T_sole(self.sole_position, self.sole_orientation, mm = False)
            self.T_sole_mm = self.define_T_sole(self.sole_position, self.sole_orientation, mm = True)

            # ----  T_burr: Burr pose with respect to sole frame ---- #
            self.T_burr_m = self.define_T_burr(self.local_coord_path, mm = False)
            self.T_burr_mm = self.define_T_burr(self.local_coord_path, mm = True)            
                     
            # ---- Global_TCP_poses_trajectory ---- #
            self.global_TCP_poses_trajectory_mm = self.define_global_TCP_poses_trajectory(mm=True)
            self.global_TCP_poses_trajectory_m = self.define_global_TCP_poses_trajectory(mm=False)

            # ---- Global_Tool_poses_trajectory ---- #
            self.global_Tool_poses_trajectory_mm = self.define_global_Tool_poses_trajectory(mm =True)
            self.global_Tool_poses_trajectory_m = self.define_global_Tool_poses_trajectory(mm =False)
            
        def action_step_generate_position(self):
            """
            Generate random TCP pose (position and orientation)
            """               
            x = random.uniform( -200, 120)   
            y = random.uniform(360, 510)	 
            z = random.uniform(10, 10)  

            W = random.uniform(0, 0)	  # z-direction rotation of reference coordinate system
            P = random.uniform(180, 180)	  # y-direction rotation of w rotated coordinate system
            R = random.uniform(0, 90)      # z-direction rotation of of w and p rotated coordinate system

            return posx(x,y,z,W,P,R)

        def action_step_generate_trajectory(self, n_steps = 7):
            """
            Generate random TCP trajectory (sequaence of positions and orientations)
            """               
            traj = []
            for i in range(n_steps):
                traj.append(self.action_step_generate_position())
            print('Trajectory with %s steps generated' % (n_steps))
            return traj

        def action_step_perform_position_movejx(self, pos):
            """
            Reach a position of the trajectory with a movejx. Used to reach the first position of the deburring trajectory.             
            Args:
                pos: Robot TCP position to be reached
            """             
            success = movejx(pos, vel=60, acc=60, sol=2)
            print '\n\nInitial position reached'
            return success

        def action_step_perform_position_moveL(self, pos):
            """
            Reach a position of the trajectory with a movel. Used to execute the actual deburring trajectory.
            Args:
                pos: Robot TCP position to be reached
            """             
            success = movel(pos, self.velx, self.accx)
            return success

        def action_step_perform_trajectory(self, traj, coeff_reward = 1):
            """
            Execute action step: The robot performs the generated trajectory, the reward is computed and the state space is defined.
            Args:
                traj: Robot trajectory to be executed
                coeff_reward: alpha coefficient in the [Reward = reward_position + alpha * Reward_orietation] forumla
            """ 
            # ------ Real initial pose: Orientation as quaternion -----#
            initial_pose = traj[0]
            initial_position = initial_pose[0:3]
            initial_orientation = R.from_euler('zyz', initial_pose[3:]).as_quat()
            
            initial_orientation_PYQ = Quaternion([initial_orientation[-1], initial_orientation[0], initial_orientation[1], initial_orientation[2]])



            # ------ Ground-truth initial pose -----#
            initial_position_true = self.global_TCP_poses_trajectory_mm[0,0:3,-1]
                    
            initial_orientation_true_PYQ = Quaternion(matrix=self.global_TCP_poses_trajectory_mm[0,0:3,0:3]) # PYQUATERNION ASSUMES W,X,Y,Z
            initial_orientation_true = np.array([initial_orientation_true_PYQ.x,initial_orientation_true_PYQ.y,initial_orientation_true_PYQ.z,initial_orientation_true_PYQ.w])

            initial_pose_true = list(initial_position_true)+ list(R.from_quat(initial_orientation_true).as_euler('zyz',degrees=True))

            # -------------------- EXECUTE TRAJECTORY------------------#
            #success =  self.action_step_perform_position_movejx(initial_pose)
            success =  self.action_step_perform_position_movejx(posx(initial_pose_true))
            
            rospy.wait_for_message('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, timeout=5)

            print '\n\nStreamed initial position: ', initial_position 
            print 'Current TCP initial position:', self.current_TCP_pos[0:3] 

            print 'Streamed initial orientation: ', R.from_quat(initial_orientation).as_quat()
            print 'Current TCP initial orientation:', R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()

            # -------------------- COMPUTE REWARD ------------------#
            # -------------------- streamed pose ------------------#
            reward_initial_position_stream = self.calculate_reward_position(initial_position,  initial_position_true)
            reward_initial_orientation_stream = self.calculate_reward_orientation(initial_orientation_PYQ,  initial_orientation_true_PYQ)
            reward_stream = reward_initial_position_stream + coeff_reward * reward_initial_orientation_stream

            # -------------------- actual reached pose ------------------#
            reward_initial_position_actual = self.calculate_reward_position(self.current_TCP_pos[0:3],  initial_position_true)
            reward_initial_orientation_actual = self.calculate_reward_orientation(Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()),  initial_orientation_true_PYQ)
            reward_actual = reward_initial_position_actual + coeff_reward * reward_initial_orientation_actual


            print('Reward actual :', reward_actual, '   Reward stream :', reward_stream)
            # -------------------- DEFINE STATE SPACE ------------------#
            s  = self.define_state_space()
            print'\n\nState space :', s
            

            print '\n\nTrajectory started..'            
            for i,pose in enumerate(traj[1:]):
                # ------  Real pose: Orientation as quaternion -----#
                position = pose[0:3]
                orientation = R.from_euler('zyz', pose[3:]).as_quat()
                orientation_PYQ = Quaternion([orientation[-1], orientation[0], orientation[1], orientation[2]])

                #  ------ Ground-truth pose -----#
                position_true = self.global_TCP_poses_trajectory_mm[i,0:3,-1]
                orientation_true_PYQ = Quaternion(matrix=self.global_TCP_poses_trajectory_mm[i,0:3,0:3]) # PYQUATERNION ASSUMES W,X,Y,Z
                orientation_true =  np.array([orientation_true_PYQ.x,orientation_true_PYQ.y,orientation_true_PYQ.z,orientation_true_PYQ.w])
                pose_true = list(position_true)+ list(R.from_quat(orientation_true).as_euler('zyz',degrees=True))

                # -------------------- EXECUTE TRAJECTORY------------------#
                #success =  self.action_step_perform_position_moveL(pose)
                success =  self.action_step_perform_position_movejx(posx(pose_true))

                rospy.wait_for_message('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, timeout=5)
                print '\n\nStreamed  position: ', position
                print 'Current TCP  position:', self.current_TCP_pos[0:3] 

                print 'Streamed initial orientation: ', R.from_quat(orientation).as_quat()
                print 'Current TCP initial orientation:', R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()

                # -------------------- COMPUTE REWARD ------------------#

                # -------------------- streamed pose ------------------#
                reward_position_stream = self.calculate_reward_position(position,  initial_position_true)
                reward_orientation_stream = self.calculate_reward_orientation(orientation_PYQ,  orientation_true_PYQ)
                reward_stream = reward_stream + reward_position_stream + coeff_reward * reward_orientation_stream

                # -------------------- actual reached pose ------------------#
                reward_position_actual = self.calculate_reward_position(self.current_TCP_pos[0:3],  initial_position_true)
                reward_orientation_actual = self.calculate_reward_orientation(Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()),  orientation_true_PYQ)
                reward_actual = reward_actual + reward_position_actual + coeff_reward * reward_orientation_actual

                print('Reward actual :', reward_actual, '   Reward stream :', reward_stream)

                # -------------------- DEFINE STATE SPACE ------------------#
                s  = self.define_state_space()
                print'\n\nState space :', s
            
            print '\n\nTrajectory executed.. ' 
            print('FINAL Reward actual :', reward_actual, '   FINAL Reward stream :', reward_stream)

        def calculate_reward_position(self, point1, point2):
            """
            Calcualte position related reward: EUCLIDEAN DISTANCE BETWEEN 2 CARTESIAN POINTS (point1, point2)
            """          
            reward = np.linalg.norm(point1  - point2)
            return reward

        def calculate_reward_orientation(self, q0,  q1 ):
            """
            Calcualte position related reward: EUCLIDEAN DISTANCE BETWEEN 2 CARTESIAN POINTS (q0, q1)
            """            
            reward = Quaternion.absolute_distance(q0, q1)
            return reward   

        def define_state_space(self):
            """
            State space vector definition.
            Returns:
                [TCP x coordinate, TCP y coordinate, TCP z coordinate, TCP Z rotation (Euler ZYZ), TCP Y rotation (Euler ZYZ), TCP Z rotation (Euler ZYZ),
                SOLE x coordinate, SOLE Y coordinate, SOLE Z coordinate, SOLE x quaternion, SOLE y quaternion, SOLE z quaternion, SOLE w quaternion,
                sole model number]
            """   
            self.model_state = rospy.Subscriber('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, self.msgRobotState_cb )
            self.get_current_sole_pose()
            rospy.wait_for_message('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, timeout=5)
            s = np.array([self.current_TCP_pos[0], self.current_TCP_pos[1], self.current_TCP_pos[2], self.current_TCP_pos[3], self.current_TCP_pos[4], self.current_TCP_pos[5],
                            self.sole_position[0], self.sole_position[1], self.sole_position[2], self.sole_orientation[0], self.sole_orientation[1], self.sole_orientation[2], self.sole_orientation[3],
                            self.sole_n])
            return s