.model small
.stack
.data
    string db 'Tryyourbest! '
.code
.startup
    mov ax, ds
    mov es, ax
    mov di, offset string
    mov al, ' '
    mov cx, lengthof string
    repnz scasb
    je found
    mov dl, 'n'
    jmp output
found:
    mov dl, 'y'
output:
    mov ah, 2
    int 21h
.exit 0
end