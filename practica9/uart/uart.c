#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

/*Global variables*/
ring_buffer_t input_queue;
ring_buffer_t output_queue;

/*SIG_USARTx_DATA*/
ISR(USART_UDRE_vect){
    if(OUTPUT_BUFFER_EMPTY)
        /*Disable Empty Interrupt*/
        UCSR0B &= ~(1<<UDRIE0); 
    else{
        output_queue.head = (output_queue.head+1) % BUFFER_SIZE;
        UDR0 = output_queue.buffer[output_queue.head];
    }
}
/*USART0 Receiver*/
ISR(USART_TX_vect){
    if(!INPUT_BUFFER_FULL){
        input_queue.tail = (input_queue.tail+1) % BUFFER_SIZE;
        input_queue.buffer[input_queue.tail] = UDR0;
    }
}

void UART_putchar(char data){
    /*waits to data */
    while (OUTPUT_BUFFER_FULL);
    /*Points to the next position*/
    output_queue.tail = (output_queue.tail+1) % BUFFER_SIZE;
    input_queue.buffer[output_queue.tail] = data;
    /*Enable interrupt in UDRE flag (Ready to Transmit)*/
    USCR0B |= (1 << UDRIE0); 
}

void UART_puts(char *str){
    while (*str)
        UART_putchar(*(str++) );
}

uint8_t UART_available( void ){
    return (!INPUT_BUFFER_EMPTY);
}

char UART_getchar( void ){
    static char aux;
    /*Waiting for Data*/
    while(!UART_available());
    input_queue.head = (input_queue.head+1) % BUFFER_SIZE;
    aux = input_queue.buffer[input_queue.head];
    /*Print the character (echo)*/
    UART_putchar(aux);
    return aux;
}

void UART_gets(char *str){
    const unsigned char max_size = 20;
    const char *const aux = str;
    static char c;
    
    c = UART_getchar();
    while (c != 13){
        if( c != 8){
            if(str < aux + max_size - 1)
                *(str++) = c;
            else{
                UART_putchar(8);
                UART_putchar(32);
                UART_putchar(8);
            }
        }else{
            if(str == aux)
                UART_putchar(32);
            else{
                UART_putchar(32);
                UART_putchar(c);
                str--;
            }
        }
        c = UART_getchar();
    }
    UART_putchar(10); 
    *str = 0;
}

void gotoXY(uint8_t x,uint8_t y) {
  static char str[] = "\x1b[00;00H";

  /*convert dec to char*/
    str[3] = '0' + y % 10;
    y/=10;
    str[2] = '0' + y %10; 
    str[6] = '0' + x % 10;
    x/=10;
    str[5] = '0' + x %10; 
    UART_puts(str);
}

void setColor(uint8_t color){
    static char str[] = "\x1b[30m";
    switch (color) {
      case BLACK: str[3]  = '0';    break;
      case RED: str[3]    = '1';    break;
      case GREEN: str[3]  = '2';    break;
      case YELLOW: str[3] = '3';    break;
      case BLUE: str[3]   = '4';    break;
      case MANETA: str[3] = '5';    break;
      case CYAN: str[3]   = '6';    break;
      case WHITE: str[3]  = '7';    break;
    }
    UART_puts(str);
}

void clr_screen( void ){
    UART_puts("\x1b[2J");
    UART_puts("\x1b[H");
}

unsigned int atoi(const char *str){
    unsigned int number = 0;
    while(*str) {
        if(*str >= '0' && *str <= '9'){
            number *= 10;
            number += (*str) - '0';
            str++;
        }
        else 
            break;
    }
    return number;
}
void itoa(char *str, unsigned int number, unsigned char base){
    char *str_start = str;
    char aux;
    do{
        aux = '0' + number % base;
        *(str++) = (aux > '9') ? aux+7 : aux;
        number /= base;
    } while(number > 0 );
    *(str--) = '\0';
    /*reversing the array*/
    while(str_start < str) {
        aux = *str_start;
        *str_start = *str;
        *str = aux;
        str_start++;
		str--;
    }
}

void UART_init(uint8_t com, uint16_t baud_rate, uint8_t size,uint8_t parity,uint8_t stop){
    uint8_t *base_address;
    
    /*0: 0x0C; 1: 0xC8; 2: 0xD0; 3: 0x130*/
    if(com == 3)
        base_address = (uint8_t*)0x130;
    else
        base_address = (uint8_t*) 0xC0 + (0x08 * com);
    
    /*Enable receiver and transmitter*/
    *(base_address + 1) |= (1<<RXEN0) | (1<<TXEN0);
    
    /*Settin' baud rate*/
    baud_rate = FREQ/16/baud_rate - 1;
    *(base_address + 5) = (uint8_t) (baud_rate >> 8);    
    *(base_address + 4) = (uint8_t) baud_rate;
    
    /**setting up character size. Size 5 is set by default below**/
    *(base_address + 1) &= ~(1<<UCSZ02); /*UCRxB*/
    *(base_address + 2) &= ~(1<<UCSZ00) & ~(1<<UCSZ01);/*UCRxC*/
    
    switch (size) {
        case 6: *(base_address + 2) |= (1<<UCSZ00) ;/*UCRxC*/
        break;
        case 7:*(base_address + 2) |= (1<<UCSZ01) ;/*UCRxC*/
        break;
        case 8: *(base_address + 2) |= (1<<UCSZ00) | (1<<UCSZ01);/*UCRxC*/
        break;
    }

    /**setting up parity**/
    *(base_address + 2) &= ~(1<<UPM00) & ~(1<<UPM01);/*UCRxC*/
    switch (parity) {
        case 1: *(base_address + 2) |= (1<<UPM00) | (1<<UPM01);/*UCRxC*/
        break;
        case 2: *(base_address + 2) |= (1<<UPM01);/*UCRxC*/
        break;
    }

    /* STOP BIT */
    if (stop == 2)
        *(base_address + 2) |= (1<<USBS0); /*UCRxC*/
    
    /*enable rx and UDRIE interrupt  **/
    *(base_address + 1) |= (1<<RXCIE0) | (1<<UDRIE0); /*UCRxB*/
    	input_queue.head = 0;
	input_queue.tail = 0;
	output_queue.head = 0;
	output_queue.tail = 0;
}