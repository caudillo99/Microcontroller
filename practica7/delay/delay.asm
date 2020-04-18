.INCLUDE "m2560def.inc"
.EQU INIT_VALUE = 0x80

.def A = R16
.def B = R17
.def C = R18
.def D = R19
main:
	CALL DELAY1seg
	ret
	
DELAY103us:
	LDI A,182
	delay1:
		LDI B, 1
	delay2:
		DEC B
		NOP             
	
		BRNE delay2

		DEC A
		NOP
		NOP
		BRNE delay1
		RET

;******************* Delay 100ms *******************
DELAY100ms:
	LDI		A,190
NXT:
	LDI 	B,122
NXT2:
	LDI 	C,62
NXT3:
	DEC 	C
	BRNE 	NXT3
	DEC 	B
	BRNE 	NXT2
	DEC 	A
	BRNE 	NXT
	NOP
	NOP
	RET

;******************* Delay 1seg *******************
DELAY1seg:
	LDI		A,255   ;1
NEXT:
	LDI 	B,255   ;A
NEXT2:
	LDI 	C,62   ;AB
NEXT3:
	DEC 	C    ;ABC
	NOP			 ;ABC
	BRNE 	NXT3 ;2*(ABC-1)+1 
	DEC 	B	 ;1*AB
	BRNE 	NXT2 ;2*(AB-1)+1
	DEC 	A	 ;1*A
	BRNE 	NXT	 ;2*(A-1)+1
	RET			 ;5
	;5+5+1-3+4A+4AB+4ABC = 16,000,000
	;4(A+AB+ABC) = 15 999 992
	; A+AB+ABC = 3 999 998/65281
	; A(1+B+BC) =

