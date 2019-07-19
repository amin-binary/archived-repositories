#!/bin/bash
set -e

mkdir -p ~/.tmp && cd ~/.tmp
rm -rf watchman-4.9.0
curl -L https://github.com/facebook/watchman/archive/v4.9.0.tar.gz | tar xzf -
cd watchman-4.9.0

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    # Linux (tested on ubuntu 18.04)
    sudo apt-get install -y libtool libssl-dev autoconf automake build-essential pkg-config;
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # Mac OSX
    brew install libtool openssl autoconf automake pkg-config python@2;
fi

./autogen.sh
./configure --enable-lenient --without-python
make
sudo make install

