;Practica.6 Programacion ATmel 1280
;Caudillo Sanchez Diego
;Microcontroladores y microprocesadores
.INCLUDE "m2560def.inc"
.EQU INIT_VALUE = 0x80

;	x = (a * x + c) % mod
;	where X is the sequence of pseudo-random values
;	m, 0 < m  - modulus 
;	a, 0 < a < m  - multiplier
;	c, 0 = c < m  - increment
;	x, 0<=x < m	- the seed (start value)
;====================================================
; X = 16-bit 
.DEF	x_l = R16
.DEF	x_h = R17
; A = 16-bit 
.DEF 	a = R18
; C = 8bit increment
.DEF	c_l = R20
.DEF	c_h	= R21
; MOD = 16-bit module (0-65535)
.DEF 	mod_l = R22 
.DEF 	mod_h = R23

main:
	ldi mod_l, 0xFF
	ldi mod_h, 0xFF	; modulus = 0xffff(65,535)
	ldi a, 0xAA
	ldi c_l, 0xFF
	ldi c_h, 0x00	; increment = 0x00FF
	ldi x_l, 0x04
	ldi x_h, 0x00	; seed value = 0x0004
	ldi r24, 0x10
	ldi r30, 0xff
	ldi r31, 0xff
	
	calculate:
		mul a, x_l
		add x_l, r0
		adc x_h, r1
		add x_l, c_l
		adc x_h, c_h
		and x_l, mod_l
		and x_h, mod_h
		out PORTA, x_l
		out PORTA, x_h
		
		sbiw z, 1
		cpi r31,0
		brne calculate
		cpi r30,0
		brne calculate
		ldi r31, 0xff
		ldi r30, 0xff
		dec r24
		cpi r24,0
		brne calculate
	finish:
		jmp finish



	

