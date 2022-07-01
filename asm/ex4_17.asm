.model small
.stack
.data
    n dw 3
    result dw ?
.code
.startup
    mov bx, n
    push bx

fact proc
    push ax
    push bx
    mov bp, sp
    mov ax, [bp+6]
    cmp ax, 0
    jne fact1
    inc ax
    jmp fact2
fact1:
    dec ax
    push ax
    call fact
    pop ax
    mul word ptr[bp+6]
fact2:
    mov [bp+6], ax
    pop bp
    pop ax
    ret
fact endp