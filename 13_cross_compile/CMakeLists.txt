cmake_minimum_required(VERSION 3.10)
set(CMAKE_CROSSCOMPILING TRUE)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_CXX_COMPILER clang++)

project(Helloworld VERSION 1.0)

add_executable(helloworld helloworld.cpp)