#include <avr/interrupt.h>
#include <inttypes.h>
#include "Timer0.h"
#include "UART.h"

static volatile uint64_t ms=0;
static volatile uint8_t SecFlag;

void Timer0_Init( void ){
    DDRB |= (1 << PB7); //OC0A
    TCNT0 = 0x00 ;     //Initialize the counter
    OCR0A = 249; //Set the TOP value
    TCCR0A |= (1<<WGM01);  //ctc mode
    TCCR0B |= (1<<CS00) | (1<<CS01);//Timer0 start 64 prescaler
    TIMSK0 |= (1<<OCIE0A); //Timer/Counter0 Output Compare Match A Interrupt Enable

	sei();
}

uint8_t Timer0_SecFlag ( void ){
    if( SecFlag ){
        SecFlag=0;
        return 1;
    }
    else{
        return 0;
    }
}

uint64_t millis( void ){
    return ms;
}

void UART_AutoBaudRate( void ){
    DDRE &= ~(1<<DDE0); //porte as input
    PORTE |= (1<<PE0); //pull up on 

    TCNT0 = 0;  //set Counter0 register to 0
    TCCR0A = 0; //normal mode
    TCCR0B = 0; //timer0 stopped    

    while ((PINE & (1<<PE0)));
    TCCR0B = (1<<CS01);  //timer0 starts; 8 prescaler
    while (!(PINE & (1<<PE0)));
    TCCR0B = 0; //timer0 stopped
    
    UBRR0 = (TCNT0>>1)-1;
}


ISR (TIMER0_COMPA_vect){ 
    static uint16_t milli_sec = 0;
    ms++;
    milli_sec++;
    if(1000 <= milli_sec ){
        SecFlag = 1;
        milli_sec = 0;
    }
}

