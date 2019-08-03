#!/bin/bash
set -e


if [[ "$OSTYPE" == "linux-gnu" ]]; then
    echo "linux"
    # Install Python
    sudo apt-get install -y python2.7
    # optional, only needed for tests and building Binaryen
    sudo apt-get install -y cmake
    # optional, only needed for Closure Compiler minification
    sudo apt-get install -y default-jre
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # Install Xcode
    # Install git
    brew install cmake
fi


# Get the emsdk repo
rm -rf ~/.emsdk
git clone https://github.com/emscripten-core/emsdk.git ~/.emsdk

# Enter that directory
cd ~/.emsdk

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes ~/.emscripten file)
./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
echo 'source ~/.emsdk/emsdk_env.sh' >> ~/.bashrc
