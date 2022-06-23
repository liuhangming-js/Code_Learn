.model small
.stack
.data
array db 2h,3h,4h,5h,6h,7h,8h
.code
.startup
mov cx, 7
mov bx, offset array
again: dec byte ptr [bx]
inc bx
loop again
.exit 0
end