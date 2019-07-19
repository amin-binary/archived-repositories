#!/bin/bash
set -e
proj=$(cd "$(dirname "${BASH_SOURCE[0]}")"; cd ..; pwd -P )

# build the project
./scripts/build.sh

cd "$proj"

# watch for test cahnges
watchman-make -p '**/*.cc' '**/*.h' --run scripts/test.sh

# install facebook.github.io/watchman
#   git clone https://github.com/facebook/watchman.git
#   cd watchman
#   git checkout v4.9.0  # the latest stable release
#   ./autogen.sh
#   ./configure --enable-lenient #disable warnings
#   make
#   sudo make install
