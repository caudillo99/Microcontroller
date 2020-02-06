.model tiny
;----- Insert INCLUDE "filename" directives here
;----- Insert EQU and = equates here
locals
.data
  new_line DB 10,13,0
.code
  org 100h

  ;***********************************************
  ; Procedimiento principal
  ;***********************************************
        main            proc
                        mov sp, 0fffh       ; inicializa SP
                        mov ax, -1234       ; numero a invertir
                        call printNumBase   ; print the number in AX
                        push ax             ; save temporary AX onto stack
                        mov al,'-'
                        call putchar
                        mov al,'>'
                        call putchar
                        pop ax              ; remove AX from the stack
                        call reverse        ; call the reverse procedure, which flips a number that was stored in AX
                        mov ax,dx           ; the procedure returns in DX the flipped number.
                        call printNumBase   ; print the flipped number
                      @@here:               ; the program never ends
                        jmp @@here
                        ret
                        endp

  ;***********************************************
  ; Procedimiento
  ;***********************************************
        reverse         proc
                        push bx             ; save the register
                        push ax
                        push cx
                        test ax,8000h       ; check if the number is negative
                        jns @@no_sign       ; if No Sign flag is activated then jumps to convert the number
                        xor ax, 0FFFFh      ; if the number is negative,
                        inc ax              ; we're gonna apply the 2's complements
                      @@no_sign:
                        xor cx,cx           ; we're gonna take CX as auxiliary
                        mov bx,10           ; BX is the multiplier and divider
                      @@proc1:
                        idiv bx             ; we divide the number in 10, then we're use
                        add cx, dx
                        xor dx, dx
                        cmp cx, 7fffh     ; check if the number is greater than the maximum capacity of the signed 16-bits register
                        jo @@overflow
                        cmp ax,0          
                        je @@end
                        push ax
                        mov ax, cx
                        imul bx
                        mov cx,ax
                        pop ax
                        jmp @@proc1
                      @@end:
                        mov dx, cx
                      @@overflow:
                        pop cx
                        pop ax
                        pop bx
                        ret
                        endp
    ;***********************************************
    ; Procedimiento que imprime un caracter guardado en AL
    ;***********************************************
        putchar         proc
                        push ax
                        push dx
                        mov dl,al
                        mov ah,2        ; imprimir caracter DL
                        int 21h         ; usando servicio 2 (ah=2)
                        pop dx          ; del int 21h
                        pop ax
                        ret
                        endp

    ;***********************************************
    ; Procedimiento que imprime el numero guardado en AX
    ;***********************************************
        printNumBase    proc
                        push bx
                        push ax
                        push cx
                        push dx
                        ;4f7A
                        test ax,8000h
                        jns @@no_sign
                        xor ax, 0FFFFh
                        inc ax
                        push ax
                        mov al, '-'
                        call putchar
                        pop ax
                      @@no_sign:
                        mov cx,0        ; Variable que nos sirve de contador
                        mov bx , 10		  ; base modificable
                      @@no_zero:
                        xor dx,dx       ; Es equivalente a mov dx,0 y nos aseguramos que no nos vaya a cambiar el numero
                        div bx          ; Se realiza la divison
                        push dx         ; Guardamos el residuo de la division
                        inc cx          ; Se incrementa cx, cada vez que se realice la operacion anterior
                        or ax,ax        ; verificamos si ax, ha llegado a 0
                        jne @@no_zero   ; Realiza el salto si no es cero, lo cual indica que aun no termina la operacion
                      @@convierte:
                        pop ax          ; Sacamos el resultado en DX
                        add ax,'0'
                        cmp ax,39h      ; se le suma 30h para que inicie del 0 en ascii
                        jbe l1
                        add ax,7h
                      l1:
                        call putchar
                        loop @@convierte; realiza pop la  cantidad de veces en cx, para acomodar los numeros correctamente
                        pop dx
                        pop cx
                        pop ax
                        pop bx
                        ret
                        endp

        getch	          proc
                        push ax
                      	mov ah,8				; no echo
                      	int 21h
                        pop ax
                      	ret
                      	endp
   ;***********************************************
   ; Procedimiento principal
   ;***********************************************
        puts	          proc
                      	push ax
                      	push bx
                      	mov  bx,dx
                      @@nxt:
                      	mov  al,[bx]
                      	cmp  al,0
                      	je   @@end
                      	call putchar
                      	inc  bx
                      	jmp  @@nxt
                      @@end:
                      	pop  bx
                      	pop  ax
                      	ret
                      	endp
END main
