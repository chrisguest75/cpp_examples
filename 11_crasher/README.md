# README

Demonstrates how to build and single step debug a CPP program using `cmake`  

Ref: `vscode` extensions [README.md](../README.md)  

TODO:

* Look at 10_conan
* Get boost program options linking.
        mkdir -p build
        cd build
        conan install .. 


## Install cmake

```sh
brew install cmake
```

## NixEnv

NOTE: At time of writing gcc14 is actually gcc13

```sh
cd ./11_crasher
nix-build
nix-shell 
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
* https://docs.conan.io/2/tutorial/consuming_packages.html
* https://www.boost.org/users/history/version_1_85_0.html
* Search more than 100 000 packages [here](https://search.nixos.org/packages?channel=24.05)
