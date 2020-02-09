.model tiny
.code
    public _getchar
    _getchar    PROC
                push bp

                mov bp,sp
                mov ax,0
                mov ah,1
                int 21h

                pop bp
                ret
    _getchar    ENDP

    public _putchar
    _putchar    PROC
                push bp

                mov bp,sp
                mov dl, [bp+4]
                mov ah,02h
                int 21h

                pop bp
                ret
    _putchar    ENDP
END
