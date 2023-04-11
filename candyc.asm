include display.inc
include board.inc
include candies.inc
.model small
.stack 100h
.data

nam db 10 dup("$")
entrnam db "Enter your first name$"	
mo db "moves left:$"
na db "player: $"
ta db "target: 20000$"
sc db "current score: $"
WINNING DB "YOU WIN :)$"
LOSING db "GAME OVER :($"

XC DW 11, 76, 142, 209, 276, 343, 410
YC DW 9, 74, 139, 204, 269, 334, 399

file db "instruct.txt",0
buffer dw 5000 DUP ("$")

ARRAY DB 7 DUP(7 DUP(0))

s1 dw 3 dup(0) ;;for swapping storing values temporarily
s2 dw 3 dup(0)
x1 dw 0
y1 dw 0
x_lim dw 0
y_lim dw 0
rows db 0
cols db 0
ro dw 0
co dw 0
temp db 0
temp2 db 0
count dw 0
score dw 0
spw db 0 ;swap: 1 for true, and 0 for false
xt dw 0
yt dw 0
yt_lim dw 0
xt_lim dw 0
moves db 10

.code
mov ax,@data
mov ds,ax

vid macro
;video mode
	mov ah,00h
	mov al,12h
	int 10h
endm

inst macro

mov dx,offset file
mov al,0
mov ah,3dh
int 21h

mov bx,ax
mov dx,offset buffer
mov ah,3Fh
int 21h

mov dx,offset buffer
mov ah,09h
int 21h

endm

main proc

	vid
	
	disp

	vid
	
	inst
	
	mov ah,0
	int 16h
	
	vid
	
	werds
	
	drawbox
	
	drawgrid
	
	
	
	call fill_arr
	call boardpop
	
	
	.while moves>0
	
		
		
	
		call swap
		dec moves
		
		;score output
		mov ah,02h
		mov bx,0
		mov dh, 8	;row number
		mov dl, 75 	;column number
		int 10h
		
		call output
		
		;moves output
		mov ah,02h
		mov bx,0
		mov dh, 4	;row number
		mov dl, 72 	;column number
		int 10h
		
		mov dl, moves
		add dl,48
		mov ah, 02h
		int 21h
		
			
		mov ax,score
		.if ax>=20000
			winpg
			jmp done
		.endif
	.endw
	losepg
	
	done:
	
	;LEVEL 2 BEGINS HERE
;	werds
	
;	drawbox
	
;	drawgrid
	
;	call fill_arr
;	call boardpop
	
;	DRAWLEV2
	
;LEVEL 3 BEGINS HERE

;	werds
	
;	drawbox
	
;	drawgrid
	
;	call fill_arr
;	call boardpop
	
;	DRAWLEV3
	
	call control
ret	
main endp

boardpop proc ;;only for initial board

mov ro,0
mov co,0

.while ro<7
	mov co,0
	.while co<7
	
		call offsett
		mov temp,al
		call candies

		inc co
	.endw
	inc ro
.endw

ret
boardpop endp

offsett proc

	mov ax,ro
	inc ax
	mov bx,7
	mul bx
	sub ax,1
	
	mov bx,6
	sub bx,co
	
	sub ax,bx
	
	mov si,offset array
	add si,ax
	
	mov al,[si]
	
	
	

ret
offsett endp

move proc

	;;;;;;;;add ax and bx with the array position;;;;;;;;
	;;note: add 0 to them if either it is not moving down/up(y) or left/right(x)

	mov ax,co

	mov bx,67 ;for x-axis
	mul bx
	add x1,ax

	mov ax,ro
	mov bx,65 ;for y-axis
	mul bx
	add y1,ax

	ret
move endp

candies proc

	;;;;;;cmp the number/type of candy and then jmp to that label;;;;;;;;
	
	cmp temp,49
	je sqre
	
	cmp temp,54
	je sqre
	
	cmp temp,53
	je bomb
	
	jmp other

	sqre:
		mov x1,19
		mov y1,20

		call move

		mov ax,x1
		add ax,44
		mov x_lim,ax
		mov ax,y1
		add ax,43
		mov y_lim,ax
		
		.if temp==49
			drawsquare
		.endif
		
		.if temp==54
			swapsqr
		.endif
	jmp endc

	bomb:
		mov count,0
		mov x1,21
		mov y1,20

		call move

		mov ax,x1
		add ax,36
		mov x_lim,ax
		mov ax,y1
		add ax,35
		mov y_lim,ax

		drawbomb
	jmp endc


	other:
		;;;;if hexa, tear or diamond
		mov x1,41
		mov y1,20

		call move

		mov ax,x1
		mov x_lim,ax
		mov ax,y1
		mov y_lim,ax

		cmp temp,50
		je H
		
		cmp temp,51
		je T
		
		cmp temp,52
		je D
		
		H:
		drawhex
		jmp endc
		
		T:
		drawtear
		jmp endc
		
		D:
		drawdiamond
		jmp endc


	endc:
	ret
candies endp



delayy proc
	mov cx, 1000000
	mov dx, 1000000
	time_waste:
		tw:
		cmp dx,0
		je escc
		
		dec dx
		jmp tw
		
		escc:
				
	 loop time_waste
ret
delayy endp

	;filling array with randos
randos proc

	mov ah, 00h  ; interrupts to get system time        
	int 1ah   
	   
	mov  ax, dx
	xor  dx, dx
	mov  cx, 4    
	div  cx       ; here dx contains the remainder of the division from 1 to 4

	add  dl, '1'  ; to ascii from '1' to '4'
		
ret
randos endp

fill_arr proc

	mov si, offset array
	mov count, 49
	lv1:
	cmp count, 0
	je leave1

	call randos
	mov [si], dl


	mov dl ,0
	inc si
	dec count

	call delayy
	
		
	jmp lv1


leave1:
ret
fill_arr endp

swap proc

	mov ax,0
	int 33h

	mov ax,1
	int 33h
	
	restrictmouse
	
	;click 1

	call mose 
	call offsett
	mov temp,al
	mov di,offset s1
	mov [di],si
	add di,2
	mov ax,ro
	mov [di],ax
	add di,2
	mov ax,co
	mov [di],ax
	
	;click 2

	call mose 
	call offsett
	mov temp2,al
	mov di,offset s2
	mov [di],si
	add di,2
	mov ax,ro
	
	mov [di],ax
	add di,2
	mov ax,co

	mov [di],ax
	
	mov ax,2
	int 33h

	
	
	call adjacent
	
	

ret
swap endp

mose proc


	aga:
	mov ax,5
	int 33h

	cmp bx,1
	je plc
	jmp aga

	plc:
	mov ax,3
	int 33h
	mov x1,cx
	mov y1,dx

	mov ro,-1
	mov co,-1

	mov di, offset yc
	mov si, offset xc
	mov ax,[si]
	mov bx,[di]

	.while ax<x1
			add si,2
			mov ax,[si]
			inc co
	
		.endw

	.while bx<y1
		
		add di,2
		mov bx,[di]
		inc ro
	.endw
	
	
	add co,48
	.if co=='='
		mov co,54
	.endif
	sub co,48


ret
mose endp



adjacent proc

mov si,offset s1
mov di,offset s2
mov ax,[si]
sub ax,[di]

.if ax==-1 || ax==1 || ax==7 || ax==-7
       
	
	call swapcoor
	
	
	mov temp,54
	call candies
	
	call offsett
	mov temp2,al
	
	mov si,offset s2
	call swapcoor
	

	mov temp,54
	call candies 
	
	
	call offsett
	mov temp,al
	mov al,temp2
	mov [si],al
	
	mov di,offset s1
	mov si,[di]
	
	mov al,temp
	mov [si],al
	
	mov si,offset s1
	
	
	call swapcoor

	call offsett
	mov temp,al
	call candies
	
	
	mov si,offset s2
	call swapcoor
	

	call offsett
	mov temp,al
	call candies
	
	
	call combosall
	call dropdown
	
	.if spw ==0
		mov si,offset s1
		mov di,[si]
		mov si,offset s2
		mov bx,[si]
		
		mov al,[di]
		mov cl,[bx]
		
		mov [bx],al
		mov [di],cl
		
		call dropdown
		drawbox
		drawgrid
		call boardpop
		
	.endif
	
	.while spw==1

		mov spw,0
		call combosall
		
		call dropdown
		
	.endw	
		drawbox
		drawgrid
		call boardpop
	
.endif

ret
adjacent endp

combosall proc
	
	mov ro,0
	
	.while ro<7
		mov co,0
		.while co<5
			mov cx,co

			call combohor

			mov co,cx
			inc co
		.endw
		inc ro
	.endw
	
	mov co,0
	
	.while co<7
		mov ro,0
		.while ro<5
			mov cx,ro

			call combover
			
			mov ro,cx
			inc ro
		.endw
		inc co
	.endw
	
ret
combosall endp

swapcoor proc

	add si,2
	mov ax,[si]
	mov ro,ax
	add si,2
	mov ax,[si]
	mov co,ax

ret
swapcoor endp

combohor proc

	mov count,1
	
	
	call offsett
	mov temp,al

	;forward combo
	.if co<6
	inc co
	inc si
	mov bl,[si]

		.while temp==bl && co<7
			inc count
			inc co
			inc si
			mov bl,[si]
			
			
		.endw
	.endif
	
	cmp count,3
	jb back
	

		mov ax,count
		mov bl,temp ;temp has candy number, so count is multiplied by candy number
		mul bl
		add score,ax
		mov spw,1
		
		dec si
		.while count>0
			mov al,54
			mov [si],al
			dec si
			dec count
			
		.endw
			
	jmp redo
	
	;backward combo
	back:
		mov count,0
		.if co>0
			dec co
			dec si
			mov bl,[si]

			.while temp==bl && co>=0
				inc count
				dec co
				dec si
				mov bl,[si]
				mov dx,count
			.endw
	.endif
		

	
	.if count>=3
		mov ax,count
		mov bl,temp ;temp has candy number, so count is multiplied by candy number
		mul bl
		add score,ax
		
		mov spw,1 ;swap=true
		
		inc si
		.while count>0
			mov al,54
			mov [si],al
			inc si
			dec count
			
			
		.endw
			
	.endif

	redo:
	
ret
combohor endp

combover proc

	mov count,1
	
	
	call offsett
	mov temp,al

	;downward combo
	.if ro<7
	inc ro
	add si,7
	mov bl,[si]

		.while temp==bl && ro<7
			inc count
			inc ro
			add si,7
			mov bl,[si]

			
		.endw
	.endif
	
	cmp count,3
	jb back
	

		mov ax,count
		mov bl,temp ;temp has candy number, so count is multiplied by candy number
		mul bl
		add score,ax
		
		mov spw,1
		
		dec si
		.while count>0
			mov al,54
			mov [si],al
			sub si,7
			dec count

		.endw
			
	jmp redo
	
	;upward combo
	back:
		mov count,0
		.if ro>0
			dec ro
			sub si,7
			mov bl,[si]

			.while temp==bl && ro>=0
				inc count
				dec ro
				sub si,7
				mov bl,[si]
				mov dx,count
			.endw
	.endif
		

	
	.if count>=3
		mov ax,count
		mov bl,temp ;temp has candy number, so count is multiplied by candy number
		mul bl
		add score,ax
		
		mov spw,1
		
		add si,7
		.while count>0
			mov al,54
			mov [si],al
			add si,7
			dec count
			
			
		.endw
			
	.endif

	redo:

ret
combover endp

dropdown proc

	mov ro,6
	mov co,6

	call offsett
	
	.while ro>0
		mov co,0
		mov bx,ro
		mov temp2,bl
		.while co<7
			mov al,[si]
			.if al==54 ;meaning no candy
				mov bx,si
				mov di,bx
				sub di,7
				dec temp2
				mov al,[di]
				.while al==54
					sub di,7
					dec temp2
					.if temp2==0
						call randos
						mov [si],dl
						call delayy
						je stp
					.endif
				.endw
				mov al,[di]
				mov bl,54
				mov [di],bl
				mov [si],al
			stp:
			.endif
			dec si
			inc co
			
		.endw
		dec ro
	.endw	
	
	mov ro,0
	mov co,0
	call offsett	
	.while co<7
		mov al,[si]

		.if al==54
			call randos
			mov [si],dl
			call delayy
		.endif
		inc co
		inc si
	.endw
	
ret
dropdown endp

output proc
mov count,0
mov ax,score
mov dx,0
outp:
cmp ax,0
je display

mov bx,10
div bx

mov cx,dx


push cx

mov dx,0
;mov ans,al
inc count

jmp outp

display:
cmp count,0
je endout

pop dx
add dx, 48
mov ah, 02h
int 21h

dec count

jmp display

endout:
ret
output endp


;control
control proc

	mov ah,4ch
	int 21h
	
control endp

end