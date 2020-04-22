.INCLUDE "m2560def.inc"
.EQU INIT_VALUE = 0x80

.def A = R16
.def B = R17
.def C = R18
.def D = R19
main:
	CALL delay1seg
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
	LDI		A,2
	NOP
NXT1:
	LDI 	B,246
NXT2:
	LDI 	C,203
NXT3:
	LDI 	D,3
NXT4:
	DEC 	D
	NOP
	BRNE 	NXT4
	DEC 	C
	BRNE 	NXT3
	DEC 	B
	BRNE 	NXT2
	DEC		A
	BRNE	NXT1
	RET

;******************* Delay 1seg *******************
delay1seg:
    LDI A, 142
jmp1:
    LDI B, 112
jmp2:
    LDI C, 167
jmp3:
	NOP
	NOP
	NOP
    DEC C
    BRNE jmp3
    
	DEC B
    BRNE jmp2
    
	DEC A
    BRNE jmp1

    RET
