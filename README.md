# Thesis: 
### Bridging the Sim-to-Real Gap: Self-Supervised Trajectory Planning via Visual Perception for Robotic Deburring
# Paper: 
[PAPER](https://link.springer.com/article/10.1007/s11633-025-1560-6)

|         |                   |
|-----------------|------------------------|
| Author         | **Martin Molinaro**        |
| Co-supervisor   | **Alessandra Tafuro**     |
| Advisor         | **Prof. Paolo Rocco**      |
| University      | **Politecnico di Milano**  |
| Academic Year   | **2023-2024**              |


## Thesis content and structure:
This thesis focused on the application of machine learning to robotic deburring of a shoe sole, with the aim to enhance the performance of training the autonomus agent (Doosan Robot) in simulation (Gazebo) and then aplly it in reality. 

![0 3_thesis_structure](https://github.com/TAFFI98/Real2Sim_ROS_Doosan/assets/108731826/8aef490f-0529-452a-ab1d-832552d61d48)

The Learning phases encompass both the visual network and the reinforcement learning (specifically bandits) areas. 
The learning phases adopted are:
- **Learn to See**: Train visual networks to autonomously detect the burrs in the sole images, and then to efficiently encode these burrs images into latent vectors (used for following learning phase) able to decode the images of the external conoturs of the burrs (which are the trajectories the deburring tool will have to follow)
  
  ![1 2_visual_network](https://github.com/TAFFI98/Real2Sim_ROS_Doosan/assets/108731826/aceef7fe-1490-4832-8101-a2f0d30ccc75)

  
- **Learn to Act** : Train an agent (a contextual bandit) to purposefuly map the latent vector, coming from the trained visual networks from teh camera sole's image, into the spatial trajectories (here efficiently predicted as movement primitives weights) the cutting tool, attached to robot, has to follow to perform deburring on the working object. For comparison of different supervised approaches also a regressor has been trained.

  ![2 4_learn_to_act](https://github.com/TAFFI98/Real2Sim_ROS_Doosan/assets/108731826/747ce62d-4f45-49b3-874d-162066a12d05)

- **Learn to Transfer** : Methods and technique to transfer the knowledge acqured in simulation to the real robot

  ![3_approaches_rg](https://github.com/TAFFI98/Real2Sim_ROS_Doosan/assets/108731826/b32e7a15-01e0-4a92-8795-ff59df8a2bd8)


## Code structure:
![3_code_architecture](https://github.com/TAFFI98/Real2Sim_ROS_Doosan/assets/108731826/f3dd6668-c339-48b1-b394-05db1eb8e556)

### Learn to See:

In the folder in the main branch you can find the Learn to See folder with the main codes and info about the visual networks training. 
In particular there are three steps:
- Dataset creation: creates a dataset of RGB images of a shoe sole and their relative burred regions (as binary images)
- cGAN: train a Pix2Pix (cGAN) network for image segmentation of the rgb images of soles to detect the burred areas
- Autoencoders: train an AE to map the burred regions (binary imgs) into their external contours (binary img). The input burred regions are the ouptut images coming from the trained cGAN with some image processing applied, the output images are not used but the encoded latent vectors of 300 are later used as input of the Learn to Act network.

### Learn to Act:

The main code for the creation of the simulated environment compatible with the real scenario has been implemented with Docker. You can download the docker .zip folder in the latest Github release of this project. 
In the Docker, you'll find all the data, instructions and info about each folder's content.
The docker represents the framework for all the codes relative to:
- simulate the enviroment with the Doosan robot, the sole and the camera
- learning to map information coming from the camera (and passing to the trained Learn to See networks) into an action of the robot to follow the burrs's external conotur trajectories
- Collecting sim and real data, and test the trained acting networks in both environment

### Learn to Transfer
(the code relative to this part is implicitly implemented in the previous phases)

To set-up the real environment follow these steps:
- Turn on the Doosan A0509 robot (via teach pendant)
- Go to menu Home>Status and turn ON the Servo so the robot can move
- Mount the support with the Realsense D435i camera (then connect the cam to your PC with the usb cable) and the tool to the flange (if needed, you can move manually the robot with the botton of the hand on the cockpit of the robot)
- To connect to the robot:
  - **Connect to the wi-fi**: HOMBERGER-HUB-NETWORK

    *Settings*:
    - **ipv4 Method**: Manual
    - **Address**: 192.168.137.99
    - **Netmask**: 255.255.255.0
    - **password**: homberger
- In the docker container you can check if the connection has been established with:
```bash
apt-get install -y iputils-ping
ping 192.168.137.160
```
- Then use the Docker commands for the real robot





________________________________________________________________________________________________________

# Docker Guide
## Set-up
________________________________________________________________________________________________________

Make sure you make the scripts executable :
```bash
chmod +x 01_build_image.sh
```
```bash
chmod +x 02_run_container.sh
```
### Build the container image [~16.5GB]
A bash script is provided to build the container, it can be executed by entering the following command :
```bash
sudo ./01_build_image.sh 
```

### Start the container

To start the container execute the script below :
```bash
sudo ./02_run_container.sh
```

### Install and source the workspace
```bash
cd ~/catkin_ws
```
```bash
catkin_make
```
```bash
source ./devel/setup.bash
```

________________________________________________________________________________________________________
## Run the environment with Doosan Robot and camera
________________________________________________________________________________________________________

**IN THE FIRST TERMINAL** in container OR under the first terminal of the activated environment (if done):

#### RViZ-Gazebo with Virtual Doosan-robot: 
```bash
roslaunch dsr_launcher single_robot_rviz_gazebo_moveit_sole.launch model:=a0509  color:=blue gripper:=deburring_tool mode:=virtual 
```

#### RViZ with Real Doosan-robot: 
- To connect to the real robot and display it also in the simulation visalization tools
```bash
roslaunch dsr_launcher single_robot_rviz.launch model:=a0509  color:=blue gripper:=deburring_tool mode:=real host:=192.168.137.160 port:=12345
```
- To connect to the real camera, launch the realsense2 camera node (in **ANOTHER TERMINAL** in the container):
```bash
roslaunch realsense2_camera rs_camera.launch enable_color:=true color_width:=640 color_height:=480 color_fps:=15
```
\
**ANOTHER TERMINAL** in container and after doing catkin_make in the first terminal:
#### Source the workspace(if necessary)
```bash
source ./devel/setup.bash
```

________________________________________________________________________________________________________
## Learn to See 
________________________________________________________________________________________________________
***optional***: *just for visualization examples, the real Learn To See part was done out of this docker*
To run Gazebo sole's image simulation (specify sole):
```bash
roslaunch dsr_launcher single_robot_rviz_gazebo_moveit_sole.launch model:=a0509  color:=blue gripper:=deburring_tool mode:=virtual sole:=true sole_n:=10
```
In other terminal capture the images of the specified sole:
```bash
python3 /root/catkin_ws/src/learn_to_see/scripts/run_learn_to_see.py
```

________________________________________________________________________________________________________
## Learn to Act
________________________________________________________________________________________________________
Refer to learn_to_act package for further info on how to modify the scripts for settings
- Run Regressor
```bash
python3 /root/catkin_ws/src/learn_to_act/scripts/regressor_main.py
```
- Run Contextual Bandit (CB)
```bash
python3 /root/catkin_ws/src/learn_to_act/scripts/CB_main.py
```

________________________________________________________________________________________________________
## Learn to Transfer
________________________________________________________________________________________________________
- ***(To capture real images (and optionally process them with visual netwroks) if needed to collect real soles experimental data. Use the script:)***
```bash
python3 /root/catkin_ws/src/learn_to_act/scripts/real_data_acquisition.py
```




