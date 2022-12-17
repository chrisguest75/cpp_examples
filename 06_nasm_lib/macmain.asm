        global   start
        section  .text

start:  mov      rax, 0x02000004
        mov      rdi, 1
        mov      rsi, msg
        mov      rdx, 13
        syscall
        mov      rax, 0x02000001
        xor      rdi, rdi
        syscall

        section  .data
msg:    db       "Hello world!", 10
