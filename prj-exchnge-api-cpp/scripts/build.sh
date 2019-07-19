#!/bin/bash
set -e

proj=$(cd "$(dirname "${BASH_SOURCE[0]}")"; cd ..; pwd -P )

cd "$proj"
if [ ! -d "./build" ]; then
    mkdir build
    cd build
    cmake $* ..
fi

cd "$proj/build"
cmake --build . -- -j2
