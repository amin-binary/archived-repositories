#!/bin/bash
set -e

mkdir -p .dist && cd .dist

# emconfigure cmake -DCMAKE_CXX_FLAGS="-O0 --closure 0 --bind -s ENVIRONMENT=web -s MODULARIZE=1 " ..

# Release build: Use -O3 --closure 1
emconfigure cmake -DCMAKE_CXX_FLAGS="-Os --closure 1 --bind -s ENVIRONMENT=web -s MODULARIZE=1 " ..


emmake make

# Copy files to www folder
mkdir -p ../dist
cp chart-wasm.js ../www/
cp chart-wasm.wasm ../www/ 
