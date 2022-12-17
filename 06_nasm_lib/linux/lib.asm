section  .data
msg:            db       "From linux asm library!", 10, 0
len             equ     $ - msg                 ;length of our dear string
version:        db       __?NASM_VER?__, 10, 0
versionlen      equ     $ - version                 ;length of our dear string

section  .text
global   get_version
global   get_message
bits 64						;64bit mode
get_version:  
        mov     rax, version
        ret

get_message:  
        mov     rax, msg
        ret
