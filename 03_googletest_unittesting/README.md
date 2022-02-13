# README

Demonstrates how to create a program that inputs a set of numbers and prints them out.  

`vscode` extensions [README.md](../README.md)  

## Prereqs

```sh
brew install cmake
```

## Build googletest

```sh
git clone https://github.com/google/googletest.git 
cd googletest 
rm -rf .git
mkdir install 
cd install 
make

cd ../..

# look at library exports (objdump as well)
nm --extern-only --demangle ./googletest/install/lib/libgtest.a

# build the tests
make
```

## Build and Run

Select the Terminal > Run Build Task command.

```sh
clang++ --version

# make from terminal
make && ./main
```

## Debugging

Use the debugger in `vscode`  

## Resources

https://github.com/google/googletest

https://alexanderbussan.medium.com/getting-started-with-google-test-on-os-x-a07eee7ae6dc
