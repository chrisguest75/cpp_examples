# README

Demonstrates how to use `ghidra` to dissassmble code  

## Install

```sh
# replaces adoptopenjdk
brew install --cask temurin

# install ghidra
brew install ghidra
```

## Compile

```sh
clang++ --version

# make from terminal
make -f makefile.clang 
```

## Decompile

```sh
ghidraRun
```

Steps:

* Create a project in this folder.
* Import the `helloworld` tool.  
* Analyse.

NOTE: You may have to allow security and privacy for the decompiler and demnagler.  

## Resources

* A software reverse engineering (SRE) suite of tools developed by NSA's Research Directorate in support of the Cybersecurity mission [here](https://ghidra-sre.org/)  
* Eclipse Temurin [here](https://projects.eclipse.org/projects/adoptium.temurin)  
