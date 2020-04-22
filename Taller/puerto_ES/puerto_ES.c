#include <avr/io.h>
#include <inttypes.h>
#define BAUD 9600

void TXoPin ( uint8_t dato);

int main(void){
	
	
}

void USART_init(unsigned int ubbr){
	UBRR0H = (unsigned char) (ubbr>>8);
	UBRR0L = (unsigned char) ubbr;
	/*Enable transmiter and receiver*/
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/**/
	UCSR0C = (1<<USBS0);
}
