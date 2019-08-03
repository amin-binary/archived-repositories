#!/bin/bash

rm -rf dist && mkdir -p dist
rm -rf .dist && mkdir -p .dist/

bash ./.build.sh

watchman-make -p '**/*.cc' --run ./.build.sh
