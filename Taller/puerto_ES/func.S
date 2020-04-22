; ALUMNO: Caudillo Sanchez Diego 
; MATRICULA: 1249199
; Taller- Puerto E/S (Tx Serie)
; FECHA DE ENTREGA : 22/04/2020
.global TXoPin ; hace visible el procedimiento para ser llamada en C.

; void TXoPin(uint8_t data);
TXoPin:
	LDI 	R18,	1
	CBI		0X05,	7		; START BIT
	CALL 	delay104us
NEXT:
	LSL 	R18
	MOV 	R19, 	R24		; Copia el parametro a R19
	AND 	R19, 	R18 	; AND con la mascara en R18
	BREQ 	CLR_BIT			; Revisa si la bandera Z es 0 o 1
	SBI 	0x05, 	7 		; SET al PB7
	JMP 	CHECK
CLR_BIT:		
	CBI 	0x05, 	7		; CLEAR al PB7
	NOP
	NOP						; 2 NOP para compensar el tiempo del salto "JMP CHECK"
CHECK:
	CALL 	delay104us		; TIEMPO DE ESPERA PARA ENVIAR EL DATO
	CPI 	0x80, 	R18		; Verifica si ha terminado de escribir todos los bits
	BRNE 	NEXT
	SBI		0X05,	1		; STOP BIT
	CALL 	delay104us
	RET	


/**********************************/
/* Delay para escritura al puerto */
/**********************************/
delay104us:
	LDI R16,59
loop1: 
	LDI R17, 6
loop2:
	NOP
	DEC R17
	BRNE loop2

	DEC R16
	BRNE loop1
	RET
