# README

Demonstrate how to debug in gdb/lldb

TODO:

* single step debugging in gdb.  
* How do I debug when cmd requires stdin?
* Get source debugging working

NOTES:

* clang++ and gdb have diferent tools
* You can debug from mac to linux.  
* The debugger returns a random port to connect to - this means the debugger has to be on same network to work in docker.  

## Build

```sh
make

# run it
./helloworld
```

## LLDB

```sh
lldb ./helloworld

# run the executable
> run
```

## Docker

Run lldb in docker.  

### clang

```sh
# build
docker build -f Dockerfile.clang -t clangbuilder . 

# run debugger
docker run -p 1234:1234 -it clangbuilder
```

### Local Debugging

```sh
# set breakpoint
breakpoint set --file helloworld.cpp --line 7

# run
r

source list
frame info
```

### Remote Debugging

Attempt to connect to a container and single step debug.  

```sh
# server (run make and host)
docker run -p 1234:1234 --name clangbuilder -it clangbuilder
make
lldb-server platform --listen "0.0.0.0:1234" --server --  ./helloworld

# client
lldb
platform select remote-linux
platform list
platform connect connect://0.0.0.0:1234  

# is it connected
platform status

# list files on remote machine 
platform shell hostname
platform shell ls -l 

platform process list

platform process launch helloworld


target create ./helloworld

# disconnect
platform disconnect
```

## Resources

- Remote Containerized Debugging with VSCode C/C++ [here](https://www.vinnie.work/blog/2020-10-22-vscode-c-debug/)
- How to compile/debug a C++ application in Docker with Visual Studio Code on Windows [here](https://stackoverflow.com/questions/51433937/how-to-compile-debug-a-c-application-in-docker-with-visual-studio-code-on-wind)
- Is there an lldb equivalent to gdbserver? [here](https://stackoverflow.com/questions/46001954/is-there-an-lldb-equivalent-to-gdbserver)
- Remote Debugging [here](https://lldb.llvm.org/use/remote.html)
- https://lldb.llvm.org/man/lldb-server.html
- https://lldb.llvm.org/use/map.html
- https://lldb.llvm.org/use/tutorial.html

