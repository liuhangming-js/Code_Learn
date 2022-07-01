.model small
.stack
.data
    string1 db 'Equal or not'
    string2 db 'Equal or not'
.code
.startup
    mov ax, ds
    mov es, ax
    mov cx, lengthof string1
    mov si, offset string1
    mov di, offset string2
    cld
    repz cmpsb
    jnz unmat
    mov dl, 'y'
    jmp output
unmat:
    mov dl, 'n'
output:
    mov ah, 2
    int 21h
.exit 0
end