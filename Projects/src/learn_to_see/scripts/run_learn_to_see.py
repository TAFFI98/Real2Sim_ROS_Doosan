#!/usr/bin/env python

import os
import time
from learn_to_see import LearnToSeeNode
import rospy
import json
from sensor_msgs.msg import Image


def main(folder_dataset, sole_name):
	# -------------------- Initialize node ------------------#
	rospy.init_node('LearnToSee_node', anonymous=True)
	learn_to_see_node = LearnToSeeNode()
	while not rospy.is_shutdown():
		
		# -------------------- Define the number of different images in the dataset (different pose of the sole) ------------------#
		num_episodes_init = 0	
		num_episodes_end = 4
		
		# -------------------- Start episodes ------------------#
		print("Starting episodes...")
		for episode in range (num_episodes_init,num_episodes_end):		

			# -------------------- Move sole to new position and orientation  ------------------#
			learn_to_see_node.set_new_sole_position() 
			time.sleep(1.0)
			
			# -------------------- Get the new position and orientation of the sole ------------------#
			new_sole_pos, new_sole_ori = learn_to_see_node.get_current_sole_pose() 	
			
			# -------------------- Save position and orientation of the sole in txt file ------------------#
			print("Saving Pose in json file...")
			dict = {'position': new_sole_pos, 'orientation': new_sole_ori }
			filename = folder_dataset + 'img'
			file = open(filename + '_%s_%s.json'% (sole_name, episode), 'w')
			json.dump(dict, file)
			file.close()
			print("Pose saved!")
			# -------------------- Save image ------------------# 
			rospy.wait_for_message('/camera/color/image_raw', Image, timeout=5)

			learn_to_see_node.image_saving(filename + '_%s_%s.png'% (sole_name, episode))
			time.sleep(1.0)
			print ('Episode %s Ended'% (episode+1))
		
		# -------------------- End of episodes ------------------#
		rospy.signal_shutdown("EPISODES ENDED")
	
	print ("Total num of episodes completed, Exiting ....")


if __name__ == '__main__':
	# Define folder for dataset storage
	folder_dataset = '/root/catkin_ws/dataset_learn_to_see/'
	sole_name = 'sole_20'

	main(folder_dataset, sole_name)



