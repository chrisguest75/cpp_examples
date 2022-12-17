cmake_minimum_required(VERSION 3.14)
project(helloworld VERSION 1.0)

#Set C++ language version
set(CMAKE_CXX_STANDARD 17)
enable_language(ASM_NASM)


if(APPLE)
        #Add leading underscore when building macho64 object files
        string(APPEND CMAKE_ASM_NASM_FLAGS "--prefix _")
endif(APPLE)

add_executable(helloworld helloworld.cpp lib.asm)
