#!/bin/bash
set -e
set -x

cd $(dirname $0)

rm -rf dot-files
git clone git@github.com:aminroosta/dot-files.git dot-files

docker build . -t ubuntu:v1

rm -rf dot-files 
