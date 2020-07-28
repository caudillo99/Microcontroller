/*
    Alumno: Caudillo Sanchez Diego
    Ejercicio: Interruptores y 2 Displays de 7 segmentos.
    Materia: Microcontroladores y microprocesadores
    Fecha de entrega: 19/06/2020
*/

/*      ***** INSTRUCCIONES *****
Dado el siguiente circuito diseñe un programa para incrementar o decrementar 
los displays de 7 segmentos que cumpla con los siguientes puntos.
1. El display debe iniciar mostrando 0 (solo un cero).
2. Cada vez que se presiona SW1 se incrementa el valor mostrado en el display 
   siempre y cuando no sea el valor máximo (99).
3. Si se presiona SW2 se decrementa el valor desplegado siempre y cuando el 
   valor presentado no sea cero (0).
4.Las acción de incrementar y decrementar se realizan cuando se libera el 
  interruptor. Esto es, el interruptor debe ser presionado y liberado para 
  tomar la acción (cambio del conteo)

NOTAS:
    1. El dispositivo 8255 tiene direccion de 40h
    2. Es deseable estar actualizando el display de 7 segmento aproximadamente cada 200ms.
    3. Considere la siguiente seccion correspondiente al desplegado de un valor  (digito)
    como una base para su funcion de desplegado.

    0   1111 1100   FCh
    1   0110 0000   60h
    2   1101 1010   DAh
    3   1111 0010   F2h
    4   0110 0110   66H
    5   1011 0110   B6h
    6   1011 1110   BEh
    7   1110 0000   E0h
    8   1111 1110   FEh
    9   1110 0110   E6h
*/

#define PA 0x40
#define PB 0x41
#define PC 0x42
#define CtlReg8255 0x43

#define BYTE unsigned char
#define WORD unsigned int

#define MAX_VALUE 99
#define MIN_VALUE 0
#define UPDATE_TIME 200
#define PC0 0
#define PC1 1

/*Representacion de un display de 7-segmentos*/
static BYTE display7seg[10] = {0xFC, 0x60, 0xDA, 0xF2, 
    0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xE6
};

void outportb(BYTE port, BYTE data);
void DisplayDato( BYTE n);
void updateDisplay( void );

void main(){
    BYTE counter = 0,ms = 0, switch_value ;

    /*Setting the control word*/
    outportb(CtlReg8255, 0x89);

    /*Displaying the start value (zero) */
    outportb( PA, display7seg[counter] );
    outportb( PB, display7seg[counter] );

    while (1){
        /*Get the switch value (increment or decrement)*/
        switch_value = inport(PC);

        /*Check which button was pressed*/
        if( (switch_value & (1<<PC0) ) ){
            /*Waits till' the button is released*/
            while (switch_value & (1<<PC0) );
            counter = (counter < MAX_VALUE) ? counter+1 : MAX_VALUE;
        }
        else if ( switch_value & (1<<PC1) ){
            /*Waits till' the button is released*/
            while ( switch_value & (1<<PC1) );
            counter = (counter > MIN_VALUE) ? counter-1 : MIN_VALUE;
        }

        /*Display update*/
        delay(1);
        ms += 1 % UPDATE_TIME;
        if( !ms ){
            DisplayDato(counter);
        }
    }   
}

/*Funcion que muestra un valor de 0 a 99 en dos displays de 7 segmentos.
    Parametros:
        n: Valor de tamano BYTE que indica el valor que
        se va mostrar en los displays
    Valor de retorno: Ninguno
*/
void DisplayDato( BYTE n ){
    /*Least Significant Display*/
    outportb(PB, display7seg[n%10]);
    /*Most Significant Display*/
    outportb(PA, display7seg[n/10] );
}
