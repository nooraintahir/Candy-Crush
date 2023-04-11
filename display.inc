disp macro

;LETTER C
mov cx,70
mov dx,100

.while cx<90
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
.endw

mov cx,70
mov dx,100
.while cx>50
mov ah,0Ch
mov al,0Dh
int 10h
dec cx
inc dx
.endw

.while dx<140
mov ah,0Ch
mov al,0Dh
int 10h
inc dx
.endw

.while cx<71
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
inc dx
.endw

mov cx,70

.while cx<90
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
.endw


;LETTER A

mov cx,100
mov dx,161

.while dx>120
mov ah,0Ch
mov al,0Eh
int 10h
dec dx
.endw

mov dx,120
.while dx>105
mov ah,0Ch
mov al,0Eh
int 10h
inc cx
dec dx
.endw

mov dx,161
mov cx, 130

.while dx>120
mov ah,0Ch
mov al,0Eh
int 10h
dec dx
.endw

mov dx,120
.while dx>104
mov ah,0Ch
mov al,0Eh
int 10h
dec cx
dec dx
.endw

mov dx,140
mov cx,100
.while cx<130
mov ah,0Ch
mov al,0Eh
int 10h
inc cx
.endw

;LETTER N

mov cx,140
mov dx,105

.while dx<163
mov ah,0Ch
mov al,0Ch
int 10h
inc dx
.endw

mov cx,140
mov dx,105

.while cx<170
mov ah,0Ch
mov al,0Ch
int 10h
inc dx
inc cx
.endw

mov cx,170
mov dx,105

.while dx<163
mov ah,0Ch
mov al,0Ch
int 10h
inc dx
.endw

;LETTER D
mov cx,180
mov dx,105

.while dx<163
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
.endw

mov cx,180
mov dx,105

.while cx<200
mov ah,0Ch
mov al,0Bh
int 10h
inc cx
.endw

.while cx<215
mov ah,0Ch
mov al,0Bh
int 10h
inc cx
inc dx
.endw

.while dx<150
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
.endw

mov cx,180
mov dx,163

.while cx<200
mov ah,0Ch
mov al,0Bh
int 10h
inc cx
.endw

.while cx<215
mov ah,0Ch
mov al,0Bh
int 10h
inc cx
dec dx
.endw

;LETTER Y

mov cx,220
mov dx,105

.while cx<240
mov ah,0Ch
mov al,0Ah
int 10h
inc cx
inc dx
.endw

mov cx,260
mov dx,105

.while cx>240
mov ah,0Ch
mov al,0Ah
int 10h
dec cx
inc dx
.endw

mov cx,240
mov dx,125

.while dx<165
mov ah,0Ch
mov al,0Ah
int 10h
inc dx
.endw

;LETTER C
mov cx,340
mov dx,100

.while cx<360
mov ah,0Ch
mov al,0Eh
int 10h
inc cx
.endw

mov cx,340
mov dx,100
.while cx>320
mov ah,0Ch
mov al,0Eh
int 10h
dec cx
inc dx
.endw

.while dx<142
mov ah,0Ch
mov al,0Eh
int 10h
inc dx
.endw

.while cx<341
mov ah,0Ch
mov al,0Eh
int 10h
inc cx
inc dx
.endw

mov cx,341

.while cx<360
mov ah,0Ch
mov al,0Eh
int 10h
inc cx
.endw

;LETTER R

mov cx,370
mov dx,105

.while dx<164
mov ah,0Ch
mov al,0Ch
int 10h
inc dx
.endw

mov cx,370
mov dx,105

.while cx<390
mov ah,0Ch
mov al,0Ch
int 10h
inc cx
.endw

.while cx<395
mov ah,0Ch
mov al,0Ch
int 10h
inc cx
inc dx
.endw

.while dx<131
mov ah,0Ch
mov al,0Ch
int 10h
inc dx
.endw

mov cx,370
mov dx,135

.while cx<390
mov ah,0Ch
mov al,0Ch
int 10h
inc cx
.endw

.while cx<395
mov ah,0Ch
mov al,0Ch
int 10h
inc cx
dec dx
.endw

mov cx,380
mov dx,135
.while dx<163
mov ah,0Ch
mov al,0Ch
int 10h
inc cx
inc dx
.endw

;LETTER U

mov cx,410
mov dx,105

.while dx<154
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
.endw

.while dx<163
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
inc cx
.endw

mov cx,440
mov dx,105

.while dx<154
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
.endw

.while dx<163
mov ah,0Ch
mov al,0Bh
int 10h
inc dx
dec cx
.endw

mov cx,419
mov dx,163

.while cx<433
mov ah,0Ch
mov al,0Bh
int 10h
inc cx
.endw

;LETTER S

mov cx,465
mov dx,105

.while cx<490
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
.endw

mov cx,465
mov dx,105

.while cx>454
mov ah,0Ch
mov al,0Dh
int 10h
dec cx
inc dx
.endw


.while dx<123
mov ah,0Ch
mov al,0Dh
int 10h
inc dx
.endw


.while cx<465
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
inc dx
.endw

mov cx,465

.while cx<480
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
.endw

.while cx<490
mov ah,0Ch
mov al,0Dh
int 10h
inc cx
inc dx
.endw

.while dx<153
mov ah,0Ch
mov al,0Dh
int 10h
inc dx
.endw

.while cx>480
mov ah,0Ch
mov al,0Dh
int 10h
dec cx
inc dx
.endw


.while cx>455
mov ah,0Ch
mov al,0Dh
int 10h
dec cx
.endw

;LETTER H

mov cx,500
mov dx,105

.while dx<165
mov ah,0Ch
mov al,09h
int 10h
inc dx
.endw

mov cx,530
mov dx,105

.while dx<165
mov ah,0Ch
mov al,09h
int 10h
inc dx
.endw

mov cx,500
mov dx,135

.while cx<531
mov ah,0Ch
mov al,09h
int 10h
inc cx
.endw

;displaying enter your name
mov ah,02h
mov bx,0
mov dh, 15
mov dl, 25
int 10h

mov dx,offset entrnam
mov ah,09h
int 21h

;input name
mov ah,02h
mov bx,0
mov dh, 16
mov dl, 25
int 10h

	mov si,offset nam
innam:
	mov ah,01h
	int 21h
	mov [si],al
	inc si
	cmp al,13
jne innam


endm