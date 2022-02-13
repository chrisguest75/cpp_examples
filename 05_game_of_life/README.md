# README

Create a game-of-life example.

`vscode` extensions [README.md](../README.md)  

TODO:

* Load files
* Vistor pattern for grid

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
cmake ../
make

cd ../..

# look at library exports (objdump as well)
nm --extern-only --demangle ./googletest/install/lib/libgtest.a

# build and run the tests
make && ./gameoflife tests
# run program
make && ./gameoflife
```

## Debugging

Use the debugger in `vscode`  

## Resources

* Getting Started with Google Test on macOS [here](https://alexanderbussan.medium.com/getting-started-with-google-test-on-os-x-a07eee7ae6dc)  
* Google Test [repo](https://github.com/google/googletest)  
