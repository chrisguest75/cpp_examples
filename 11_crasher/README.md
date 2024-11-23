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

```sh
just build_docker

just start_docker

just shell_docker

# inside container
gdb
run ./build/crasher --nullPointer
```

Use the debugger in `vscode`  

## Resources

* github.com/boostorg/boost repo [here](https://github.com/boostorg/boost)
* Boost provides free peer-reviewed portable C++ source libraries. [here](https://www.boost.org/)
* Conan boost/1.86.0 package [here](https://conan.io/center/recipes/boost?version=1.86.0)
* Boost Program Options [here](https://www.boost.org/doc/libs/1_86_0/doc/html/program_options/tutorial.html#id-1.3.30.4.3)
* Drop Autotools for CMake [here](https://opensource.com/article/21/5/cmake)  
* C/C++ for Visual Studio Code [here](https://code.visualstudio.com/docs/languages/cpp)  
* Consuming packages [here](https://docs.conan.io/2/tutorial/consuming_packages.html)
* Boost 1.85.0 Release Notes [here](https://www.boost.org/users/history/version_1_85_0.html)
* Search more than 100 000 packages [here](https://search.nixos.org/packages?channel=24.05)
