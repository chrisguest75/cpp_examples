# CROSS-COMPILE

Demonstrates how to cross compile an application to ARM.  

Ref: `vscode` extensions [README.md](../README.md)  

TODO:

* https://github.com/tonistiigi/binfmt
* Work out why it is not working.  

## NixEnv

```sh
just nix
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
* A master guide to Linux cross compiling [here](https://ruvi-d.medium.com/a-master-guide-to-linux-cross-compiling-b894bf909386)
* https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html
* https://mcilloni.ovh/2021/02/09/cxx-cross-clang/
