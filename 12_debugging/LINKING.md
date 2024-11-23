# LINKING

## Contents

- [LINKING](#linking)
  - [Contents](#contents)
  - [objdump - display information from object files](#objdump---display-information-from-object-files)
  - [readelf - display information about ELF files](#readelf---display-information-about-elf-files)
  - [nm - list symbols from object files](#nm---list-symbols-from-object-files)
  - [Resources](#resources)

## objdump - display information from object files

```sh
# disassemble
objdump -d ./helloworld 

# show symbol table
objdump -t ./helloworld
objdump -t ./obj/helloworld.o
```

## readelf - display information about ELF files

```sh
# see section headers nm
readelf -SW ./helloworld  
readelf -SW ./obj/helloworld.o     
```

## nm - list symbols from object files

```sh
# demangle names
nm -C ./obj/helloworld.o
```

## Resources
