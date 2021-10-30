FROM gcc:latest
# check for updates
RUN apt-get update
RUN apt-get upgrade -y
# mounts the volume to the root
VOLUME /root/env
# cd to the working directory
WORKDIR /root/env