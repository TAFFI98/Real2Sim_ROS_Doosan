# Thesis: 
### Sim-to-Real and Real-to-Sim Transfer in Reinforcement Learning (RL) for Robotics

| Field           | Value                  |
|-----------------|------------------------|
| Student         | Martin Molinaro        |
| Co-supervisor   | Alessandra Tafuro      |
| Advisor         | Prof. Paolo Rocco      |
| University      | Politecnico di Milano  |
| Academic Year   | 2023-2024              |


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
### Learn to See:

In the folder in the main branch you can find the Learn to See folder with the main codes and info about the visual networks training. 
In particular there are three steps:
- Dataset creation: creates a dataset of RGB images of a shoe sole and their relative burred regions (as binary images)
- cGAN: train a Pix2Pix (cGAN) network for image segmentation of the rgb images of soles to detect the burred areas
- Autoencoders: train an AE to map the burred regions (binary imgs) into their external contours (binary img). The input burred regions are the ouptut images coming from the trained cGAN with some image processing applied, the output images are not used but the encoded latent vectors of 300 are later used as input of the Learn to Act network.
### Learn to Act:

In the branch Docker, you'll find all the data, instructions and info about each folder's content.
The docker represents the framework for all the codes relative to:
- simulate the enviroment with the robot, the sole and the camera
- learning to map information caming from the camera (and passing to the trained Learn to See networks) into an action of the robot to follow the burrs's external conotur trajectories

### Learn to Transfer
(put any files related to real robot apllication and any network adjustment/result based on that)


