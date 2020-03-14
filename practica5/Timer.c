#define INTR 8
extern void putchar(char c);
extern void pokeW(unsigned int segment, unsigned int offset, unsigned int value);
volatile static unsigned char secFlag;

void interrupt ManejadorISR( void ){
    static unsigned char cont = 0;
    cont++; /*ticks counter*/
    if(cont == 20){
        secFlag = 1;
        cont = 0;
    }
}

unsigned char TimerSecFlag( void ){
    if( secFlag ){
        secFlag = 0;
        return 1;
    }else
        return 0;
}

void Timer_Ini( void ){
    secFlag = 0;
    pokeW(0x0, INTR*4, offset de la ISR); /*Determinar offset*/
    pokeW(0x0, INTR*4+2, _CS);
}

