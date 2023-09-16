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
sys.dont_write_bytecode = True
sys.path.append( os.path.abspath(os.path.join("/root/catkin_ws/src/doosan-robot/common/imp")) ) # get import path : DSR_ROBOT.py 
from DSR_ROBOT import *

from cv_bridge import CvBridge, CvBridgeError
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Image

from gazebo_msgs.srv import GetLinkState ,SetLinkState
from gazebo_msgs.msg import ModelState, LinkState


class MyRLEnvironmentNode(): 
        def __init__ (self, ROBOT_ID, ROBOT_MODEL):
            print("Initializing MyRLEnvironmentNode Node.....")
            self.bridge = CvBridge()	

            # -------------------- Image subscriber ------------------#
            self.suscriber_image = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
            
            # -------------------- Client to get the sole position ------------------#
            self.model_coordinates = rospy.ServiceProxy('/gazebo/get_link_state', GetLinkState)			
            self.sole_coordinates = self.model_coordinates( "sole::sole_link" , "world" )
            self.sole_z = self.sole_coordinates.link_state.pose.position.z
            self.sole_y = self.sole_coordinates.link_state.pose.position.y
            self.sole_x = self.sole_coordinates.link_state.pose.position.x
            self.sole_ori_x = self.sole_coordinates.link_state.pose.orientation.x
            self.sole_ori_y = self.sole_coordinates.link_state.pose.orientation.y
            self.sole_ori_z = self.sole_coordinates.link_state.pose.orientation.z
            self.sole_ori_w = self.sole_coordinates.link_state.pose.orientation.w
            
            # -------------------- Client to reset the sole position ------------------#
            self.set_model_coordinates = rospy.ServiceProxy('/gazebo/set_link_state', SetLinkState)			
            
            # --------------------  ROBOT interface ------------------#
            self.ROBOT_ID = ROBOT_ID
            self.ROBOT_MODEL = ROBOT_MODEL
            self.velx=[50, 50]
            self.accx=[100, 100]
            print("Initialized MyRLEnvironmentNode Node")
        
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
            # -------------------- EXECUTE TRAJECTORY------------------#
            initial_pos = traj[0]
            success =  self.action_step_perform_position_movejx(initial_pos)
            
            print('Trajectory started..')
            for pos in traj[1:]:
                success =  self.action_step_perform_position_moveL(pos)
            
            print('Trajectory executed.. ')

        def  action_step_perform_position_movejx(self, pos):
            # -------------------- EXECUTE MOVEJX------------------#
            success = movejx(pos, vel=60, acc=60, sol=2)
            print('Initial position reached')

        def  action_step_perform_position_moveL(self, pos):
            # -------------------- EXECUTE MOVEL------------------#
            success = movel(pos, self.velx, self.accx)

        def action_step_generate_position(self):
            # -------------------- POSITION GENERATION------------------#
            x = random.uniform( -200, 120)   
            y = random.uniform(360, 510)	 
            z = random.uniform(10, 10)  
            W = random.uniform(0, 360)	  # z-direction rotation of reference coordinate system
            P = random.uniform(90, 270)	  # y-direction rotation of w rotated coordinate system
            R = random.uniform(0, 0)    # z-direction rotation of of w and p rotated coordinate system
            
            return posx(x,y,z,W,P,R)

        def  action_step_generate_trajectory(self):
            # -------------------- TRAJECTORY GENERATION------------------#
            x1 = self.action_step_generate_position()   
            x2 = self.action_step_generate_position()	 
            x3 = self.action_step_generate_position() 
            x4 = self.action_step_generate_position()	 
            x5 = self.action_step_generate_position()	 
            x6 = self.action_step_generate_position()  
            x7 = self.action_step_generate_position()  
            print('Trajectory generated')
            return [x1, x2, x3, x4, x5, x6, x7]

        def  calculate_reward(self):
            # sole_pos, sole_ori = self.get_current_sole_pose() 	
            # EE_pose = self.current_EE_pos
            pass
        def  define_state_space(self):
            pass