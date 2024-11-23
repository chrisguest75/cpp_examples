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
just run --nullPointer 
just run --divideByZero 

# cleanup
just clean
```

## Debugging

Use the debugger in `vscode`  

## Resources

* https://github.com/boostorg/boost
* https://www.boost.org/
* https://conan.io/center/recipes/boost?version=1.86.0
* https://www.boost.org/doc/libs/1_86_0/doc/html/program_options/tutorial.html#id-1.3.30.4.3
* Drop Autotools for CMake [here](https://opensource.com/article/21/5/cmake)  
* C/C++ for Visual Studio Code [here](https://code.visualstudio.com/docs/languages/cpp)  
* https://docs.conan.io/2/tutorial/consuming_packages.html
* https://www.boost.org/users/history/version_1_85_0.html
* Search more than 100 000 packages [here](https://search.nixos.org/packages?channel=24.05)
