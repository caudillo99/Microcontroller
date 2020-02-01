.model tiny
;----- Insert INCLUDE "filename" directives here
;----- Insert EQU and = equates here
locals
.data
  aux DB 0
.code
  org 100h

;***********************************************
; Procedimiento principal
;***********************************************
  main  proc
        mov sp, 0fffh   ; inicializa SP
        mov ax, 123     ; numero a invertir
        mov bx,10       ; divider

      @@proc1:
        idiv bx        ; remainder is stored in DX
        add aux, dx
        xor dx,dx
        cmp ax,0
        jz @@end
        push ax
        mov ax, aux
        imul bx
        pop ax
        mov aux,dx
        jmp @@proc1
      @@end:
        jo @@overflow
        mov dx, aux
      @@overflow:
        jmp @@overflow
        ret
        endp

putchar proc
        push ax
        push dx
        mov dl,al
        mov ah,2 ; imprimir caracter DL
        int 21h ; usando servicio 2 (ah=2)
        pop dx ; del int 21h
        pop ax
        ret
        endp
  end   main
