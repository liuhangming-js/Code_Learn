.model small
.stack
.data
    string db 'Let us have a try! ', '$'
.code
.startup
    mov si, offset string
outlp:
    cmp byte ptr[si], '$'
    je done
    cmp byte ptr[si], ' '
    jne next
    mov di, si
    mov ah, count
    dec ah
inlp:
    inc di
    mov al, [di]
    mov [di-1], al
    cmp byte ptr[di], '$'
    jnz inlp
    jmp outlp
next:
    inc si
    jmp outlp
done:
    mov dx, offset string
    mov ah, 09h
    int 21h
.exit 0
end