#!/usr/bin/env python
import cv2
import rospy
import os
import threading, time
import sys
sys.dont_write_bytecode = True
sys.path.append( os.path.abspath(os.path.join("/root/catkin_ws/src/doosan-robot/common/imp")) ) # get import path : DSR_ROBOT.py 
from Realsense_projection import Realsense_projection
''' ROBOT CONFIGURATION '''
ROBOT_ID     = "dsr01"
ROBOT_MODEL  = "a0509"

''' SOLE N CONFIGUARTION '''
sole_n = 10

import DR_init
DR_init.__dsr__id = ROBOT_ID
DR_init.__dsr__model = ROBOT_MODEL
from DSR_ROBOT import *
from main_rl_environment import MyRLEnvironmentNode



if __name__ == "__main__":
    ''' NODE INITIALIZATION '''
    rospy.init_node('MY_RL_ENVINRONMENT')
    RL_node = MyRLEnvironmentNode(ROBOT_ID,ROBOT_MODEL,sole_n)
    RS_projection = Realsense_projection()
    set_robot_mode  = rospy.ServiceProxy('/'+ROBOT_ID + ROBOT_MODEL+'/system/set_robot_mode', SetRobotMode)
    pub_stop = rospy.Publisher('/'+ROBOT_ID +ROBOT_MODEL+'/stop', RobotStop, queue_size=10)           
    set_robot_mode(ROBOT_MODE_AUTONOMOUS)
    
    ''' TCP CONFIGURATION: deburring tool'''
    get_tcp = rospy.ServiceProxy('/'+ROBOT_ID +ROBOT_MODEL+ '/tcp/get_current_tcp', GetCurrentTcp)
    p0 = [-10,8,166,0,0,2.46]
    add_tcp("tcp", p0)
    set_tcp("tcp")

    ''' EPISODES START '''
    while not rospy.is_shutdown():
        # -------------------- Define the number of episodes ------------------#
        num_episodes = 3
        
        # -------------------- Start episodes ------------------#
        print "\n\nStarting episodes..."
        time.sleep(1.0)
        for episode in range (num_episodes):
            time.sleep(0.1)

            # -------------------- RESET ENVIRONMENT ------------------#
            RL_node.reset_evironment()
            time.sleep(0.5)
            print '\n\nEpisode %s started: Environment reset'% (episode+1)

            # -------------------- REALSENSE ACQUISITION ------------------# 
            print(RL_node.global_traj)
            RS_projection.transform_from_global_to_camera_frame(RL_node.global_traj)
            image_processed = RS_projection.project_to_image()
            cv2.namedWindow('Dice', cv2.WINDOW_NORMAL)
            cv2.imshow("Dice",image_processed)
            cv2.waitKey(0)


			# -------------------- GENERATE ACTION: TRAJECTORY ------------------#
            action = RL_node.action_step_generate_trajectory()
            
            # -------------------- PERFORM ACTION: EXECUTE TRAJECTORY ------------------#
            RL_node.action_step_perform_trajectory(action)
            
            time.sleep(2)

            print '\n\nEpisode %s Ended'% (episode+1)

        # -------------------- End of episodes ------------------#
        rospy.signal_shutdown("EPISODES ENDED")	
    
        
