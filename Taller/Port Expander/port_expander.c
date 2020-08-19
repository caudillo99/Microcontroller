/**
 * Alumno: Caudillo Sanchez Diego
 * Materia: Microcontroladores y microprocesadores
 * Taller: Expansor de puertos (salida)
 * Docente: Dr. Leocundo Aguilar
 * Fecha de entrega: 18/Agosto/2020

Descripcion.
Una forma de expandir un puerto (de salida) a mayor cantidad 
de bits es utilizando un dispositivo retenedor direccionable 
por bits  (n-bit addressable latch). Un ejemplo de este tipo 
de dispositivo es el IC 74LS259 al cual se le puede escribir 
el valor de un bit (0 ó 1) a una determinada salida tipo latch 
seleccionado por tres bits ( 0 a 7).

====================================================================

Instrucciones.
Analice, diseñe e implemente el código correspondiente al manejador 
de un puerto extendido basado el IC 74LS259 el cual está conectado 
en el puerto B del microcontrolador.
*/

#include <avr/io.h>
#include <inttypes.h>

#define MAX_OUTPUTS 8
/*Headers*/
void Init_PortB( void );
void Write_PORTB_Expander( uint8_t data, uint8_t latch_output );

/*Funcion que escribe un bit (0 o 1) en un latch (74ls259) (0-7)*/
void Write_PORTB_Expander( uint8_t data, uint8_t latch_output ){
    if(latch_output < MAX_OUTPUTS ){
        if(data == 0 || data == 1){
            /*Inicializa PORTB*/
            Init_PortB();
            /*Selecciona la salida del Latch*/
            PORTB |= latch_output;
            /*DDB3 como salida para el pin D del latch*/
            DDRB |= (1<<DDB3);
            /*Si dato es 1*/
            if(data)
                PORTB |= (1<<PB3);
            /*Si dato es 0*/
            else
                PORTB |= ~(1<<PB3);
        }
        /*Setea los puertos como salidas en Hi-Z*/
        PORTB = 0x00;
        DDRB = 0x00;
    }
}

/*Inicializa el Puerto B del AVR*/
void Init_PortB( void ){
    /**
     * DDR0 (output) = 1    PB0 (A0) = 0  
     * DDR1 (output) = 1    PB1 (A1) = 0 
     * DDR2 (output) = 1    PB2 (A2) = 0 
     * DDR3 (input) =  0    PB3 (D) = x 
     * DDR4 (output) = 1    PB4 (Enable') = 0 
     * DDR5 (output) = 1    PB5 (Clear') = 1 
     * DDR6 = x             PB6  = x 
     * DDR7 = x             PB7  = x 
    */
   DDRB = 0x37;
   PORTB = 0x20;
}