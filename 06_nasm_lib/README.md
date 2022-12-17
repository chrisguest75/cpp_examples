# README

Demonstrates how to link an ASM lib with CPP

TODO:

* call conventions

## Prereqs

```sh
# install nasm
brew install nasm

# install extension
code --install-extension 13xforever.language-x86-64-assembly
```

## Build exe (macos)

```sh
mkdir -p ./build/mac

# build
nasm -f macho64 -o ./build/mac/main.o ./macos/main.asm

# link
ld -e start -static -o ./build/mac/main ./build/mac/main.o

# run
./build/mac/main 
```

## Build CMake Library (macos)

```sh
mkdir -p ./macos/build && cd $_
# configure
cmake ..
# build
cmake --build .
# run
./helloworld
```

## Docker Playground

```sh
# Build
docker build -f Dockerfile.nasm -t nasm . 

# Start container
docker run -v $(pwd):/scratch --rm -it nasm
```

### Register based (call convention)

```sh
# register based
mkdir -p ./build/linux/main

# based
nasm -f elf -o ./build/linux/main/main.o ./linux/main.asm

# link
ld -m elf_i386 ./build/linux/main/main.o -o ./build/linux/main/main

# run
./build/linux/main/main
```

## Build CMake Library (linux)

```sh
mkdir -p ./linux/build && cd $_
# configure
cmake ..
# build
cmake --build .
# run
./helloworld
```

## Resources

* netwide-assembler/nasm repo [here](https://github.com/netwide-assembler/nasm)  
* NASM - The Netwide Assembler repo [here](https://www.nasm.us/xdoc/2.15.05/html/nasmdoc0.html)  
* Intel assembler on Mac OS X [here](https://orangejuiceliberationfront.com/intel-assembler-on-mac-os-x/)
* djmgit/asmenv [here](https://github.com/djmgit/asmenv/blob/master/bin/build_and_run.sh)
* nasm - Can't link object file with ld on macOS Mojave [here](https://stackoverflow.com/questions/52830484/nasm-cant-link-object-file-with-ld-on-macos-mojave)
* Ybalrid/cmake-cpp-nasm repo [here](https://github.com/Ybalrid/cmake-cpp-nasm)  
* Mac OS X 64 bit Assembly System Calls [here](http://dustin.schultz.io/mac-os-x-64-bit-assembly-system-calls.html)  
* BSD syscalls [here](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)
* 0x02000000 [here](https://opensource.apple.com/source/xnu/xnu-792.13.8/osfmk/mach/i386/syscall_sw.h)

