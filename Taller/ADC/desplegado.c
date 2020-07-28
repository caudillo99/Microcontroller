/*
Ejercicio ADC - desplegado
Alumno: Caudillo Sanchez Diego
Materia: Microprocesadores y microcontroladores
Docente: Dr. Leocundo Aguilar

*/

#include <avr/io.h>
#include <inttypes.h>

#define MOD 100
#define GAIN 100000
#define BASE 10
#define C1 -4 
#define C2 0.648
#define C3 -0.00072 
uint8_t module(uint32_t number, uint32_t base);
void Humidity_show(uint8_t valor_sensor);
void itoa(uint32_t number, char *str, uint8_t base);
void myputs(char *str);

void main( void ){
    /*Suponiendo que ya se configuro y se hizo la conversion
    del ADC.*/
    uint8_t value;
    /*Leer el valor de ADCH, suponiendo que se ajusto a la derecha*/
    value = ADCH;
    myputs("Sensor value: ");
    Humidity_show(value);
}

uint8_t module(uint32_t number, uint32_t  module){
    while(number >= module){
        number -= module;
    }
    return ((uint8_t)number);
}

/*  Descripcion: despliega el valor de la humedad relativa en formato decimal
    *con solo dos digitos despues del punto (p.e. 68.53%) sin manejar datos o 
    *constantes tipo float

    Parametros de entrada:
    uint8_t valor_sensor: es el valor (crudo) leido del sensor de humedad 

    Valores retornados:
    Ninguno.
*/
void Humidity_show(uint8_t valor_sensor){
    char str[5];
    /*Valor de la ecuacion con resolucion de x100000 para obtener los decimales como entero*/
    uint32_t res = (C1 + C2*(valor_sensor) + C3*(valor_sensor*valor_sensor))*(GAIN);
    /*Pasa el valor de los digitos despues del punto. Debido a que con 8-bits (255)
    se obtiene una humedad de 114.42%, el modulo se multiplica x10 para obtener valores del 0-1000.
    Que en este caso, solo se necesita hasta el 114.*/
    itoa(module(res/GAIN, MOD*10), str, BASE);
    myputs(str);
    putchar('.');
    /*Para obtener los numeros decimales, es necesario dividir la resolucion con el modulo con 
    el fin de hacer mas chica la resolucion y obtener los numeros mas a la derecha*/
    itoa(module(res/(GAIN/MOD), MOD), str, BASE);
    myputs(str);
    putchar('%');
}

void myputs(char *str){
    while(*str)
        putchar(*(str++));
}

void itoa(unsigned int number, char *str, unsigned char base){
    unsigned char aux,i=0;
    char str_aux[10];
    while (number) {
        aux = (unsigned char)module(number, base);
        number /= base;
        str_aux[i] = (aux<10) ? aux+'0' : aux+'A'-10;
        i++;
    }
    while (i) {
        *(str++) = str_aux[i-1];
        i--;
    }
    *str='\0';
}