        global   start
        section  .text

start:  mov      rax, 0x02000004
        mov      rdi, 1
        mov      rsi, msg
        mov      rdx, len
        syscall

        mov      rax, 0x02000004
        mov      rdi, 1
        mov      rsi, version
        mov      rdx, versionlen
        syscall

        mov      rax, 0x02000001
        xor      rdi, rdi
        syscall

        section  .data
msg:            db       "Hello world!", 10
len             equ     $ - msg                 ;length of our dear string
version:        db       __?NASM_VER?__, 10
versionlen      equ     $ - version                 ;length of our dear string
