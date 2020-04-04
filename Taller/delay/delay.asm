Delay_1seg:                 ; Delay for 1 second
    LDI R16,128             ; Consumes one clock cycle.
Delay1:
    LDI R17,125             ; Consumes one clock cycle.
Delay2:
    LDI R18,249             ; Consumes one clock cycle.
Delay3:
    DEC R18                 ; Consumes one clock cycle.
    NOP                     ; Consumes one clock cycle.
    BRNE Delay3             ; Consumes two clock cycles if Z=1. 1 clock if Z=0
	NOP
	DEC R17                 ; Consumes one clock cycle.
    BRNE Delay2             ; Consumes two clock cycles if Z=1. 1 clock if Z=0
	NOP
	DEC R16                 ; Consumes one clock cycle.s
	BRNE Delay1             ; Consumes two clock cycles if Z=1. 1 clock if Z=0
RET

/********************************************************************/
Delay_1ms:                  ; Delay for 1 second
    LDI R16,16              ; Consumes one clock cycle.
Delay1:
    LDI R17,249             ; Consumes one clock cycle.
Delay2:
    DEC R17
    NOP                     ; Consumes one clock cycle.
    BRNE Delay2             ; Consumes two clock cycles if Z=1. 1 clock if Z=0
    NOP
    DEC R16                 ; Consumes one clock cycle.
    BRNE Delay1             ; Consumes two clock cycles if Z=1. 1 clock if Z=0
RET


/********************************************************************/
Delay_100us:            ; Delay for 1 second
    LDI R16,2           ; Consumes one clock cycle.
Delay1:
    LDI R17,199         ; Consumes one clock cycle.
Delay2:
    DEC R17
    NOP                 ; Consumes one clock cycle.
    BRNE Delay2         ; Consumes two clock cycles if Z=1. 1 clock if Z=0
    DEC R16             ; Consumes one clock cycle.
    BRNE Delay1         ; Consumes two clock cycles if Z=1. 1 clock if Z=0
	NOP
	NOP
RET