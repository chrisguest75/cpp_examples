# README

Demonstrates how to build and single step debug a CPP program using `cmake`  

Ref: `vscode` extensions [README.md](../README.md)  

## Install cmake

```sh
brew install cmake
```

## NixEnv

NOTE: At time of writing gcc14 is actually gcc13

```sh
nix-env -f. -iA tools -vvv

nix-shell -p gcc14 -p cmake -p just
gcc --version
cmake --version
just --version
```

## Build and Run

Select the Terminal > Run Build Task command.

```sh
# create make
just create

# build target
just build

# run 
just run

# cleanup
just clean
```

## Debugging

Use the debugger in `vscode`  

## Resources

* Drop Autotools for CMake [here](https://opensource.com/article/21/5/cmake)  
* C/C++ for Visual Studio Code [here](https://code.visualstudio.com/docs/languages/cpp)  
