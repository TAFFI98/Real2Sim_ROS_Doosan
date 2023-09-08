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
        && apt-get install -y  terminator python3-catkin-tools \
	&& apt install snapd -y



COPY ./Projects/src ~/catkin_ws/src
WORKDIR ~/catkin_ws/src
RUN rosdep install --from-paths doosan-robot --ignore-src --rosdistro melodic -r -y




