cmake_minimum_required(VERSION 2.8.3)
project(RL_environment)
find_package(catkin REQUIRED COMPONENTS
roscpp
rospy
sensor_msgs
cv_bridge)
catkin_package(CATKIN_DEPENDS roscpp rospy sensor_msgs cv_bridge)

install(DIRECTORY config launch meshes rviz urdf xacro
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


install(PROGRAMS
  scripts/run_environment.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


install(PROGRAMS
scripts/rmain_rl_environment.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)