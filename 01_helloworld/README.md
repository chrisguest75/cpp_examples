# README

Demonstrates how to build and single step debug a CPP program  

`vscode` extensions [README.md](../README.md)  

NOTES: 

* makefiles need to use tabs by default.
* This supports `gcc` and `clang` builds.

TODO:

* make clean
* output directory

## Build and Run

Select the Terminal > Run Build Task command.  

[tasks.json](../.vscode/tasks.json) from repo root.  

```sh
clang++ --version
gcc --version    

# make from terminal
make -f makefile.clang 
make -f makefile.gcc
```

## Debugging

Use the debugger in `vscode`  

[launch.json](../.vscode/launch.json) from repo root.  

## Docker

### clang

```sh
docker build -f Dockerfile.clang -t clangbuilder . 

docker run -it -v $(pwd):/scratch --entrypoint /bin/bash clangbuilder    

cd /scratch
make -f makefile.clang 
```

### gcc

```sh
docker build -f Dockerfile.gcc -t gccbuilder . 

docker run -it -v $(pwd):/scratch --entrypoint /bin/bash gccbuilder    

cd /scratch
make -f makefile.gcc 
```

## Resources

* C/C++ for Visual Studio Code [here](https://code.visualstudio.com/docs/languages/cpp)  
* Creating A Basic Make File for Compiling C Code [here](https://www.codeproject.com/Articles/794764/Creating-A-Basic-Make-File-for-Compiling-C-Code)  

https://solarianprogrammer.com/2017/12/14/clang-in-docker-container-cpp-17-development/

https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.2

https://www.gnu.org/software/make/manual/html_node/Special-Variables.html#Special-Variables

https://stackoverflow.com/questions/14639794/getting-make-to-create-object-files-in-a-specific-directory