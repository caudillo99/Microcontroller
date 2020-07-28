; Alumno: Diego Caudillo Sanchez
; Matricula: 1249199
; Ejercicio: procedimiento WriteBit
; Materia: Microcontroladores y Microprocesadores
; Docente: Dr. Leocundo Aguilar Noriega
; Fecha de entrega: 26/06/2020

.model tiny
.code
    public _writeBit
    ; void writeBit(uint8_t *dato, uint8_t num, uint8_t valor_bit)
    _writeBit   PROC
                push bp                 ; Salvar los registros
                push bx
                push ax
                push dx
                
                mov bp, sp
                mov bx, [bp+10]         ; pointer to data
                mov cl, [bp+12]         ; num; utiiza solo la parte baja debido a solo puede modificar 8 bits (0-7) solo 3-bits bastan.
                mov dl, [bp+14]         ; valor_bit
                mov al,1                ; mask
                
                shl al, cl              ; identifica el bit que se quiere escribir
                mov ah, byte ptr[bx]    ; trae el dato, solo utiliza 8-bits
                cmp dl, 0               ; Si es 1, entonces usamos OR para escribir el dato 
                jz @@clr_bit       
                or ah, al               ; Operación OR con la mascara y el valor de 'data', para setear el bit.
                jmp @@end
            @@clr_bit:                  ; Si el valor del bit es 1 usamos AND para apagar el bit
                not al                  ; invierte el valor para posicionar el 0 en la ubicacoión correcta.
                and ah, al              ; se realiza la mascara con AND el valor de 'data', para borrar el bit.
            @@end:
                mov byte ptr[bx], ah    ; escribe el dato en el contenido de la dirección de memoria.
                pop dx
                pop ax
                pop bx
                pop bp
                ret
    _writeBit   ENDP
END