from ubuntu:18.04
workdir ~/


# Restore man pages
run yes | unminimize

# Install essential packages
run apt-get update && \
    DEBIAN_FRONTEND=noninteractive && apt-get install -y \
    curl git zsh vim tmux wget python-dev \
    cmake build-essential man-db

# Install oh my zsh
run wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true

# Set default timezone
RUN ln -sf /usr/share/zoneinfo/Europe/Amsterdam /etc/localtime


