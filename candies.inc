drawbomb macro
  mov ax,y1
  mov yt,ax
  mov ax,x1
  mov xt,ax
  mov ax,y_lim
  mov yt_lim,ax
  mov ax,x_lim
  mov xt_lim,ax

	repet:
		mov dx,yt
		mov cx,xt
		add cx,10
		.while cx>xt
		mov ah,0ch
		mov al,01h
		int 10h
		inc dx
		dec cx
		.endw
		
		
		.while dx<yt_lim
		mov ah,0ch
		mov al,09h
		int 10h
		inc dx
		.endw
		
		add xt,10
		.while cx<xt
		mov ah,0ch
		mov al,00h
		int 10h
		inc dx
		inc cx
		.endw
		
		mov dx,yt
		.while cx<xt_lim
		mov ah,0ch
		mov al,0eh
		int 10h
		inc cx
		.endw
		
		add xt_lim,10
		.while cx<xt_lim
		mov ah,0ch
		mov al,0ah
		int 10h
		inc cx
		inc dx
		.endw

		.while dx<yt_lim
		mov ah,0ch
		mov al,0bh
		int 10h
		inc dx
		.endw
		
		sub xt_lim,10
		.while cx>xt_lim
		mov ah,0ch
		mov al,0ch
		int 10h
		inc dx
		dec cx
		.endw
		
		add yt_lim,10
		mov dx,yt_lim
		mov cx,xt
		.while cx<=xt_lim
		mov ah,0ch
		mov al,0dh
		int 10h
		inc cx
		.endw
			
	inc count
	mov bx,count
	  mov ax,y1
	  mov yt,ax
	  mov ax,x1
	  mov xt,ax
	  mov ax,y_lim
	  mov yt_lim,ax
	  mov ax,x_lim
	  mov xt_lim,ax   
	add xt,bx
	add yt,bx
	sub xt_lim,bx
	sub yt_lim,bx
	
	cmp count, 10
	
	jne repet
			
				
endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

drawdiamond macro
	
	mov cx, x1
	mov dx, y1
	add y_lim,10
	
	.while dx<= y_lim
	
	 .while cx<=x_lim
		mov ah, 0ch
		mov al, 0ah
		mov bh, 0
		inc cx
		
		int 10h
	 .endw
		
	 add x_lim, 1
	 inc dx
	 sub x1, 1
	 mov cx, x1
	
	.endw
	
	;vertical lines
	mov cx, x1
	add y_lim, 20
	
	.while dx<=y_lim

	 .while cx<=x_lim
		mov ah, 0ch
		mov al, 0ah
		mov bh, 0
		inc cx
		int 10h
	 .endw

	 mov cx, x1
	 inc dx
	 
	.endw

	mov cx, x1
	add y_lim, 12
	
	.while dx<= y_lim
	
	 .while cx<=x_lim
		mov ah, 0ch
		mov al, 0ah
		mov bh, 0
		inc cx
		
		int 10h
	 .endw
		
	 sub x_lim, 1
	 inc dx
	 add x1, 1
	 mov cx, x1
	 
	.endw
	
endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

drawsquare macro

	; vertical lines
	mov cx, x1
	mov dx, y1

	
	.while dx<=y_lim

		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0Ch
		mov bh, 0
		inc cx
		int 10h
		.endw

	mov cx, x1
	inc dx
	.endw

endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

drawtear macro
    mov cx, x1
	mov dx, y1
	add y_lim, 20
	
	.while dx<= y_lim
	
		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0eh
		mov bh, 0
		inc cx
		
		int 10h
		.endw
	add x_lim, 1
	inc dx
	sub x1, 1
	mov cx, x1
	
	.endw
	
	; vertical lines
	mov cx, x1
	add y_lim, 10
	
	.while dx<=y_lim

		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0eh
		mov bh, 0
		inc cx
		int 10h
		.endw

	mov cx, x1
	inc dx
	.endw

	mov cx, x1
	add y_lim, 12
	
	.while dx<= y_lim
	
		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0eh
		mov bh, 0
		inc cx
		
		int 10h
		.endw
	sub x_lim, 1
	inc dx
	add x1, 1
	mov cx, x1
	
	.endw


endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

drawhex macro
	
	mov cx, x1
	mov dx, y1
	add y_lim,10
	
	.while dx<= y_lim
	
		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0bh
		mov bh, 0
		inc cx
		
		int 10h
		.endw
	add x_lim, 2
	inc dx
	sub x1, 2
	mov cx, x1
	
	.endw
	
	; vertical lines
	mov cx, x1
	add y_lim, 20
	
	.while dx<=y_lim

		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0bh
		mov bh, 0
		inc cx
		int 10h
		.endw

	mov cx, x1
	inc dx
	.endw

	mov cx, x1
	add y_lim, 12
	
	.while dx<= y_lim
	
		.while cx<=x_lim
		mov ah, 0ch
		mov al, 0bh
		mov bh, 0
		inc cx
		
		int 10h
		.endw
	sub x_lim, 2
	inc dx
	add x1, 2
	mov cx, x1
	
	.endw
	
endm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;

swapsqr macro

	; vertical lines
	mov cx, x1
	mov dx, y1

	
	.while dx<=y_lim

		.while cx<=x_lim
		mov ah, 0ch
		mov al, 07h
		mov bh, 0
		inc cx
		int 10h
		.endw

	mov cx, x1
	inc dx
	.endw

endm