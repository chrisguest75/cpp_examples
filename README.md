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

## VSCode Extensions

```sh
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cpptools-extension-pack
```

```sh
# list installed packages
pkgutil --packages | sort     
# list files for a package.
pkgutil --files com.apple.pkg.CLTools_SDK_macOS12

# local libs and includes
ls /usr/local/lib  
ls /usr/local/include 
```

## Simple Hello World

Demonstrates how to build and single step debug a CPP program  
Steps [README.md](./01_helloworld/README.md)  

## Queue

Demonstrates how to create a program that inputs a set of numbers and prints them out.  
Steps [README.md](./02_queue/README.md)  

## Google test

Demonstrates how to use `googletest`  
Steps [README.md](./03_googletest_unittesting/README.md)  

## Resources

* C++ reference [here](https://en.cppreference.com/w/)
* https://github.com/stefanpantic/cpp-playground
* https://developer.apple.com/documentation/xcode-release-notes
* https://github.com/stefanpantic/cpp-playground/tree/master/container-classes/Vector
* https://docs.pocoproject.org/current/index.html
* https://github.com/Martchus/cpp-utilities
https://abseil.io/blog/

https://github.com/boostorg/boost