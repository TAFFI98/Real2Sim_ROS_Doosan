#!/usr/bin/env python
import time
from main_rl_environment import MyRLEnvironmentNode
import rospy


def main(args=None):
    # -------------------- Initialize node ------------------#
    rospy.init_node('LearnToSee_node', anonymous=True)
    learn_to_see_node = MyRLEnvironmentNode()
    while not rospy.is_shutdown():
        # -------------------- Define the number of episodes ------------------#
        num_episodes = 3

        # -------------------- Start episodes ------------------#
        print("Starting episodes...")

        for episode in range (num_episodes):

            print ('Episode %s Ended'% (episode+1))

        # -------------------- End of episodes ------------------#
        rospy.signal_shutdown("EPISODES ENDED")	
	
    
    print ("Total num of episodes completed, Exiting ....")

if __name__ == '__main__':
	main()