# README

Demonstrates how to build and single step debug a CPP program using `cmake`  

Ref: `vscode` extensions [README.md](../README.md)  

## Install cmake

```sh
brew install cmake
```

## Build and Run

Select the Terminal > Run Build Task command.

```sh
# make from terminal
mkdir -p build && cd $_
# configure
cmake ..
# build
cmake --build .
# run
../build/helloworld
```

## Debugging

Use the debugger in `vscode`  

## Resources

* Drop Autotools for CMake [here](https://opensource.com/article/21/5/cmake)  
* C/C++ for Visual Studio Code [here](https://code.visualstudio.com/docs/languages/cpp)  
