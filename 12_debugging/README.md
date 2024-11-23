# README

Demonstrate how to debug in gdb/lldb

NOTES:

- clang++ and gdb have diferent tools
- You can debug from mac to linux.  
- The debugger returns a random port to connect to - this means the debugger has to be on same network to work in docker (use compose).  
- It looks like it's a known issue trying to debug with programs that require `cin`.  

## Contents

- [README](#readme)
  - [Contents](#contents)
  - [Local](#local)
    - [Build](#build)
    - [LLDB](#lldb)
  - [Docker](#docker)
    - [clang](#clang)
    - [Local Debugging](#local-debugging)
    - [Remote Debugging](#remote-debugging)
      - [Server](#server)
      - [Client](#client)
        - [Example Commands](#example-commands)
      - [Cleanup](#cleanup)
  - [Resources](#resources)

TODO:

- single step debugging in gdb.  
- How do I debug when cmd requires stdin?
- Get source debugging working

## Local

### Build

Build locally.  

```sh
make CC=clang++

# run it
./helloworld
```

### LLDB

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

#### Server

Start the server hosting the code.  

```sh
just start_compose
just attach_server 
# server (run make and host)
make CC=clang++
echo "Waiting..."
lldb-server platform --listen "0.0.0.0:1234" --server --  ./bin/helloworld
```

#### Client

Remote debug from the client.  

```sh
just attach_client 
lldb
```

##### Example Commands

[github.com/reveng007/GDB-Cheat-Sheet](https://github.com/reveng007/GDB-Cheat-Sheet)  

Connecting

```sh
log enable gdb-remote packets"
platform status
platform list
platform select remote-linux
platform connect connect://0.0.0.0:1234
platform connect connect://server:1234
platform process launch /scratch/helloworld
target create /scratch/helloworld
breakpoint set --file helloworld.cpp --line 16
platform shell ls -l
gui
platform disconnect
```

Execution

```sh
bt - show stacktrace
```

#### Cleanup

```sh
just stop_compose
```

## Resources

- Remote Containerized Debugging with VSCode C/C++ [here](https://www.vinnie.work/blog/2020-10-22-vscode-c-debug/)
- How to compile/debug a C++ application in Docker with Visual Studio Code on Windows [here](https://stackoverflow.com/questions/51433937/how-to-compile-debug-a-c-application-in-docker-with-visual-studio-code-on-wind)
- Is there an lldb equivalent to gdbserver? [here](https://stackoverflow.com/questions/46001954/is-there-an-lldb-equivalent-to-gdbserver)
- Remote Debugging [here](https://lldb.llvm.org/use/remote.html)
- lldb-server – Server for LLDB Debugging Sessions [here](https://lldb.llvm.org/man/lldb-server.html)
- GDB to LLDB command map [here](https://lldb.llvm.org/use/map.html)
- LLDB Tutorial [here](https://lldb.llvm.org/use/tutorial.html)

