# README

Demonstrate a simple cpp container with `cmake`.  

## Example

Based on my examples from devcontainer_examples:

* [devcontainer_examples/README.md](https://github.com/chrisguest75/devcontainer_examples/tree/master/README.md)  

## Start (vscode)

```sh
npm install -g @vscode/dev-container-cli  
```

```sh
devcontainer up --remove-existing-container --build-no-cache --config $(pwd)/.devcontainer/06_cpp/devcontainer.json
```

Use `⌘ + ^ + p` and "Dev Containers: Attach to a running container"

Add `/workspaces/devcontainer_examples` as a workspace to the new vscode editor.  

```sh
cd /workspaces/devcontainer_examples
```

## Run

```sh
# start devcontainer
./startdevcontainer.sh -n=09_devcontainer 
```

## Run tests

```sh
cd ./01_helloworld_cmake
echo $DEVCONTAINER_TYPE

mkdir -p build
cd build
cmake ..

cmake --build .  
./helloworld
```

## Resources

