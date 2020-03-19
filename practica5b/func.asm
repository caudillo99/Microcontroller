.model tiny
.code
    public _getch
    public _putchar
    public _inportb
    public _outportb
    public _clrscr

    _clrscr     PROC
                push bp
                
                mov bp,sp
                mov al,07h
                mov ah, 05h
                int 10h
                
                pop bp
                ret
    _clrscr     ENDP

    _getch      PROC
                push bp

                mov bp,sp
                mov ax,0
                mov ah,1
                int 21h

                pop bp
                ret
    _getch      ENDP

    _putchar    PROC
                push bp
		        push dx
		        push ax

		        mov bp,sp
		        mov dl,[bp + 8]
		        mov ah,02
		        int 21h

		        pop ax
		        pop dx
		        pop bp
		        ret
    _putchar    ENDP
    
    ;extern void outportb(WORD port, BYTE dato);
    _outportb   PROC
                push bp
                mov bp,sp
                mov dx, [bp+4]
                mov al, [bp+6]
                out dx, al
                pop bp
                ret
    _outportb   ENDP
    
    ;extern BYTE inportb(WORD port);
    _inportb    PROC
                push bp
                mov bp,sp
                mov dx, [bp+4]
                in al, dx
                pop bp
                ret
    _inportb    ENDP

END
