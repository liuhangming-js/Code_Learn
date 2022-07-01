begin macro
    mov ax, @data
    mov ds, ax
endm
endd macro retnum
    mov al, retnum
    mov ah, 4ch
    int 21h
endm
outp MACRO params
    lea dx, params
    mov ah, 9
    int 21h
endm

.model small
.data
    string db 'Hello!$'
.code
start:
    begin
    outp string
    endd 0
end start
