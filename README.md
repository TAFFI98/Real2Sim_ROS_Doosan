version https://git-lfs.github.com/spec/v1
oid sha256:ce2747b5e8391bfbdb83d77627cb237372cfda3c6be8101f31306cc6bc220ed5
size 64

# Docker commands
(if you have your user added to the docker group ignore the sudo)

[List all images, gives IDs]
sudo docker image ls -a

[List alla containers, gives IDs]
sudo docker ps -a

[Remove particular image]
sudo docker rmi <your-image-id> 

[Remove particular container]
sudo docker rm <your-container-id> 

[Stop and remove all containers]
sudo docker stop $(sudo docker ps -aq)
sudo docker rm $(sudo docker ps -aq)

[Enter into a container from terminal]
sudo docker exec -it <container_id> bash 

[After building image if / partition is running out of space remove the build cache]
sudo docker system prune --volumes

# ROS melodic with python3 compatibility

This container contains the scripts to build and run a ROS melodic container.
This container also provide python3 with deep learning framework and utilities installation packages.
Dockerfile author: Alessandra Tafuro (email="taffi98.at@gmail.com") 


## Set-up

[Make sure you make the scripts executable] :
bash
chmod +x 01_build_image.sh

bash
chmod +x 02_run_container.sh

## How to build the container image [~16.5GB]
[A bash script is provided to build the container, it can be executed by entering the following command] :
bash
sudo ./01_build_image.sh 

## How to start the container

[To start the container execute the script below] :
bash
sudo ./02_run_container.sh


# ------------- INSTALL AND SOURCE THE WORKSPACE  --------------- #
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash



#################### OPTIONAL (testing with python codes) ####################

You can test the Learn to See phase and algorithms used later during the RL phase: along with the simulation environment (subsequent command section), you need to create and activate python (conda) environments for these codes. 

# ------------- How to CREATE conda env  --------------- #

[IN THE FIRST TERMINAL in container]

-[If you want to test LearnToSee framework (just form mapping and visualization)] :
 conda env create -f /root/catkin_ws/learn_to_see_mapping/environment.yml 
-[If you want to test LearnToSee final GAN network(with actual decoded images)]
 conda env create -f /root/catkin_ws/learn_to_see_gan/environment.yml 
-[If you want to test MovementPrimitives algorithms] : 
 conda env create -f /root/catkin_ws/MP/environment.yml 
 
conda init bash


[If you got an error about "conda" command not being found, try to use instead] :
cd /miniconda3/bin
./conda env create -f /root/catkin_ws/learn_to_see_mapping/environment.yml
./conda env create -f /root/catkin_ws/learn_to_see_gan/environment.yml 
./conda env create -f /root/catkin_ws/MP/environment.yml
./conda init bash


# ------------- How to ACTIVATE conda env and run the python codes --------------- #

[in another terminal opended after creting the environment and doing conda init bash]
conda activate myenv
conda activate myenv_gan (GAN)
python /root/catkin_ws/learn_to_see_mapping/3Dto2D.py
python /root/catkin_ws/learn_to_see_gan/GAN_decoder.py (GAN)

python /root/catkin_ws/MP/MP.py

#################### END OPTIONAL ####################





#################### SIMULATION ####################

[IN THE FIRST TERMINAL in container OR under the first terminal of the activated environment (if done)]
# ------------- RVIZ GAZEBO WITH SOLE (LAUNCH FILE FOR LEARN TO SEE DATASET GENERATION AND RL_ENVIRONEMNT)  --------------- #
roslaunch dsr_launcher single_robot_rviz_gazebo_moveit_sole.launch model:=a0509  color:=blue gripper:=deburring_tool mode:=virtual 

[NEW TERMINAL in container and with catkin_make]
# ------------- SOURCE WORKSPACE (if necessary)  --------------- #
cd ~/catkin_ws
source ./devel/setup.bash

# ------------- To run LEARN TO SEE DATASET GENERATION (optional, just for visualization examples)  --------------- #
python3 /root/catkin_ws/src/learn_to_see/scripts/run_learn_to_see.py


# ------------- To run RL ENVIRONMENT --------------- #
python3 /root/catkin_ws/src/RL_environment/scripts/run_environment.py

# ------------- To run SL ENVIRONMENT --------------- #
python3 /root/catkin_ws/src/RL_environment/scripts/trajectory_generator.py

# ------------- To run RL-CMAB ENVIRONMENT --------------- #
python3 /root/catkin_ws/src/RL_environment/scripts/CMAB_train.py



