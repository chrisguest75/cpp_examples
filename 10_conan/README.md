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

## Troubleshooting

```sh
rm -rf /root/.conan
ls -la /root/
```

## Resources

* conan-io/examples repo [here](https://github.com/conan-io/examples)  
* The place to find and share popular C/C++ Conan packages [here](https://conan.io/center/)  
* conan-io/training repo [here](https://github.com/conan-io/training)
* undefined reference to Poco::DigestEngine [here](https://github.com/conan-io/examples/issues/40)
* [bug] example poco/md5 fails with "undefined reference" #6808 [here](https://github.com/conan-io/conan/issues/6808)