# README

Demonstrate an example of using DevStudio on Windows.  

TODO:

* Add a cmdline parser

## Prerequisites

* Add markdown editor v2 extension
* Install Conan app

## Configure

Open a conan shell then.  

```sh
conan install nlohmann_json/3.11.2@ --build=missing
conan install args-parser/6.3.2@

conan install .
```

Add conanbuildinfo.props to build...  

## Building and Running

```sh
# create iso date string
Get-Date -format s

# after building the solution
.\x64\Debug\11_windows_devstudio.exe --help
.\x64\Debug\11_windows_devstudio.exe add file .\test.json
```

## Resources

* Conan Centre for json [here](https://conan.io/center/nlohmann_json?tab=useit)
* https://docs.conan.io/en/1.8/integrations/visual_studio.html
* https://github.com/nlohmann/json#creating-json-objects-from-json-literals
* https://github.com/nlohmann/json



https://conan.io/center/args-parser

https://github.com/igormironchik/args-parser

