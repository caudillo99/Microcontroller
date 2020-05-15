#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer0.h"
#include "UART.h"
/* incluir lo necesario para usar UART0 */
void Clock_Ini(uint64_t);
void Clock_Display(void);
void Clock_update(void);
void Clear_string(char*str);
uint8_t month, day,week, hour, min, sec;
uint16_t year;
int main(){
    char str[10];
    sei();
	UART_init(0,0,8,1,2);
    UART_AutoBaudRate();
    UART_clrscr(0);
    UART_gotoxy(0,5,1);
    UART_puts(0,"Autobauding Done. UBRR =");
    itoa(str,UBRR0 ,10);
    UART_puts(0, str);
    UART_puts(0, "\n\r");

    Timer0_Init();
    Clock_Ini(1583049590000);
              
    while(1){ 
        if( Timer0_SecFlag() ){
            UART_gotoxy(0,5,2);
            Clock_update();
            Clock_Display();
            UART_gotoxy(0,5,3);
        }
        
    } /* fin del loop principal */
    return 0;
}
void Clock_update(void){    
    sec++;
    if (sec == 60){
    	sec = 0;
    	min++;
    	if (min == 60){
    		min = 0; 
    		hour = (hour+1) % 24;
            if (hour == 24){
                hour = 0;
                day++;
                if(day == 30 ){
                    day = 0;
                    month++;
                    if(month == 12){
                        month = 0;
                        year++;
                    }
                }
            }
    	}
    }
}
void Clock_Ini(uint64_t millis){
    uint64_t remainder = 0;
    int aux = 0;
    year = (millis/DIV_YEAR);
    year /= 1000;

    remainder = millis;
    remainder -= (uint64_t)DIV_YEAR*1000*year;
    
    aux = remainder/DIV_MONTH/1000;
    month = (uint8_t)aux;
	
    remainder -= (uint64_t)month*DIV_MONTH*1000;
	aux = remainder/DIV_WEEK/1000;
    week = (uint8_t)aux;

	remainder -= (uint64_t)week*DIV_WEEK*1000;
	aux = (remainder/DIV_DAY/1000);
    day = (uint8_t)aux;

	remainder -= (uint64_t)day*DIV_DAY*1000;
	aux = (remainder/DIV_HOUR/1000);
    hour = (uint8_t)aux;

	remainder -= (uint64_t)hour*DIV_HOUR*1000;
	min = (remainder/DIV_MIN/1000);
    min = (uint8_t)aux;

	remainder -= (uint64_t)min*DIV_MIN*1000;
	aux = (remainder/1000);
    sec = (uint8_t)aux;
}

void Clock_Display( void ){
    /*Date format*/
    char str[5];
    UART_clrscr(0);
    
    /*Print hours*/
    itoa(str,hour, 10);
    UART_puts(0,str);
    UART_putchar(0,':');
    
    /*Print minutes*/
    itoa(str,min, 10);
    UART_puts(0,str);
    UART_putchar(0,':');

    /*Print seconds*/
    itoa(str,sec, 10);
    UART_puts(0,str);
    
    UART_putchar(0, ' ');

    /*print day of the month*/
    itoa(str, 1+(week*7), 10);
    UART_puts(0,str);
    UART_putchar(0,'/');
    
    /*print month*/
    itoa(str, month+1, 10);
    UART_puts(0,str);
    UART_putchar(0,'/');

    /*print the year*/
    itoa(str,year+1970, 10);
    UART_puts(0,str);
    
    
}

void Clear_string(char*str){
    while (*(str)){
        *(str++) = 0;
    }
}
