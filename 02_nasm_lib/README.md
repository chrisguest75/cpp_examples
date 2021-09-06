# README
Demonstrates how to link an ASM lib with CPP

```sh
brew install nasm
code --install-extension 13xforever.language-x86-64-assembly
```


nasm -f macho hello.asm     
ld -e _start -o hello hello.o



It's not linking
https://stackoverflow.com/questions/52830484/nasm-cant-link-object-file-with-ld-on-macos-mojave

# Resources
http://salahuddin66.blogspot.com/2009/08/nasm-in-mac-os-x.html
https://orangejuiceliberationfront.com/intel-assembler-on-mac-os-x/
https://github.com/netwide-assembler/nasm