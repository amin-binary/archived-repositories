FROM ubuntu:latest
VOLUME /app

WORKDIR /root

# Install used packages
RUN apt-get update
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:neovim-ppa/stable
RUN apt-get update
RUN apt-get install -y \
        git \
        gcc \
        tmux \
        curl \
        wget \
        ctags \
        neovim \
        python-dev \
        python-pip \
        python3-dev \
        python3-pip \
        openssh-client \
        silversearcher-ag

# Setup rust
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y
RUN ~/.cargo/bin/rustup toolchain add nightly
RUN ~/.cargo/bin/rustup component add rust-src
RUN ~/.cargo/bin/rustup component add rustfmt
RUN ~/.cargo/bin/cargo install rusty-tags
RUN ~/.cargo/bin/cargo +nightly install racer
RUN echo 'export RUST_SRC_PATH=$(rustc --print sysroot)/lib/rustlib/src/rust/src/' >> ~/.bashrc
RUN echo 'source ~/.cargo/env' >> ~/.bashrc

# Setup git
RUN git config --global user.name "amin roosta"
RUN git config --global user.email "amin.roosta@outlook.com"

COPY dot-files .
RUN .scripts/install-git-so-fancy.sh
RUN .scripts/install-bash-git-prompt.sh

