/*
Alumno: Caudillo Sanchez Diego
Taller: ADC
Materia: Microcontroladores y microprocesadores
Fecha de entrega: 27/05/2020
*/
#include <inttypes.h>
/*Funciones prototipo*/
void Init_ReadKeys( void );
uint8_t ReadKeys( void );

void main(){

}

/*Inicializa la recursos segun la aplicacion*/
void Init_ReadKeys( void ){
    /*Selecciona ADC0; MUX5:0 = 0
    AVCC con capacitor externo en pin AREF*/
    ADMUX = (1 << ADLAR)|(1 << REFS0);
    ADCSRB = 0; 
    
    /*Hace PC0 de entrada*/
    DDRA0 = 0;
    PORTA0 = 0;
    /*Deshabilita interrupciones; Prescaler 16; Activa ADC*/
    ADCSRA = (1<<ADEN) | (1 << ADPS2);
}

/*Determina la tecla que se presionó*/
uint8_t ReadKeys( void ){
    uint8_t key, x = 10;
    /* Selecciona el canal 0*/
    ADMUX = (1 << ADLAR)|(1 << REFS0);
    ADCSRB = 0; 
    
    /*Inicia conversion, seteando el bit SC (Start conversion) */
    ADCSRA = (1 << ADSC );

    /*Espera a que se realice la conversion.S
    Cuando finalice el bit ADSC se hace clear.*/
    while ( ADCSRA & (1 << ADSC) )
        ;
    /* Determina la tecla de presionada */
    if(ADCH < (0x00 + x))
        button = 0; /*No se esta presionando ningun boton*/
    else if(ADCH < (0x33 + x))
        button = 4;
    else if(ADCH < (0x3F + x))
        button = 3;
    else if(ADCH < (0x55 + x))
        button = 2;
    else 
        button = 1;
    
    return key;
}
