# CPP Examples

A repository for showing some CPP examples.

TODO:

* cppunit
* stl
* boost
* lint
* webassembly
* xcode
* abseil
* a docker image to build code for different platforms and cpu arch (added a pr to docker images.)
* ldconfig? ldd? static linking?

## VSCode Extensions

```sh
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cpptools-extension-pack
code --install-extension ms-vscode.makefile-tools
```

### MacOSX

```sh
clang++ --version
gcc --version    

# list installed packages
pkgutil --packages | sort     
# list files for a package.
pkgutil --files com.apple.pkg.CLTools_SDK_macOS10
pkgutil --files com.apple.pkg.CLTools_SDK_macOS12

# local libs and includes
ls /usr/local/lib  
ls /usr/local/include 
```

## 01 - Simple Hello World

Demonstrates how to build and single step debug a CPP program  
Steps [README.md](./01_helloworld_make/README.md)  

## 01 - Simple Hello World (using cmake)

Demonstrates how to build and single step debug a CPP program using `cmake`  
Steps [README.md](./01_helloworld_cmake/README.md)  

## 02 - Queue

Demonstrates how to create a program that inputs a set of numbers and prints them out.  
Steps [README.md](./02_queue/README.md)  

## 03 - Google test

Demonstrates how to use `googletest`  
Steps [README.md](./03_googletest_unittesting/README.md)  

## 08 - SC68

Building SC68 tools inside a docker container.  
Steps [README.md](./08_sc68/README.md)  

## 09 - devcontainer

Demonstrate a simple cpp container with `cmake`.  
Steps [README.md](./09_devcontainer/README.md)  


## Resources

* C++ reference [here](https://en.cppreference.com/w/)
* Xcode Release Notes [here](https://developer.apple.com/documentation/xcode-release-notes)  
* The POCO C++ Libraries are a collection of open source C++ class libraries that simplify and accelerate the development of network-centric, portable applications in C++. [here](https://docs.pocoproject.org/current/index.html)
* Abseil Logging [here](https://abseil.io/blog/)  
* boostorg/boost [here](https://github.com/boostorg/boost)
* Martchus/cpp-utilities [here](https://github.com/Martchus/cpp-utilities)
* stefanpantic/cpp-playground [here](https://github.com/stefanpantic/cpp-playground)
* https://github.com/stefanpantic/cpp-playground/tree/master/container-classes/Vector
