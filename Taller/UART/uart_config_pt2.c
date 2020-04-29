/*
Alumno: Caudillo Sánchez Diego
Matricula : 1249199
Materia: Microcontroladores y microprocesadores
Taller-UART Pt.2
Fecha de entrega: 29/04/2020
*/
#include <avr/io.h>
#define FREQ 16000000
unsigned char UART_config(char* str);
unsigned int getParameter(unsigned char parameter, char* str);

void main( void ){
    UART_config("COM1:9600,8,N,1");
}

uint8_t UART_config(char* str){
    uint8_t status, UCSZ = 0X01, USBS = 0X03, UPM = 0X04;
    uint8_t *com, parity, stopBit, dataSize;
    uint32_t baudRate;
    /*Gettin' configuraton parameters*/
    offset   = (uint8_t)getParameter(1, str);
    baudRate = FREQ / (uint32_t)(16*(uint32_t)getParameter(2, str)-1 ) ;
    dataSize = (uint8_t)getParameter(3, str);
    parity   = (uint8_t)getParameter(4, str);
    stopBit  = (uint8_t)getParameter(5, str);
    /*Checking parity*/
    if(parity == 'N')
        parity = 0;
    else if (parity == 'O')
        parity = 1;
    else 
        parity = 3;
    /*Validating if all the parameters are Ok.*/
    if( (offset>=0 && offset <=3) && (baudRate>=300 && baudRate<=115200)  && (dataSize>=5 && dataSize<=8) && (parity>=1 && parity<=2) && (stopBit==1 || stopBit==2) ){
        /*Getting the selected COM*/
        com = (uint8_t*)(0xC0 + (uint8_t)(offset*0x08) ); 
        /*Set frame format*/
        *(com+0x02) =  (uint8_t)(( stopBit << USBS) | (dataSize-0x05) << UCSZ | (parity << UPM) ); 
        /*Set baud rate*/
        *(com+0x04) = (uint8_t)baudRate;
        *(com+0x05) = (uint8_t)(baudRate >> 8);
        status = 1; /*Set status flag ON indicating that everthing is OK.*/
    }else
        status = 0; /*Clear status flag indicating that something went wrong */
    return status;
}
/*  
    La función retorna el valor (entero) del parametro seleccionado.
    Parametros:
        parameter: Número de parámetro desea que retorne:
            1: COM
            2: BAUD
            3: DATA
            4: PARITY
            5: STOP BIT
        str: Cadena que contiene la configuración de 
        del UART. Ej: "COM2:9600,8,N,1"
*/
uint16_t getParameter(unsigned char parameter, char *str){
    uint16_t aux;
    aux = 0;
    if( parameter > 0 && parameter < 4 ){
        /*Si elije el COM como parametro, buscará
        el caracter ':' y se colocara en la posicion
        anterior que es el numero de COM y retornara
        el valor en la variable aux.*/
        if(parameter == 1){
            while (*(str+1) != ':')
                str++;
            aux = *str - '0';
        }else{
            uint8_t startChar;
            if(parameter == 2)
                startChar = ':'; /*Se posiciona en el caracter ':' e inicia los calculos para
                determinar el BAUD */
            else
                startChar = ','; /* Se posiciona en el caracter ',' e incia los calculos para 
                determinar la cantidad de bits que envia*/
            while(*(str-1) != startChar)
                str++;
                /*Ambos paran en una ','. En esta parte se hacen las operaciones para
                retornar el valor del parametro */
            while (*(str) != ','){
                aux *= 10;
                aux += (*str)-'0' ;
                str++;
            }
        }
        /*Busca las dos comas, que significa que se ha posicionado en el
        caracter indicado del parametro de Paridad. Almacena el valor en 
        la variable aux, para retornalo.*/
    }else if(parameter == 4){
        uint8_t counter = 0;
        while (counter < 2){
            str++;
            if(*(str-1) == ',')
                counter++;
        } aux = *(str);
    }else{
        /*Busca el final de la cadena para posicionarse en una posicion anterior
        y retornar el valor que esta ahí. */
        while(*(str+1) != 0)
            str++;
        aux = *str - '0';
    }
    return aux;
}