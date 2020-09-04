#ifndef _TIMER0_H
#define _TIMER0_H
#include <inttypes.h> 
#define DIV_YEAR  31556926
#define DIV_MONTH 2629743 
#define DIV_WEEK  604800
#define DIV_DAY   86400
#define DIV_HOUR  3600
#define DIV_MIN   60
#define DIV_SEC   1 
/* Función para inicializar el Timer0 y generar */
/* la temporización de 1 Sec. */
void Timer0_Init( void );
/* Función para verificar bandera del segundo */
uint8_t Timer0_SecFlag ( void );
uint64_t millis(void);
void UART_AutoBaudRate( void );

#endif /* _TIMER0_H */
