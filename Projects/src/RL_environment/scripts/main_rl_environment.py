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

from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Image

from gazebo_msgs.srv import GetLinkState ,SetLinkState
from gazebo_msgs.msg import ModelState, LinkState

from scipy.spatial.transform import Rotation as R
import tf.transformations as tr

class MyRLEnvironmentNode(): 
    
        def __init__ (self, ROBOT_ID, ROBOT_MODEL, sole_number):
            print("Initializing MyRLEnvironmentNode Node.....")
            
            # -------------------- CLIENT TO GET THE SOLE POSITION IN GAZEBO ------------------#
            self.sole_n = sole_number
            self.model_coordinates = rospy.ServiceProxy('/gazebo/get_link_state', GetLinkState)			
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_position = self.sole_coordinates.link_state.pose.position
            self.sole_orientation = self.sole_coordinates.link_state.pose.orientation
            
            # -------------------- CLIENT TO RESET THE SOLE POSITION IN GAZEBO ------------------#
            self.set_model_coordinates = rospy.ServiceProxy('/gazebo/set_link_state', SetLinkState)			
            
            # --------------------  ROBOT  ------------------#
            self.ROBOT_ID = ROBOT_ID
            self.ROBOT_MODEL = ROBOT_MODEL
            self.velx=[50, 50]
            self.accx=[100, 100]
            self.model_state = rospy.Subscriber('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, self.msgRobotState_cb )

            
            # --------------------  GROUND TRUTH BURR POSITION AND TOOL ORIENTATION ------------------#
            # -------- Burr position and orientation with respect to sole reference frame --------- #
            self.local_coord_path = '/root/catkin_ws/src/RL_environment/scripts/dataset_config/suola_%s.txt' % (sole_number) 
            self.local_traj, self.R_tool= self.define_local_position_traj(self.local_coord_path)  # mm
            # -------- Burr position and orientation with respect to global reference frame --------- #
            self.transformation_matrix_global_local = self.define_tansformation_matrix_global_to_sole_frame(self.sole_position, self.sole_orientation) # mm
            self.global_traj =  self.define_global_position_traj(self.transformation_matrix_global_local, self.local_traj)
            self.global_R_tool_quat =  self.define_global_orientation_traj(self.transformation_matrix_global_local, self.R_tool)

            print("Initialized MyRLEnvironmentNode Node")
                
        def msgRobotState_cb(self, msg):
            """
            Callback to define the current TCP pose
            """
            self.current_TCP_pos = [msg.current_posx[0],msg.current_posx[1],msg.current_posx[2],msg.current_posx[3],msg.current_posx[4],msg.current_posx[5]]

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

        def define_global_orientation_traj(self, transformation_matrix, R_tool):
            """
            Define the ground truth tool orientation trajectory.

            Args:
                R_tool (np.ndarray): The 3x3 rotation matrix expressing the tool orientation in ref. frame in the center of the sole.
                transformation_matrix (np.ndarray): The transformation matrix expressing the rototranslation of the ref. 
                                                    frame in the center of the sole. w.r.t the ref. frame in the robot base.

            Returns:
                np.ndarray (n_points,3,3): Tool orientation trajecotry in the ref. frame in the robot base.
            """
            global_R_tool_quat = np.empty((R_tool.shape[0], 4))
            for i in range(R_tool.shape[0]):
                matrix = np.matmul(transformation_matrix[:3,:3],R_tool[i,:,:])
                global_R_tool_quat[i,:] = self.rotation_matrix_to_quaternion(matrix)

            return global_R_tool_quat 

        def define_global_position_traj(self, transformation_matrix, local_traj):
            """
            Define the ground truth tool position trajectory.

            Args:
                local_traj (np.ndarray): The vector expressing the burr position in ref. frame in the center of the sole.
                transformation_matrix (np.ndarray): The transformation matrix expressing the rototranslation of the ref. 
                                                    frame in the center of the sole. w.r.t the ref. frame in the robot base.

            Returns:
                np.ndarray : Tool position trajecotry in the ref. frame in the robot base.
            """           
            global_traj = np.empty((local_traj.shape[0], 4))
            for i in range(local_traj.shape[0]):
                global_traj[i,:]= np.matmul(transformation_matrix,local_traj[i,:])
            return global_traj 

        def define_tansformation_matrix_global_to_sole_frame(self, sole_position, sole_orientation ):
            """
            Define the transformation matrix expressing the rototranslation of the ref. frame in the center of the sole. w.r.t the ref. frame in the robot base.

            Args:
                sole_position (np.ndarray): Sole position
                sole_orientation (np.ndarray): Sole orientation (quaternion)
                                                    
            Returns:
                np.ndarray : Transformation_matrix.
            """ 

            position = np.multiply(np.expand_dims(np.asarray([sole_position.x,sole_position.y,sole_position.z]),axis=0),np.array([[1000,1000,1000]], np.float32))
            rotation_matrix = self.quaternion_to_rotation_matrix([sole_orientation.x,sole_orientation.y,sole_orientation.z,sole_orientation.w])
            upper_matrix = np.concatenate((rotation_matrix, position.T), axis=1)
            lower_matrix = np.array([[0,0,0,1]])
            transformation_matrix = np.concatenate((upper_matrix, lower_matrix), axis=0)
            
            return transformation_matrix

        def is_rotation_matrix(self,matrix):
            """
            Auxiliary function to check if the input matrix is a valid rotation matrix
            Args:
                    matrix (np.ndarray)
                                                        
            Returns:
                    Bool : True - False
            """ 

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
        
        def define_local_position_traj(self, local_coord_path):
            """
            Load annotated ground truth trajectory (burr position and tool orientation)

            Args:
                local_coord_path : Path to annotations
                                                    
            Returns:
                local_traj: The vector expressing the burr position trajectory in ref. frame in the center of the sole.
                R_tool:  The vector expressing the tool orientation trajectory in ref. frame in the center of the sole.
            """             

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
            #d1 = R.from_euler('xzy', [0,0, 0],degrees=True).as_quat()

            d1 = self.euler_to_rotation_matrix(0, 0, 0) # EULER XYZ in degrees

            # ----Tool orientation in reference frame in the center of the sole ---#
            R_tool = np.empty((n_points,3,3)) 
            for i in range(n_points):
                R_tool[i,:,:]  = np.matmul(d1,rotation_matrix_O_O1[i,:,:])
            return local_traj, R_tool

        def get_current_sole_pose(self):
            """
            Get current position of the sole in Gazebo
            Returns:
                pos : Position of the sole
                ori : Orientaion of the sole as quaternion
            """             
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
            """
            Set new random position and orientaiton of the sole in Gazebo
            """               
            state = LinkState()
            state.link_name = "sole::sole_link"
            state.reference_frame = 'world'  

            # New sole position 
            random_soles_position_x = random.uniform( -0.20, 0.12) 
            random_soles_position_y = random.uniform( 0.36, 0.51) 
            random_soles_position_z = random.uniform(0.01, 0.01)
            # random_soles_position_x = 0 
            # random_soles_position_y = 0.4
            # random_soles_position_z = 0.01
            # New sole orientation	
            random_angle = random.uniform(0, 6.28)
            my_quaternion =  R.from_euler('xyz',[0,0,random_angle]).as_quat()
            my_quaternion = Quaternion(my_quaternion[0], my_quaternion[1], my_quaternion[2], my_quaternion[3])
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

        def reset_evironment(self):
            """
            Resets the environment: New sole random position and orientation and robot in HOME pose
            """ 
            # -------------------- RESET SOLE POSITION ------------------#
            self.set_new_sole_position() 
            # -------------------- GET SOLE POSITION ------------------#
            rospy.wait_for_service('/gazebo/get_link_state')
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_position = self.sole_coordinates.link_state.pose.position
            self.sole_orientation = self.sole_coordinates.link_state.pose.orientation
            # -------------------- RESET ROBOT POSE ------------------#
            self.reset_robot_pose()
            # -------- Burr position and orientation with respect to sole reference frame --------- #
            self.local_coord_path = '/root/catkin_ws/src/RL_environment/scripts/dataset_config/suola_%s.txt' % (self.sole_n) 
            self.local_traj, self.R_tool= self.define_local_position_traj(self.local_coord_path)  # mm
            # -------- Burr position and orientation with respect to global reference frame --------- #
            self.transformation_matrix_global_local = self.define_tansformation_matrix_global_to_sole_frame(self.sole_position, self.sole_orientation) # mm
            self.global_traj =  self.define_global_position_traj(self.transformation_matrix_global_local, self.local_traj)
            self.global_R_tool_quat =  self.define_global_orientation_traj(self.transformation_matrix_global_local, self.R_tool)

        def reset_robot_pose(self):
            """
            Resets the Robot pose to HOME position: q0
            """ 
            q0 = posj(0,0,0,0,0,0)
            movej(q0, vel=60, acc=30)

        def action_step_perform_trajectory(self,traj, coeff_reward = 1):
            """
            Execute action step: The robot performs the generated trajectory, the reward is computed and the state space is defined.
            Args:
                traj: Robot trajectory to be executed
                coeff_reward: alpha coefficient in the [Reward = reward_position + alpha * Reward_orietation] forumla
            """ 
            # ------ Real initial pose: Orientation as quaternion -----#
            initial_pose = traj[0]
            initial_position = initial_pose[0:3]
            initial_orientation = Quaternion(R.from_euler('zyz', initial_pose[3:]).as_quat())

            # ------ Ground-truth initial pose -----#
            initial_position_true = self.global_traj[0][0:3]
            initial_orientation_true = Quaternion(self.global_R_tool_quat[0])
            initial_pose_true = list(self.global_traj[0][0:3])+ list(R.from_quat(self.global_R_tool_quat[0]).as_euler('zyz',degrees=True))

            # -------------------- EXECUTE TRAJECTORY------------------#
            #success =  self.action_step_perform_position_movejx(initial_pose)
            success =  self.action_step_perform_position_movejx(posx(initial_pose_true))
            rospy.wait_for_message('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, timeout=5)

            print '\n\nStreamed initial position: ', initial_position 
            print 'Current TCP initial position:', self.current_TCP_pos[0:3] 

            print 'Streamed initial orientation: ', Quaternion(R.from_euler('zyz', initial_pose[3:]).as_quat())
            print 'Current TCP initial orientation:', Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat())

            # -------------------- COMPUTE REWARD ------------------#
            # -------------------- streamed pose ------------------#
            reward_initial_position_stream = self.calculate_reward_position(initial_position,  initial_position_true)
            reward_initial_orientation_stream = self.calculate_reward_orientation(initial_orientation,  initial_orientation_true)
            reward_stream = reward_initial_position_stream + coeff_reward * reward_initial_orientation_stream

            # -------------------- actual reached pose ------------------#
            reward_initial_position_actual = self.calculate_reward_position(self.current_TCP_pos[0:3],  initial_position_true)
            reward_initial_orientation_actual = self.calculate_reward_orientation(Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()),  initial_orientation_true)
            reward_actual = reward_initial_position_actual + coeff_reward * reward_initial_orientation_actual


            print('Reward actual :', reward_actual, '   Reward stream :', reward_stream)
            # -------------------- DEFINE STATE SPACE ------------------#
            s  = self.define_state_space()

            

            print '\n\nTrajectory started..'            
            for i,pose in enumerate(traj[1:]):
                # ------  Real pose: Orientation as quaternion -----#
                position = pose[0:3]
                orientation = Quaternion(R.from_euler('zyz', pose[3:]).as_quat())

                #  ------ Ground-truth pose -----#
                position_true = self.global_traj[i][0:3]
                orientation_true = Quaternion(self.global_R_tool_quat[i])
                pose_true = list(self.global_traj[i][0:3])+ list(R.from_quat(self.global_R_tool_quat[i]).as_euler('zyz',degrees=True))

                # -------------------- EXECUTE TRAJECTORY------------------#
                #success =  self.action_step_perform_position_moveL(pose)
                success =  self.action_step_perform_position_movejx(posx(pose_true))

                rospy.wait_for_message('/'+self.ROBOT_ID +self.ROBOT_MODEL+'/state', RobotState, timeout=5)
                print '\n\nStreamed  position: ', initial_position 
                print 'Current TCP  position:', self.current_TCP_pos[0:3] 

                print 'Streamed orientation: ', Quaternion(R.from_euler('zyz', initial_pose[3:]).as_quat()) 
                print 'Current TCP orientation:', Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()) 

                # -------------------- COMPUTE REWARD ------------------#

                # -------------------- streamed pose ------------------#
                reward_position_stream = self.calculate_reward_position(position,  initial_position_true)
                reward_orientation_stream = self.calculate_reward_orientation(orientation,  orientation_true)
                reward_stream = reward_stream + reward_position_stream + coeff_reward * reward_orientation_stream

                # -------------------- actual reached pose ------------------#
                reward_position_actual = self.calculate_reward_position(self.current_TCP_pos[0:3],  initial_position_true)
                reward_orientation_actual = self.calculate_reward_orientation(Quaternion(R.from_euler('zyz', self.current_TCP_pos[3:]).as_quat()),  orientation_true)
                reward_actual = reward_actual + reward_position_actual + coeff_reward * reward_orientation_actual

                print('Reward actual :', reward_actual, '   Reward stream :', reward_stream)

                # -------------------- DEFINE STATE SPACE ------------------#
                s  = self.define_state_space()

            print '\n\nTrajectory executed.. ' 
            print('FINAL Reward actual :', reward_actual, '   FINAL Reward stream :', reward_stream)
            
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

        def action_step_generate_position(self):
            """
            Generate random TCP pose (position and orientation)
            """               
            x = random.uniform( -200, 120)   
            y = random.uniform(360, 510)	 
            z = random.uniform(10, 10)  

            W = random.uniform(84, 84)	  # z-direction rotation of reference coordinate system
            P = random.uniform(180, 180)	  # y-direction rotation of w rotated coordinate system
            R = random.uniform(84, 84)      # z-direction rotation of of w and p rotated coordinate system

            # W = random.uniform(0, 360)	  # z-direction rotation of reference coordinate system
            # P = random.uniform(90, 270)	  # y-direction rotation of w rotated coordinate system
            # R = random.uniform(-180, -180)      # z-direction rotation of of w and p rotated coordinate system
            
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
            try:
                s = np.array([self.current_TCP_pos[0], self.current_TCP_pos[1], self.current_TCP_pos[2], self.current_TCP_pos[3], self.current_TCP_pos[4], self.current_TCP_pos[5],
                            self.sole_position.x, self.sole_position.y, self.sole_position.z, self.sole_orientation.x, self.sole_orientation.y, self.sole_orientation.z, self.sole_orientation.w,
                            self.sole_n])
            except:
                self.get_logger().info('--------------------node not ready yet, getting values--------------------')
                return

            else:
                return s