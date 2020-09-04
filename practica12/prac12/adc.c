#include "adc.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer0.h"
#include "UART.h"
#define LIM_INF 
uint16_t offset = 0;

/*Esta funci�n inicializa para 16 bits de resoluci�n y habilita 
el ADC del microcontrolador de forma gen�rica. Encontrar el 
desplazamiento (offset) de la medici�n y almacenarla.*/
void ADC_Init(void){
    ADMUX = (1 << REFS0) | (1<<MUX0); /*Right Adjustmen; AVCC; Single Ended input ADC0*/
    ADCSRA = (1 << ADEN) | (0x07 << ADPS0 ); /*ADC On; Prescaler at 128*/
    ADCSRA |= (1 << ADSC); /*ADC Start Conversion*/
    while ((ADCSRA>>ADSC)&1)
        ; /*Waits till' first conversion is finished*/
    ADCSRA |= (1 << ADSC); /*ADC Start Second Conversion*/
    while ((ADCSRA>>ADSC)&1)
        ;
    offset = ADC;
}

/*Est� funci�n lo que realiza es una lectura del ADC usando el 
canal correcto y retornando el valor de 16 bits acorde a la aplicaci�n, 
compensando el desplazamiento de la medici�n.*/
uint16_t ADC_Read( uint8_t channel ){
    ADCSRB |= (channel<<MUX0); /*selects the channel*/
    ADCSRA |= (1 << ADSC); /*Start ADC conversion*/
    while ((ADCSRA>>ADSC)&1)
    ; /*Waits till' conversion is finished*/
        
    return (ADC);
}

void init_port( void ){
    DDRF = 0;
    PORTF = 0;
}
/*Esta funci�n deber� polarizar de forma inversa el LED y medir el tiempo 
de descarga hasta que llegue al voltaje del l�mite inferior que elijan, 
retornando el numero de milisegundos que transcurrieron. El prop�sito de 
la funci�n es para discernir si el �Flash� este encendido o no.*/
uint16_t measureDischargeTime( void ){
    uint16_t measure_time;
	init_port();
    /** (Polarizacion inversa)
     * DDF4 = 1 (OUTPUT)    PF4 = 1 (gnd)
     * DDF5 = 1 (OUTPUT)    PF5 = 0 (vcc)*/
    DDRF |= (1<<DDF5)|(1<<DDF4); 
    PORTF |= (1<<DDF4);
	delay(100);
    /** 
     * DDF4 = 0 (INPUT Pxn)     PF4 = 1
     * DDF5 = 0 (INPUT Hi-Z)    PF5 = 0 */
    Timer0_Init();
    ADC_Read(4);
    measure_time = (uint16_t)millis();
    DDRF = 0;
    return measure_time;
}

void delay(uint8_t ms){
    uint16_t cnt;
    asm volatile(
        "\n"
        "L_dl1%=:"      "\n\t"
        "mov %A0, %A2"  "\n\t"
        "mov %B0, %B2"  "\n\t"
        "L_dl2%=:"      "\n\t"
        "sbiw %A0, 1"   "\n\t"
        "brne L_dl2%="  "\n\t"
        "dec %1"        "\n\t"
        "brne L_dl1%="  "\n\t"
        : "=&w" (cnt)
        : "r" (ms), "r" (delay_count)
    );
}

void blink(void){
  PORTF|=LED_P;
  PORTF&=~LED_M;
  delay(1);
  PORTF&=~LED_P;
  delay(99);
}

void PrintAdc(void){
    char str[5];
    uint16_t adcValue = 0; 
    adcValue = ADC_Read(4);
    for(uint8_t i = 0; i<(adcValue/25); i++){
      UART_putchar(0,'.');
    }
    itoa(str, adcValue,10);
    UART_puts(0, str);
}
