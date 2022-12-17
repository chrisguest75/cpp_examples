# README

Demonstrates how to link an ASM lib with CPP

## Prereqs

```sh
# install nasm
brew install nasm

# install extension
code --install-extension 13xforever.language-x86-64-assembly
```

## Build

```sh
nasm -f macho64 hello.asm
ld -e _start -o hello hello.o
```


It's not linking on macosx
https://stackoverflow.com/questions/52830484/nasm-cant-link-object-file-with-ld-on-macos-mojave


## Docker Playground

```sh
# Build
docker build -f Dockerfile.nasm -t nasm . 

# Start container
docker run -v $(pwd):/scratch --rm -it nasm

# switch into zsh
zsh
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

### Register based 

```sh
# register based
mkdir -p ./build/main
# based
nasm -f elf -o ./build/main/main.o main.asm
# link
ld -m elf_i386 ./build/main/main.o -o ./build/main/main
# run
./build/main/main
```

## Resources

* netwide-assembler/nasm repo [here](https://github.com/netwide-assembler/nasm)  
* NASM - The Netwide Assembler repo [here](https://www.nasm.us/xdoc/2.15.05/html/nasmdoc0.html)  

http://salahuddin66.blogspot.com/2009/08/nasm-in-mac-os-x.html
https://orangejuiceliberationfront.com/intel-assembler-on-mac-os-x/

https://github.com/djmgit/asmenv/blob/master/bin/build_and_run.sh