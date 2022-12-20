#!/bin/bash

set -e
set -x


rm -rf /root/.conan
rm -rf build
mkdir build && pushd $_

conan profile new default --detect 
conan profile update settings.compiler.libcxx=libstdc++11 default 
conan install .. 

cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

bin/md5