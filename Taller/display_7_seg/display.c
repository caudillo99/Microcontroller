/*
Alumno:Caudillo Sanchez Diego
Matricula: 1249199
Materia:Microcontroladores y microprocesadores
*/


/*Tabla para display de 7 segmentos .
Num     abcdefgh    =>  Valor Hex
==================================================
0       11111100        FCh
1       01100000        60h
2       11011010        DAh
3       11110010        F2h
4       01100110        66h
5       10110110        B6h
6       10111110        BEh
7       11100000        E0h
8       11111110        FEh
9       11110110        F6h
*/
#define PA 0x40
#define PB 0x41
#define PC 0x42
#define CtlReg  0x43

#define BYTE unsigned char
#define WORD unsigned int 

void displayDato(BYTE n);
void outportb(BYTE Port, BYTE data);

void main(){
    BYTE i = 0, ms = 0;
    outportb(CtlReg, 0x89);/*Setting the control word*/
    outportb(PA, i); /*Displaying a zero*/
    while (1){
        /*checking the buttons to increase or decrease 
        the display value*/
        if( (inportb(PC) & 0x03) == 0x02){
            if( i < 8)
                i++; 
        }
        if( (inportb(PC) & 0x03) == 0x01){
            if( i > 0)
                i--;
        }
        /*Counting time until 200 ms to update the display*/
        delay(1);
        ms++;
        /*Update the display value*/
        if( ms == 200 ){
            displayDato(i);
            ms = 0;
        }
    }
}

void displayDato(BYTE n){
    static BYTE display7seg[9] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE};
    outportb(PA, display7seg[n]);
}