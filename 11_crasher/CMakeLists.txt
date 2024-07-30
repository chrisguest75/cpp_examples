cmake_minimum_required(VERSION 3.10)

project(Crasher VERSION 1.0)

add_executable(crasher crasher.cpp)

target_compile_options(crasher PRIVATE -Wdiv-by-zero -Wall -Wextra)

