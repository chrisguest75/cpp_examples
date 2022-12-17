        global   start
        section  .data
msg:            db       "Hello world!", 10
len             equ     $ - msg                 ;length of our dear string
version:        db       __?NASM_VER?__, 10
versionlen      equ     $ - version                 ;length of our dear string

        section  .text

; syscalls https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master
; 0x02000000 https://opensource.apple.com/source/xnu/xnu-792.13.8/osfmk/mach/i386/syscall_sw.h
start:  mov      rax, 0x02000004                ;write
        mov      rdi, 1                         ;stdout  
        mov      rsi, msg
        mov      rdx, len
        syscall

        mov      rax, 0x02000004                ;write
        mov      rdi, 1                         ;stdout
        mov      rsi, version
        mov      rdx, versionlen
        syscall

        mov      rax, 0x02000001                ;sysexit
        xor      rdi, rdi
        syscall

