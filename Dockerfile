FROM osrf/ros:melodic-desktop-full

# Environment variable -> set language to C (computer) UTF-8 (8 bit unicode transformation format).
ENV LANG C.UTF-8

# Debconf is used to perform system-wide configutarions.
# Noninteractive -> use default settings -> put in debconf db.
RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Set the nvidia container runtime.
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

# Environment variable -> see output in real time.
ENV PYTHONUNBUFFERED 1

# Install some handy tools.
RUN set -x \
        && apt-get update \
        && apt-get upgrade -y \
        && apt-get install -y  terminator wget python3-catkin-tools \
	&& apt install snapd -y



COPY ./Projects/src /root/catkin_ws/src
WORKDIR /root/catkin_ws/src
RUN rosdep install --from-paths doosan-robot --ignore-src --rosdistro melodic -r -y
WORKDIR /root/catkin_ws/
RUN rosdep install --from-paths src --ignore-src --rosdistro melodic
RUN sudo apt update -y\
	&& sudo apt install -y software-properties-common \
	&& sudo add-apt-repository ppa:deadsnakes/ppa \
	&& sudo apt update \
	&& sudo apt install -y python3.8 \
	&& sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.6 1 \
	&& sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 2 \
	&& sudo apt install -y python3.8-distutils \
	&& wget https://bootstrap.pypa.io/get-pip.py \
	&& sudo python3.8 get-pip.py 

RUN pip3.8 install rospkg \
	&& pip3.8 install opencv-python \
	&& pip3.8 install pyquaternion rosnumpy \
	&& pip3.8 install "numpy<1.24"  \
	&& pip3.8 install scipy \
	&& pip3.8 install pyrealsense2 \
	&& pip3.8 install tensorflow \
	&& pip3.8 install torch torchvision torchaudio


# add environment setup 
RUN echo 'source /opt/ros/melodic/setup.bash' >> /root/.bashrc
 
ENV MINICONDA_VERSION latest
ENV CONDA_DIR $HOME/miniconda3
RUN wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-$MINICONDA_VERSION-Linux-x86_64.sh -O ~/miniconda.sh && \
    chmod +x ~/miniconda.sh && \
    sudo ~/miniconda.sh -b -p $CONDA_DIR && \
    sudo rm ~/miniconda.sh
    
    

# make conda activate command available from /bin/bash --login shells
RUN echo ". $CONDA_DIR/etc/profile.d/conda.sh" >> ~/.profile

