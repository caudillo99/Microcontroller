#include "Timer.h"
#define INTR 8
volatile static BYTE secFlag = 0;

void interrupt ManejadorISR( void ){
    static BYTE cont = 0;
    cont++; /*ticks counter*/
    if(cont == 20){
        secFlag = 1;
        cont = 0;
    }
}
BYTE TimerSecFlag( void ){
    if( secFlag ){
        secFlag = 0;
        return 1;
    }else
        return 0;
}

void Timer_Ini( void ){
    secFlag = 0;
    pokeW(0x0, INTR*4, (WORD)ManejadorISR+0x100); /*Determinar offset*/
    pokeW(0x0, (INTR*4)+2, _CS);
}
