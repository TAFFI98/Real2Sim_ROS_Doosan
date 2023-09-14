#!/usr/bin/env python

import os
import time
from learn_to_see import LearnToSeeNode
import rospy
import pickle


def main(folder_dataset, sole_name):
	# Initialize ROS camera_node
	rospy.init_node('LearnToSee_node', anonymous=True)
	learn_to_see_node = LearnToSeeNode()
	while not rospy.is_shutdown():
		
		# Define the number of different images in the dataset (different pose of the sole)
		num_episodes_init = 0	
		num_episodes_end = 4
		
		# Evaluate the initial pose of the sole
		_, initial_sole_ori = learn_to_see_node.get_current_sole_pose() # Move sole and save new position
		print("Starting episodes...")
		for episode in range (num_episodes_init,num_episodes_end):		
			time.sleep(1.0)

			filename = folder_dataset + 'img'
			learn_to_see_node.image_saving(filename + '_%s_%s.png'% (sole_name, episode-1))
			print ('Episode:%s'%(episode+1))

			# Move sole to new position and with different orientation
			learn_to_see_node.set_new_sole_position(initial_ori = initial_sole_ori) 
			time.sleep(1.0)
			
			# Evaluate the new orientation and position of the sole
			new_sole_pos, new_sole_ori = learn_to_see_node.get_current_sole_pose() 	
			
			# Save position in txt file
			print("Saving Pose in txt file...")
			dict = {'position': new_sole_pos, 'orientation': new_sole_ori }
			filename = folder_dataset + 'img'
			file = open(filename + '_%s_%s.txt'% (sole_name, episode), 'wb') 
			pickle.dump(dict, file)
			file.close()
			print("Pose saved!")
			
			# Save image 
			learn_to_see_node.image_saving(filename + '_%s_%s.png'% (sole_name, episode-1))
			time.sleep(1.0)
			print ('Episode %s Ended'% (episode+1))
		os.remove(filename + '_%s_-1.png'% (sole_name))
		os.remove(filename + '_%s_%s.txt'% (sole_name, num_episodes_end-1))
		rospy.signal_shutdown("EPISODES ENDED")
		


	print ("Total num of episode completed, Exiting ....")
if __name__ == '__main__':
	# Define folder for dataset storage
	folder_dataset = '/root/catkin_ws/dataset_learn_to_see/'
	sole_name = 'sole_10'

	main(folder_dataset, sole_name)



