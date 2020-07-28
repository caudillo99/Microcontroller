/*  Alumno: Caudillo Sanchez Diego
    Materia: Microcontroladores y microprocesadores
    Docente: Dr. Leocundo Aguilar 
    Taller ADC Amplitud de onda
    Fecha de entrega: 03/06/2020
*/

#include <avr/io.h>
#include <inttypes.h>
#define MAX_SAMPLE 8

void ADC_Init( void );
uint8_t ADC_readAmp( void );

uint8_t offset = 0;

void main(){
    uint8_t value;
    ADC_Init();
    value = ADC_readAmp();
    while (1)
        ;
}

void ADC_Init( void ){
    /*AREF; Right Adjust; Differential conversion with 10x gain at ADC0*/
    ADMUX = (1 << MUX3); 
    ADCSRB = 0;

    /*Enable ADC; Prescaler set at 128*/
    ADCSRA |= (1<<ADEN) | (7<<ADPS0);       

    /*ADC take 25 Cycles for the 1st conversion. Then it gonna take only 13 cycles.
    That's why we start the conversion here.*/
    ADCSRA |= (1<<ADSC);    
    while( ADCSRA&(1<<ADSC) );   /*Waits until conversion is done*/

    offset = ADCL;          /*Read value of ADCL */
    offset |= (ADCH<<8);    /*Gets the offset */
    offset /= 10;           /*Divide to return a the original scale value*/

    ADMUX = 0;              /*Selects ADC0 */
}

uint8_t ADC_readAmp( void ){
    uint16_t aux, amplitud;
    uint8_t counter = 0;

    while (counter < MAX_SAMPLE){
        ADCSRA |= (1<<ADSC);           /*Starts conversion*/
        while( ADCSRA&(1<<ADSC) );     /*Waits for conversion*/
        
        /*Gets the value*/
        aux = ADCL;                    
        aux |= (ADCH<<8);

        if(aux > offset+1){     /*If the read value has an acceptable range*/
            counter++;          /*Increment read counter*/
            amplitud += aux;   /*Sum the read values*/
        }
    }
    return ((uint8_t)(amplitud/MAX_SAMPLE) );
}