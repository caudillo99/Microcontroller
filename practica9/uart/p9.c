#include <avr/io.h>
#include "uart.h"
int main( void ){
    char cad[20];
    uint16_t num;
    UART_Ini(0,12345,8,1,2);
    while(1) {
        UART_getchar(0);
        UART_clrscr(0);
        UART_gotoxy(0,2,2);
        UART_setColor(0,YELLOW); //Definirlo en UART.h
        UART_puts(0,"Introduce un número:");
        UART_gotoxy(0,22,2);
        UART_setColor(0,GREEN); //Definirlo en UART.h
        UART_gets(0,cad);
        num = atoi(cad);
        itoa(num,cad,16);
        UART_gotoxy(0,5,3);
        UART_setColor(0,BLUE); //Definirlo en UART.h
        UART_puts(0,"Hex: ");
        UART_puts(0,cad);
        itoa(num,cad,2);
        UART_gotoxy(0,5,4);
        UART_puts(0,"Bin: ");
        UART_puts(0,cad);
    }
}