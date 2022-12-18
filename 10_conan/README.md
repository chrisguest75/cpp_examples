# README

Demonstrate a quick example using conan package manager.  

TODO:

* A custom devcontainer feature for conan https://github.com/devcontainers/feature-starter

## Run

```sh
# start devcontainer
./startdevcontainer.sh -n=10_conan
```

Use `⌘ + ^ + p` and "Dev Containers: Attach to a running container"

Add `/workspaces/cpp_examples` as a workspace to the new vscode editor.  

## Build

```sh
cd ./10_conan
./build.sh
```

## Resources

* conan-io/examples repo [here](https://github.com/conan-io/examples)  
* https://conan.io/center/
* https://github.com/conan-io/training

undefined reference to Poco::DigestEngine https://github.com/conan-io/examples/issues/40