#include "adc.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define LIM_INF 
uint16_t offset = 0;

/*Esta función inicializa para 16 bits de resolución y habilita 
el ADC del microcontrolador de forma genérica. Encontrar el 
desplazamiento (offset) de la medición y almacenarla.*/
void ADC_Init(void){
    ADMUX = (1 << REFS0) | ~(1 << ADLAR); /*Right Adjustmen; AVCC*/
    ADCSRA = (1 << ADEN) | (0b111 << ADPS0 ); /*ADC On; Prescaler at 128*/
    ADCSRB = (0b1000 << MUX0); /*Select channel 0 in differential mode 10x (ADC0 - ADC0)*/
    ADCSRA = (1 << ADSC); /*ADC Start Conversion*/
    while ( ADCSRA & (1<<ADSC) ) /*Waits till' conversion is finished*/
        ;
    offset = ADC;
    offset /= 10;
}

/*Está función lo que realiza es una lectura del ADC usando el 
canal correcto y retornando el valor de 16 bits acorde a la aplicación, 
compensando el desplazamiento de la medición.*/
uint16_t ADC_Read( uint8_t channel ){
    ADCSRB = (channel << MUX0); /*selects the channel*/
    ADCSRA = (1 << ADSC); /*Start ADC conversion*/
    while ( ADCSRA & (1<<ADSC) ) /*Waits till' conversion is finished*/
        ;
    return (ADC - offset);
}

/*Esta función deberá polarizar de forma inversa el LED y medir el tiempo 
de descarga hasta que llegue al voltaje del límite inferior que elijan, 
retornando el numero de milisegundos que transcurrieron. El propósito de 
la función es para discernir si el “Flash” este encendido o no.*/
uint16_t measureDischargeTime( void ){
    uint16_t discharge_time;
    while( LIM_INF < ADC_Read(0)){
        discharge_time++ ;
    }
    return discharge_time;
}
