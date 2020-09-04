ROTATELEFT:
    LDI R30, 0XFF
    LDI R31, 0X00   ; Z = 0X00FF
    MOV R29, R31 
    MOV R28, R30    ;AUX = Z
    LDI R26, 0X80   ; MASK 
    LSL R31
    LSL R30
    AND R29, MASK
    AND R28, MASK
    CPI R29, 0
    BREQ NXT
    ORI R29,1
NXT:
    CPI R28,0
    BREQ FIN
    ORI R28,1
FIN:
    LDI R29, 0
    LDI R28, 0
    RET
