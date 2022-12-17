; Hello World Program
; taken from https://asmtutor.com

SECTION .data
msg             db      'Hello World!', 0Ah
len             equ     $ - msg                 ;length of our dear string
version:        db       __?NASM_VER?__, 10
versionlen      equ     $ - version               

SECTION .text
global  _start
 
_start:
 
    mov     edx, len
    mov     ecx, msg
    mov     ebx, 1
    mov     eax, 4
    int     80h

    mov     edx, versionlen
    mov     ecx, version
    mov     ebx, 1
    mov     eax, 4
    int     80h

    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    int     80h