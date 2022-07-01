.model small
.stack
.data
    string1 db 'Try your best.$'
    string2 db sizeof string1 dup(?)
.code
.startup
    mov ax, ds
    mov es, ax
    mov si, offset string1
    mov di, offset string2
    mov cx, lengthof string1
    cld
    rep movsb
print:
    mov dx, offset string2
    mov ah, 9
    int 21h
.exit 0
end