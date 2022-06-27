.model small
.stack
.data
    string db 'Hello!', 10, 13, '$'
.code
.startup
    mov bx, offset string
again:
    mov al, [bx]
    cmp al, 10
    je done
    cmp al, 'a'
    jb next
    cmp al, 'z'
    jg next
    and al, 0dfh
    mov [bx], al
next:
    inc bx
    jmp again
done:
    mov dx, offset string
    mov ah, 09h
    int 21h
.exit 0
end