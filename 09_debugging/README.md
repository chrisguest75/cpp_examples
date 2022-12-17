# README

Demonstrate how to debug cpp in a container  

TODO:

* single step debugging in gdb.  
* 





## Docker

### clang

```sh
docker build -f Dockerfile.clang -t clangbuilder . 

docker run -it -p 1234:1234 -p 31200-31300:31200-31300 -v $(pwd):/scratch --entrypoint /bin/bash clangbuilder    

cd /scratch
make -f makefile.clang 

./helloworld

# can't get this to work.
lldb-server platform --listen "*:1234" --server -min-gdbserver-port 31200 --max-gdbserver-port 31300

lldb 
platform list
platform select remote-linux
platform select remote-macosx
platform connect connect://0.0.0.0:1234
platform settings -w /scratch
platform status
file ./helloworld
run

make -f makefile.clang clean
```


## Resources

* Remote Debugging [here](https://lldb.llvm.org/use/remote.html)  

https://www.vinnie.work/blog/2020-10-22-vscode-c-debug/




FOLLOW THIS: 
https://stackoverflow.com/questions/51433937/how-to-compile-debug-a-c-application-in-docker-with-visual-studio-code-on-wind

https://github.com/vadimcn/vscode-lldb/blob/master/MANUAL.md

https://code.visualstudio.com/docs/cpp/lldb-mi

