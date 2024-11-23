cmake_minimum_required(VERSION 3.10)

project(crasher VERSION 1.0)

add_executable(${PROJECT_NAME} src/crasher.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wdiv-by-zero -Wall -Wextra)

