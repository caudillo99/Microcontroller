#include "Timer.h"
#define BYTE unsigned char
#define WORD unsigned int
void UpdateClock( void );
void DisplayClock( void );
void PrintDec2d( BYTE dato);
void Delay( BYTE time);
void setClock(BYTE Hora, BYTE Minutos, BYTE Segundos);

BYTE seg = 0;
BYTE min = 0;
BYTE hrs = 0;
WORD address = 0xFFFF;

void main(){
    Timer_Ini();
    setClock(23,59,30);
    while (1){
        if( TimerSecFlag() ) {
            UpdateClock();
            DisplayClock();
        }
        Delay(100);
        putchar('.');
    }    
}

void UpdateClock( void ){
    seg = (++seg % 60);
	if(!(seg)){
		min = (++min%60);
		if(!(min)){
			hrs = (++hrs % 24);
		} 
    }
}
void DisplayClock( void ){
    PrintDec2d(hrs);
    putchar(':');
    PrintDec2d(min);
    putchar(':');
    PrintDec2d(seg);
}

void PrintDec2d( BYTE dato){
    putchar( dato/10 +'0'); /* Imprime decenas */
    putchar( dato%10 +'0'); /* Imprime unidades */
}
unsigned char TimerSecFlag( void ){
if( SecFlag == 1 ){
}

void Delay(BYTE time){
    while (--time);
}

void setClock(BYTE Hora, BYTE Minutos, BYTE Segundos) {
    seg = Segundos;
    min = Minutos;
    hrs = Hora;
}