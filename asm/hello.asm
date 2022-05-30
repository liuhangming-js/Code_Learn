.model small
.stack
.data
X   db 'a', 6
    db 2 dup(100), ?
Y   db 'ABC'
.code
.startup
    mov ax, seg X
    mov dl, al
    mov al, 02h
    int 21h
.exit 0
end