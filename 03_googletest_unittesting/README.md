# README

Demonstrates how to use `googletest`  

`vscode` extensions [README.md](../README.md)  

## Prereqs

```sh
brew install cmake
```

## Build and Run

```sh
git clone https://github.com/google/googletest.git 
cd googletest 
rm -rf .git
mkdir install 
cd install 
cmake ../
make

cd ../..

# look at library exports (objdump as well)
nm --extern-only --demangle ./googletest/install/lib/libgtest.a

# build the tests
make && ./sumProgram
```
## Resources

* Getting Started with Google Test on macOS [here](https://alexanderbussan.medium.com/getting-started-with-google-test-on-os-x-a07eee7ae6dc)
* Google Test [repo](https://github.com/google/googletest)

