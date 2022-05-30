.model small
.stack
.data 
    string  db 'Hello,World!', 0dh, 0ah, '$'
.code
.startup
    mov dx, offset string
    mov ah, 9
    int 21h
    mov ax, 4c00h
    int 21h
.exit 0
end