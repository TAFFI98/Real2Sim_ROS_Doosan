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
RUN sudo apt install python-pip -y
RUN pip install pyquaternion pathlib scipy
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

