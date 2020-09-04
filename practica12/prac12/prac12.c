#include "adc.h"
#include "UART.h"
#include "Timer0.h"
#include <inttypes.h>
#include <avr/interrupt.h>

#define DISCHARGE_VALUE 1000

int main(){
  	sei();
    uint32_t timestamp = 0;
    char string[8];
    // Configure as output both pins
    DDRF |= (LED_M|LED_P);
    ADC_Init();
    //UART_Init
    UART_init(0,12345,8,1,2);

    while(1){

      if (ADC_Read(4)<DISCHARGE_VALUE)
      {
        PrintAdc();
        UART_puts(0,"\t\t\t[");
        // Measure the discharge time
        itoa(string,millis()-timestamp,10);
        UART_puts(0,string);
        UART_puts(0,"]");

        //Configure '-' pin as output
        DDRF |= (LED_M);
        // Visual queue, needed only for debugging
        blink();
        // Inverse polarization of the LED
        PORTF&=~LED_P;
        PORTF|=LED_M;
        // Small delay to "charge" it
        delay(1);
        // Float the charging pin
        DDRF&=~LED_M;
        PORTF&=~LED_M;
        // Timestamp to measure the discharge time
        timestamp = millis();
        PrintAdc();
        UART_puts(0,"\n\r");
      }
    }
    return 0;
}
