#!/usr/bin/env python
from pyquaternion import Quaternion
import cv2
import numpy as np
import rospy
import time
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from geometry_msgs.msg import PoseStamped
from gazebo_msgs.srv import GetLinkState ,SetLinkState
import random
from gazebo_msgs.msg import ModelState, LinkState


class LearnToSeeNode(): 
		def __init__ (self):
			print ("Initializing LearnToSeeNode Node.....")
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
			
			# -------------------- Client to reset the  sole position ------------------#
			self.set_model_coordinates = rospy.ServiceProxy('/gazebo/set_link_state', SetLinkState)			
			
			
			print('Initialized LearnToSeeNode Node')
		
		def image_callback(self, image_msg):
			# -------------------- Read image------------------#
			try:
				self.cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")
				print("Image received")
			except CvBridgeError as e:
				rospy.logerr(e)
				return
			image_height, image_width, _ = self.cv_image.shape

		def image_show(self):
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

				# new sole position 
				random_soles_position_x = random.uniform( -0.27, 0.24) 
				random_soles_position_y = random.uniform( 0.38, 0.53) 
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



