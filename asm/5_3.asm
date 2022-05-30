.model small
.stack
.data

.code
.startup
    mov ax, 1
re:
    cmp ax, 10
    je  done
    mov [bx], ax
    inc bx
    inc bx
    inc ax
    jmp re
done:
.exit 0
end