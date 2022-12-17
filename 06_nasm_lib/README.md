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

## Build (macos)

```sh
mkdir -p ./build/mac

# build
nasm -f macho64 -o ./build/mac/main.o ./macos/main.asm

# link
ld -e start -static -o ./build/mac/main ./build/mac/main.o

# run
./build/mac/main 
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

### Stack based 

```sh
# stack based
mkdir -p ./build/hello
# build
nasm -f elf -o ./build/hello/hello.o hello.asm

# link
ld -m elf_i386 ./build/hello/hello.o -o ./build/hello/hello

# run
./build/hello/hello
```

## Resources

* netwide-assembler/nasm repo [here](https://github.com/netwide-assembler/nasm)  
* NASM - The Netwide Assembler repo [here](https://www.nasm.us/xdoc/2.15.05/html/nasmdoc0.html)  
* Intel assembler on Mac OS X [here](https://orangejuiceliberationfront.com/intel-assembler-on-mac-os-x/)
* djmgit/asmenv [here](https://github.com/djmgit/asmenv/blob/master/bin/build_and_run.sh)
* nasm - Can't link object file with ld on macOS Mojave [here](https://stackoverflow.com/questions/52830484/nasm-cant-link-object-file-with-ld-on-macos-mojave)
* Ybalrid/cmake-cpp-nasm repo [here](https://github.com/Ybalrid/cmake-cpp-nasm)  
