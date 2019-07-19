#!/bin/bash
set -e

proj=$(cd "$(dirname "${BASH_SOURCE[0]}")"; cd ..; pwd -P )

cd "$proj/build"
../scripts/build.sh
./t
