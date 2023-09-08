# Install script for directory: /root/catkin_ws/src/doosan-robot/dsr_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/root/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs/msg" TYPE FILE FILES
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/LogAlarm.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/ModbusState.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/RobotError.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/RobotState.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/RobotStop.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/JogMultiAxis.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/AlterMotionStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/ServoJStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/ServoLStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/SpeedJStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/SpeedLStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/RobotStateRT.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/ServoJRTStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/ServoLRTStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/SpeedJRTStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/SpeedLRTStream.msg"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/msg/TorqueRTStream.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs/srv" TYPE FILE FILES
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetRobotMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetRobotMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetRobotSystem.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetRobotSystem.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetRobotSpeedMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetRobotSpeedMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetCurrentPose.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetSafeStopResetType.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetLastAlarm.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/GetRobotState.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetRobotControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/ManageAccessControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/ReleaseProtectiveStop.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./system/SetSafetyMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveJoint.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveLine.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveJointx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveCircle.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveSplineJoint.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveSplineTask.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveBlending.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveSpiral.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MovePeriodic.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveWait.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/Jog.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/JogMulti.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveStop.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MovePause.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveResume.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/Trans.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/Fkin.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/Ikin.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/IkinEx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/SetRefCoord.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/MoveHome.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/CheckMotion.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/ChangeOperationSpeed.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/EnableAlterMotion.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/AlterMotion.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/DisableAlterMotion.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./motion/SetSingularityHandling.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetControlMode.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetControlSpace.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentPosj.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetDesiredPosj.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentVelj.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetDesiredVelj.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentPosx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentToolFlangePosx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentVelx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetDesiredPosx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetDesiredVelx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentSolutionSpace.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetCurrentRotm.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetJointTorque.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetExternalTorque.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetToolForce.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetSolutionSpace.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./aux_control/GetOrientationError.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/ParallelAxis1.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/ParallelAxis2.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/AlignAxis1.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/AlignAxis2.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/IsDoneBoltTightening.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/ReleaseComplianceCtrl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/TaskComplianceCtrl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/SetStiffnessx.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CalcCoord.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/SetUserCartCoord1.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/SetUserCartCoord2.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/SetUserCartCoord3.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/OverwriteUserCartCoord.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/GetUserCartCoord.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/SetDesiredForce.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/ReleaseForce.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CheckPositionCondition.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CheckForceCondition.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CheckOrientationCondition1.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CheckOrientationCondition2.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/CoordTransform.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/GetWorkpieceWeight.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./force/ResetWorkpieceWeight.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tool/ConfigCreateTool.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tool/ConfigDeleteTool.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tool/SetCurrentTool.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tool/GetCurrentTool.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tool/SetToolShape.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tcp/ConfigCreateTcp.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tcp/ConfigDeleteTcp.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tcp/SetCurrentTcp.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./tcp/GetCurrentTcp.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/SetToolDigitalOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/GetToolDigitalOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/GetToolDigitalInput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/SetCtrlBoxDigitalOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/GetCtrlBoxDigitalOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/GetCtrlBoxDigitalInput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/SetCtrlBoxAnalogInputType.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/SetCtrlBoxAnalogOutputType.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/SetCtrlBoxAnalogOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./io/GetCtrlBoxAnalogInput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./modbus/ConfigCreateModbus.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./modbus/ConfigDeleteModbus.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./modbus/SetModbusOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./modbus/GetModbusInput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./drl/DrlStart.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./drl/DrlStop.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./drl/DrlPause.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./drl/DrlResume.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./drl/GetDrlState.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./gripper/Robotiq2FClose.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./gripper/Robotiq2FOpen.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./gripper/Robotiq2FMove.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./gripper/SerialSendData.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/ConnectRTControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/DisconnectRTControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/GetRTControlInputDataList.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/GetRTControlInputVersionList.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/GetRTControlOutputDataList.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/GetRTControlOutputVersionList.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/ReadDataRT.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetAccJRT.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetAccXRT.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetRTControlInput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetRTControlOutput.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetVelJRT.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/SetVelXRT.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/StartRTControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/StopRTControl.srv"
    "/root/catkin_ws/src/doosan-robot/dsr_msgs/srv/./realtime/WriteDataRT.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs/cmake" TYPE FILE FILES "/root/catkin_ws/build/doosan-robot/dsr_msgs/catkin_generated/installspace/dsr_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/root/catkin_ws/devel/include/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/share/roseus/ros/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/share/common-lisp/ros/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/root/catkin_ws/devel/share/gennodejs/ros/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/root/catkin_ws/devel/lib/python2.7/dist-packages/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/root/catkin_ws/devel/lib/python2.7/dist-packages/dsr_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/root/catkin_ws/build/doosan-robot/dsr_msgs/catkin_generated/installspace/dsr_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs/cmake" TYPE FILE FILES "/root/catkin_ws/build/doosan-robot/dsr_msgs/catkin_generated/installspace/dsr_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs/cmake" TYPE FILE FILES
    "/root/catkin_ws/build/doosan-robot/dsr_msgs/catkin_generated/installspace/dsr_msgsConfig.cmake"
    "/root/catkin_ws/build/doosan-robot/dsr_msgs/catkin_generated/installspace/dsr_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/dsr_msgs" TYPE FILE FILES "/root/catkin_ws/src/doosan-robot/dsr_msgs/package.xml")
endif()

