.INCLUDE "m2560def.inc"
.EQU INIT_VALUE = 0x80

.def A = R16
.def B = R17
.def C = R18
.def D = R19
;--------------init PORTS-----------------------------------
	LDI R24, INIT_VALUE
	OUT DDRB, R24

;--------------MAIN LOOP---------------------------------
NEXT:
	;****Llamar retardo ****
	;CALL DELAY103us
	;CALL DELAY100ms
	;CALL DELAY1seg
	OUT PINB, R24
	
	RJMP NEXT
	
DELAY103us:
		LDI 	A,182
delay1:
		LDI 	B, 1
delay2:
		DEC 	B
		NOP             
		BRNE 	delay2
		DEC 	A
		NOP
		NOP
		BRNE 	delay1
		RET

;******************* Delay 100ms *******************
DELAY100ms:
	LDI 	A, 190
J1:
	LDI 	B, 122
J2:
	LDI		C, 11
J3:	
	NOP
	NOP
	NOP
	DEC 	C
	BRNE 	J3
	DEC 	B
	BRNE 	J2
	DEC 	A
	BRNE 	J1
	RET

;******************* Delay 1seg *******************
DELAY1seg:
	LDI 	A, 241
L1:	
	LDI 	B, 1
L2:	
	LDI 	C, 48
L3:	
	LDI 	D, 230
L4:	
	NOP
	NOP
	NOP
	DEC 	D
	BRNE 	L4
	DEC 	C
	BRNE 	L3
	DEC 	B 
	BRNE 	L2
	DEC 	A
	BRNE 	L1
    RET
