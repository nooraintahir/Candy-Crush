
	drawlineh macro		; for drawing horizontal line

		mov cx, x1
		mov dx, y1
		
			.while cx<=x_lim
				mov ah, 0ch
				mov al, 00h		;color number
				mov bh, 0
				inc cx
				int 10h
			.endw

	endm

	drawlinev macro			; for drawing vertical line

		mov cx, x1
		mov dx, y1
		
			.while dx<=y_lim
				mov ah, 0ch
				mov al, 00h		;color number
				mov bh, 0
				inc dx
				int 10h
			.endw

	endm


	drawgrid macro
		
		;the horizontal lines
		
				mov x1, 9
				mov y1, 8
				mov x_lim, 474
				drawlineh			
	
				mov x1, 9
				mov y1, 73
				mov x_lim, 474
				drawlineh
				
				mov x1, 9
				mov y1, 138
				mov x_lim, 474
				drawlineh
				
				mov x1, 9
				mov y1, 203
				mov x_lim, 474
				drawlineh
				
				mov x1, 9
				mov y1, 268
				mov x_lim, 474
				drawlineh
				
				mov x1, 9
				mov y1, 333
				mov x_lim, 474
				drawlineh
				
				mov x1, 9
				mov y1, 398
				mov x_lim, 474
				drawlineh
			
				mov x1, 9
				mov y1, 463
				mov x_lim, 474
				drawlineh
								
			;the vertical lines
				mov x1, 10
				mov y1, 8
				mov y_lim, 462
				drawlinev
			
				mov x1, 75
				mov y1, 8
				mov y_lim, 462
				drawlinev
				
				mov x1, 141
				mov y1, 8
				mov y_lim, 462
				drawlinev

				mov x1, 208
				mov y1, 8
				mov y_lim, 462
				drawlinev

				mov x1, 275
				mov y1, 8
				mov y_lim, 462
				drawlinev

				mov x1, 342
				mov y1, 8
				mov y_lim, 462
				drawlinev

				mov x1, 409
				mov y1, 8
				mov y_lim, 462
				drawlinev
				
				mov x1, 475
				mov y1, 8
				mov y_lim, 462
				drawlinev 
						
	endm

	
	drawbox macro
			mov cx, 9
			mov dx, 8
			.while dx<=463

				.while cx<=473
				mov ah, 0ch
				mov al, 07h
				mov bh, 0
				inc cx
				int 10h
				.endw

			mov cx, 9
			inc dx
			.endw
		

	endm
	
	
	werds macro
		

		
		mov rows,2
		mov cols, 61
		mov si, 0
		mov si, offset na
		werd
		
		mov rows,2
		mov cols, 68
		mov si, 0
		mov si, offset nam
		werd
		
		mov rows,4
		mov cols, 61
		mov si, 0
		mov si, offset mo
		werd
		
		mov rows,6
		mov cols, 61
		mov si, 0
		mov si, offset ta
		werd
		
		mov rows,8
		mov cols, 61
		mov si, 0
		mov si, offset sc
		werd

	endm
	
	werd macro
		mov ah,02h
		mov bx,0
		mov dh, rows 	;row number
		mov dl, cols 	;column number
		int 10h
		
		mov dx, si
		mov ah, 09h
		int 21h
	
	endm
	
	DRAWCOVER MACRO
			mov cx, X1
			mov dx, Y1
			.while dx<=Y_LIM

				.while cx<=X_LIM
				mov ah, 0Ch
				mov al, 00h
				mov bh, 0
				inc cx
				int 10h
				.endw

			mov cx, X1
			inc dx
			.endw
	ENDM

	DRAWLEV3 MACRO
				
				MOV X1, 208
				MOV Y1, 9
				MOV Y_LIM, 462
				MOV X_LIM, 273
				DRAWCOVER
	
				MOV X1, 10
				MOV Y1, 204
				MOV Y_LIM, 267
				MOV X_LIM, 473
				DRAWCOVER

	ENDM

	DRAWLEV2 MACRO
				MOV X1, 10
				MOV Y1, 9
				MOV Y_LIM, 72
				MOV X_LIM, 73
				DRAWCOVER
				
				MOV X1, 10
				MOV Y1, 73
				MOV Y_LIM, 137
				MOV X_LIM, 73
				DRAWCOVER
				
				MOV X1, 208
				MOV Y1, 9
				MOV Y_LIM, 72
				MOV X_LIM, 273
				DRAWCOVER
				
				MOV X1, 208
				MOV Y1, 399
				MOV Y_LIM, 462
				MOV X_LIM, 273
				DRAWCOVER
				
				MOV X1, 10
				MOV Y1, 204
				MOV Y_LIM, 267
				MOV X_LIM, 73
				DRAWCOVER
				
				MOV X1, 409
				MOV Y1, 204
				MOV Y_LIM, 267
				MOV X_LIM, 473
				DRAWCOVER
				
				MOV X1, 10
				MOV Y1,334
				MOV Y_LIM, 462
				MOV X_LIM, 73
				DRAWCOVER
				
				MOV X1, 409
				MOV Y1, 334
				MOV Y_LIM, 462
				MOV X_LIM, 473
				DRAWCOVER
				
				MOV X1, 409
				MOV Y1, 9
				MOV Y_LIM, 137
				MOV X_LIM, 473
				DRAWCOVER

	ENDM
	
RESTRICTMOUSE MACRO
	
		mov ax, 7
		mov cx, 9 ; min pos
		mov dx, 473 ; max pos
		int 33h

		mov ax, 8
		mov cx, 8
		mov dx, 463
		int 33h	

ENDM

WINPG macro
	vid
	
			mov cx, 9
			mov dx, 8
			.while dx<=470

				.while cx<=630
				mov ah, 0Ch
				mov al, 0Ah
				mov bh, 0
				inc cx
				int 10h
				.endw

			mov cx, 9
			inc dx
			.endw
			
		
		
		MOV ROWS,14
		MOV COLS, 34
		MOV SI, 0
		MOV SI, OFFSET winning
		werd
		
endm

LOSEPG macro
	vid
	
			mov cx, 9
			mov dx, 8
			.while dx<=470

				.while cx<=630
				mov ah, 0Ch
				mov al, 0Ch
				mov bh, 0
				inc cx
				int 10h
				.endw

			mov cx, 9
			inc dx
			.endw
			
		
		
		MOV ROWS,14
		MOV COLS, 34
		MOV SI, 0
		MOV SI, OFFSET losing
		werd
		
endm
	



