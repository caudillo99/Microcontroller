.model tiny
.code
    public _getchar
    public _putchar
    public _peek
    public _poke
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
    ;unsigned char peek(unsigned int segment, unsigned int offset)
    _peek       PROC
                push bp 
                push ds 
                push bx 
                mov bp, sp
                mov ds, [bp+8]  ; segment
                mov bx, [bp+10] ;offset
                mov al, [bx]        
                pop bx
                pop ds
                pop bp
                ret
    _peek       ENDP

    ;void poke(unsigned int segment, unsigned int offset, unsigned char data)
    _poke       PROC
                push bp
                push ds
                push bx
                push dx
                mov bp,sp
                xor dx,dx
                mov ds, [bp+10] ;segment
                mov bx, [bp+12] ;offset
                mov dl, [bp+14] ;data
                mov [bx], dl
                pop dx
                pop bx
                pop ds
                pop bp
                ret
    _poke       ENDP
END
