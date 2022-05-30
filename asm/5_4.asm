.model small
.stack
.data
.code
.startup
re:
    mov [bx], ax
    inc bx
    inc bx
    inc ax
    cmp ax, 10
    je  done
    jmp re
done:
.exit 0
end