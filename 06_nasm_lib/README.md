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
nasm -f macho hello.asm
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

# stack based
nasm -f elf hello.asm
ld -m elf_i386 hello.o -o out
./out

# register based
nasm -f elf main.asm
ld -m elf_i386 main.o -o main.exe
./main.exe
```

## Resources

http://salahuddin66.blogspot.com/2009/08/nasm-in-mac-os-x.html
https://orangejuiceliberationfront.com/intel-assembler-on-mac-os-x/
https://github.com/netwide-assembler/nasm

https://github.com/djmgit/asmenv/blob/master/bin/build_and_run.sh