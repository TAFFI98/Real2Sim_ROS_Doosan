#!/usr/bin/env python
from pyquaternion import Quaternion
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

from cv_bridge import CvBridge, CvBridgeError
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Image

from gazebo_msgs.srv import GetLinkState ,SetLinkState
from gazebo_msgs.msg import ModelState, LinkState

from scipy.spatial.transform import Rotation as R
import tf.transformations as tr

class MyRLEnvironmentNode(): 
        def __init__ (self, ROBOT_ID, ROBOT_MODEL, sole_number):
            print("Initializing MyRLEnvironmentNode Node.....")
            self.bridge = CvBridge()	

            # -------------------- Image subscriber ------------------#
            self.suscriber_image = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
            
            # -------------------- Client to get the sole position ------------------#
            self.model_coordinates = rospy.ServiceProxy('/gazebo/get_link_state', GetLinkState)			
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_position = self.sole_coordinates.link_state.pose.position
            self.sole_orientation = self.sole_coordinates.link_state.pose.orientation
            
            # -------------------- Client to reset the sole position ------------------#
            self.set_model_coordinates = rospy.ServiceProxy('/gazebo/set_link_state', SetLinkState)			
            
            # --------------------  ROBOT interface ------------------#
            self.ROBOT_ID = ROBOT_ID
            self.ROBOT_MODEL = ROBOT_MODEL
            self.velx=[50, 50]
            self.accx=[100, 100]
            
            # --------------------  Ground truth burr position and tool orientation ------------------#
            # -------- Burr position and orintation with respect to sole reference frame --------- #
            self.local_coord_path = '/root/catkin_ws/src/RL_environment/scripts/dataset_config/suola_%s.txt' % (sole_number) 
            self.local_traj, self.R_tool= self.define_local_position_traj(self.local_coord_path)
            # -------- Burr position and orintation with respect to global reference frame --------- #
            self.transformation_matrix_global_local = self.define_tansformation_matrix_global_to_sole_frame(self.sole_position, self.sole_orientation)
            self.global_traj =  self.define_global_position_traj(self.transformation_matrix_global_local, self.local_traj)
            self.global_R_tool_quat =  self.define_global_orientation_traj(self.transformation_matrix_global_local, self.R_tool)



            print("Initialized MyRLEnvironmentNode Node")
        def rotation_matrix_to_quaternion(self, R):
            """
            Convert a 3x3 rotation matrix to a unit quaternion.

            Args:
                R (np.ndarray): The 3x3 rotation matrix.

            Returns:
                np.ndarray: The unit quaternion [w, x, y, z].
            """
            # Ensure the input matrix is a valid rotation matrix (orthogonal with determinant 1)
            if not np.allclose(np.dot(R.T, R), np.eye(3)) or not np.isclose(np.linalg.det(R), 1.0):
                raise ValueError("Input matrix is not a valid rotation matrix.")

            # Extract the components of the rotation matrix
            r11, r12, r13 = R[0]
            r21, r22, r23 = R[1]
            r31, r32, r33 = R[2]

            # Calculate the quaternion components
            w = 0.5 * np.sqrt(1 + r11 + r22 + r33)
            x = (r32 - r23) / (4 * w)
            y = (r13 - r31) / (4 * w)
            z = (r21 - r12) / (4 * w)

            return np.array([w, x, y, z])     

        def define_global_orientation_traj(self, transformation_matrix, R_tool):


                #--------- Burr points in global reference frame -------- #
                global_R_tool_quat = np.empty((R_tool.shape[0], 4))
                for i in range(R_tool.shape[0]):
                    matrix = np.matmul(transformation_matrix[:3,:3],R_tool[i,:,:])
                    global_R_tool_quat[i,:] = self.rotation_matrix_to_quaternion(matrix)

                return global_R_tool_quat 

        def define_global_position_traj(self, transformation_matrix, local_traj):
                #--------- Burr points in global reference frame -------- #
                global_traj = np.empty((local_traj.shape[0], 4))
                for i in range(local_traj.shape[0]):
                    global_traj[i,:]= np.matmul(transformation_matrix,local_traj[i,:])
                return global_traj 

        def define_tansformation_matrix_global_to_sole_frame(self, sole_position, sole_orientation ):
            position = np.multiply(np.expand_dims(np.asarray([sole_position.x,sole_position.y,sole_position.z]),axis=0),np.array([[1000,1000,1000]], np.float32))
            orientation = np.asarray([sole_orientation.x,sole_orientation.y,sole_orientation.z,sole_orientation.w])
            orientation = Quaternion(orientation[0], orientation[1], orientation[2], orientation[3])
            rotation_matrix = orientation.rotation_matrix
            upper_matrix = np.concatenate((rotation_matrix, position.T), axis=1)
            lower_matrix = np.array([[0,0,0,1]])
            transformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)
            
            return transformation_matrix

        def is_rotation_matrix(self,matrix):
            # Check if the matrix is square
            if matrix.shape != (3, 3):
                return False
            
            # Check orthogonality
            is_orthogonal = np.allclose(np.dot(matrix.T, matrix), np.identity(3))
            
            # Check determinant
            det = np.linalg.det(matrix)
            is_proper_rotation = np.isclose(det, 1.0)
            
            # Check transpose inverse
            is_transpose_inverse = np.allclose(np.dot(matrix.T, matrix), np.identity(3))
            
            return is_orthogonal and is_proper_rotation and is_transpose_inverse

        def define_local_position_traj(self, local_coord_path):
            #--------- Burr points in sole reference frame -------- #
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

            # ----Tool orientation in reference frame centered in the burr (t-n-z)---#
            d1 = R.from_euler('xzy', [-180,-135, -45],degrees=True).as_quat()
            d1 = Quaternion(d1[0], d1[1], d1[2], d1[3]).rotation_matrix

            # ----Tool orientation in reference frame in the center of the sole ---#
            R_tool = np.empty((n_points,3,3)) 
            for i in range(n_points):
                R_tool[i,:,:]  = np.matmul(d1,rotation_matrix_O_O1[i,:,:])
            return local_traj, R_tool


        def thread_subscriber(self):
            self.model_state = rospy.Subscriber('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, self.msgRobotState_cb )
            rospy.spin()
        
        def msgRobotState_cb(self,msg):
            self.current_EE_pos = [msg.current_posx[0],msg.current_posx[1],msg.current_posx[2],msg.current_posx[3],msg.current_posx[4],msg.current_posx[5]]

        def image_callback(self, image_msg):
            # -------------------- Read image------------------#
            try:
                self.cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")
                #print("Image received")
            except CvBridgeError as e:
                rospy.logerr(e)
                return
            image_height, image_width, _ = self.cv_image.shape
		
        def image_show(self):
			# -------------------- Show image------------------#
			cv2.namedWindow('Camera Image')
			cv2.imshow("Camera Image",self.cv_image)
			cv2.waitKey(1)

        def image_saving(self, filename):
            # -------------------- Save image------------------#
            print("Saving image...")
            cv2.imwrite(filename , self.cv_image)
            print("Image saved!")

        def get_current_sole_pose(self):
            # -------------------- Get current position of the sole------------------#
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_z = self.sole_coordinates.link_state.pose.position.z
            self.sole_y = self.sole_coordinates.link_state.pose.position.y
            self.sole_x = self.sole_coordinates.link_state.pose.position.x
            self.sole_ori_x = self.sole_coordinates.link_state.pose.orientation.x
            self.sole_ori_y = self.sole_coordinates.link_state.pose.orientation.y
            self.sole_ori_z = self.sole_coordinates.link_state.pose.orientation.z
            self.sole_ori_w = self.sole_coordinates.link_state.pose.orientation.w
            pos = [self.sole_x,self.sole_y,self.sole_z]
            ori = [self.sole_ori_x,self.sole_ori_y,self.sole_ori_z,self.sole_ori_w]

            return pos, ori			
	

        def set_new_sole_position(self, initial_ori):
            # -------------------- Set new position of the sole------------------#
                state = LinkState()
                state.link_name = "sole::sole_link"
                state.reference_frame = 'world'  

                # New sole position 
                random_soles_position_x = random.uniform( -0.20, 0.12) 
                random_soles_position_y = random.uniform( 0.36, 0.51) 
                random_soles_position_z = random.uniform(0.01, 0.01)

                # New sole orientation	
                initial_quaternion  = Quaternion(initial_ori[0], initial_ori[1], initial_ori[2], initial_ori[3])
                random_angle = random.uniform(0, 6.28)
                rotation_quaternion = Quaternion(axis=[1, 0,0], angle=random_angle)
                rotation2_quaternion = Quaternion(axis=[0, 0,1], angle= 3.14)
                my_quaternion = initial_quaternion.rotate(rotation_quaternion)
                my_quaternion = my_quaternion.rotate(rotation2_quaternion)

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

                rospy.wait_for_service('/gazebo/set_link_state')
                time.sleep(3.0)
                try:
                    set_state = self.set_model_coordinates
                    result = set_state(state)
                    assert result.success is True
                except rospy.ServiceException:
                    print("/gazebo/set_link_state service call failed")
        
        def reset_evironment(self, initial_sole_ori):
            # -------------------- RESET SOLE POSITION ------------------#
            self.set_new_sole_position(initial_ori = initial_sole_ori) 
            # -------------------- RESET ROBOT POSe ------------------#
            self.reset_robot_pose()

        def reset_robot_pose(self):
            q0 = posj(0,0,0,0,0,0)
            movej(q0, vel=60, acc=30)

        def  action_step_perform_trajectory(self,traj):
            
            # ------ Real initial pose: Orientation as quaternion -----#
            initial_pose = traj[0]
            initial_position = initial_pose[0:3]
            initial_orientation = Quaternion(R.from_euler('zyz', initial_pose[3:]).as_quat())

            # ------ Ground-truth initial pose -----#
            initial_position_true = self.global_traj[0][0:3]
            initial_orientation_true = Quaternion(self.global_R_tool_quat[0])

            # -------------------- EXECUTE TRAJECTORY------------------#
            success =  self.action_step_perform_position_movejx(initial_pose)

            # -------------------- COMPUTE REWARD ------------------#
            reward_initial_position = self.calculate_reward_position(initial_position,  initial_position_true)
            reward_initial_orientation = self.calculate_reward_orientation(initial_orientation,  initial_orientation_true)
            reward = reward_initial_position + reward_initial_orientation
            print('Reward:', reward)
            

            print('Trajectory started..')            
            for i,pose in enumerate(traj[1:]):
                # ------  Real pose: Orientation as quaternion -----#
                position = pose[0:3]
                orientation = Quaternion(R.from_euler('zyz', pose[3:]).as_quat())

                #  ------ Ground-truth pose -----#
                position_true = self.global_traj[i][0:3]
                orientation_true = Quaternion(self.global_R_tool_quat[i])

                # -------------------- EXECUTE TRAJECTORY------------------#
                success =  self.action_step_perform_position_moveL(pose)
                
                # -------------------- COMPUTE REWARD ------------------#
                reward_position = self.calculate_reward_position(position,  initial_position_true)
                reward_orientation = self.calculate_reward_orientation(orientation,  orientation_true)
                reward = reward + reward_position + reward_orientation
                print('Reward:', reward)



            print('Trajectory executed.. ')
            print('Final Reward:', reward)
            
        def  action_step_perform_position_movejx(self, pos):
            # -------------------- EXECUTE MOVEJX------------------#
            success = movejx(pos, vel=60, acc=60, sol=2)
            print('Initial position reached')

        def  action_step_perform_position_moveL(self, pos):
            # -------------------- EXECUTE MOVEL------------------#
            success = movel(pos, self.velx, self.accx)

        def action_step_generate_position(self):
            # -------------------- TCP POSE GENERATION------------------#
            x = random.uniform( -200, 120)   
            y = random.uniform(360, 510)	 
            z = random.uniform(10, 10)  
            W = random.uniform(0, 360)	  # z-direction rotation of reference coordinate system
            P = random.uniform(90, 270)	  # y-direction rotation of w rotated coordinate system
            R = random.uniform(0, 0)      # z-direction rotation of of w and p rotated coordinate system
            
            return posx(x,y,z,W,P,R)

        def  action_step_generate_trajectory(self, n_steps = 7):
            # -------------------- TRAJECTORY GENERATION------------------#
            traj = []
            for i in range(n_steps):
                traj.append(self.action_step_generate_position())
            print('Trajectory with %s steps generated' % (n_steps))
            return traj

        def calculate_reward_position(self, point1, point2):
            # -------------------- EUCLIDEAN DISTANCE BETWEEN 2 CARTESIAN POINTS------------------#           
            reward = np.linalg.norm(point1  - point2)
            return reward

        def calculate_reward_orientation(self, q0,  q1 ):
            # -------------------- QUATERNION DISTANCE BETWEEN 2 ORIENTATIONS------------------#           
            reward = Quaternion.absolute_distance(q0, q1)
            return reward        


        def  define_state_space(self):
            pass