#!/usr/bin/env python

import rospy
import os
import threading, time
import sys
sys.dont_write_bytecode = True
sys.path.append( os.path.abspath(os.path.join("/root/catkin_ws/src/doosan-robot/common/imp")) ) # get import path : DSR_ROBOT.py 

# for single robot 
ROBOT_ID     = "dsr01"
ROBOT_MODEL  = "a0509"
sole_n = 10
import DR_init
DR_init.__dsr__id = ROBOT_ID
DR_init.__dsr__model = ROBOT_MODEL
from DSR_ROBOT import *
from main_rl_environment import MyRLEnvironmentNode


   



if __name__ == "__main__":
    rospy.init_node('MY_RL_ENVINRONMENT')
    RL_node = MyRLEnvironmentNode(ROBOT_ID,ROBOT_MODEL,sole_n)
    set_robot_mode  = rospy.ServiceProxy('/'+ROBOT_ID + ROBOT_MODEL+'/system/set_robot_mode', SetRobotMode)
   
    t1 = threading.Thread(target = RL_node.thread_subscriber)
    t1.daemon = True 
    t1.start()
    
    pub_stop = rospy.Publisher('/'+ROBOT_ID +ROBOT_MODEL+'/stop', RobotStop, queue_size=10)           
    set_robot_mode(ROBOT_MODE_AUTONOMOUS)
    

    get_tcp = rospy.ServiceProxy('/'+ROBOT_ID +ROBOT_MODEL+ '/tcp/get_current_tcp', GetCurrentTcp)
    p0 = [-10,8,166,-9.740,0,0]
    add_tcp("tcp", p0)
    set_tcp("tcp")


    while not rospy.is_shutdown():
        # -------------------- Define the number of episodes ------------------#
        num_episodes = 3
        # -------------------- Evaluate the initial pose of the sole ------------------#
        _, initial_sole_ori = RL_node.get_current_sole_pose() 
        
        # -------------------- Start episodes ------------------#
        print("Starting episodes...")
        time.sleep(1.0)
        for episode in range (num_episodes):
            time.sleep(0.1)

            # -------------------- RESET ENVIRONMENT ------------------#
            RL_node.reset_evironment(initial_sole_ori)
            time.sleep(0.5)
            print ('Episode %s started: Environment reset'% (episode+1))

			# -------------------- GENERATE ACTION: TRAJECTORY ------------------#
            action = RL_node.action_step_generate_trajectory()
            
            # -------------------- PERFORM ACTION: EXECUTE TRAJECTORY ------------------#
            RL_node.action_step_perform_trajectory(action)
            
            time.sleep(2)

            print ('Episode %s Ended'% (episode+1))

        # -------------------- End of episodes ------------------#
        rospy.signal_shutdown("EPISODES ENDED")	
    
        
