#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"



int main() {
  char cad[20];
  uint16_t num;

	sei();
	UART_init(0,12345,8,1,2);
  
  while(true) {
    UART_getchar(0);
    UART_clrscr(0);
    UART_gotoxy(0,2,2);
    UART_setColor(0,YELLOW);
    UART_puts(0,"Introduce un numero: ");


    UART_gotoxy(0,22,2);
    UART_setColor(0,GREEN);
    UART_gets(0,cad);

    num = atoi(cad);
    itoa(cad,num,16);

    UART_gotoxy(0,5,3);
    UART_setColor(0,BLUE);
    UART_puts(0,"Hex:");
    UART_puts(0,cad);

    itoa(cad,num,2);

    UART_gotoxy(0,5,4);
    UART_puts(0,"Bin:");
    UART_puts(0,cad);
  }
  return 0;
}
