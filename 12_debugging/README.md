# README

Demonstrate how to debug in gdb/lldb

TODO:

* single step debugging in gdb.  
* Can I do this across a process in a container?
  * THIS IS NOT WORKING YET

NOTES:

* clang++ and gdb hase diferent tools
* You can debug from mac to linux.  

## Build

```sh
make

# run it
./helloworld
```

## LLDB

```sh
lldb ./helloworld
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
platform shell ls -l 

platform process list

platform process launch helloworld


# disconnect
platform disconnect
```

## Resources

- https://www.vinnie.work/blog/2020-10-22-vscode-c-debug/
- https://stackoverflow.com/questions/51433937/how-to-compile-debug-a-c-application-in-docker-with-visual-studio-code-on-wind
- https://stackoverflow.com/questions/46001954/is-there-an-lldb-equivalent-to-gdbserver
- https://lldb.llvm.org/use/remote.html
