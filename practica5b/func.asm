.model tiny
.code
    public _getchar
    public _putchar
    public _inportb
    public _outportb
    _getchar    PROC
                push bp

                mov bp,sp
                mov ax,0
                mov ah,1
                int 21h

                pop bp
                ret
    _getchar    ENDP

    _putchar    PROC
                push bp
                mov bp,sp
                mov dl, [bp+4]
                mov ah,02h
                int 21h

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
