#include <avr/io.h>
#include <inttypes.h>

#define ROW 3
#define COL 3
#define NOT_PRESSED 10
#define delay_count 16000000/4000
#define SIMON_ACTIONS 6
#define setBitPort(port,bit) __asm__("sbi %0,%1" : :"I" ((uint8_t) (_SFR_IO_ADDR(port))) , "I" ((uint8_t) (bit)))
#define clrBitPort(port,bit) __asm__("cbi %0,%1" : :"I" ((uint8_t) (_SFR_IO_ADDR(port))) , "I" ((uint8_t) (bit)))

/*Functions headers*/
void Initial_state( void );
void led_off(void);
void delay(uint8_t ms);
void simonSays( void );
uint8_t randomNumber( uint8_t seed );
void initPorts( void );
uint8_t getButton( void );
void TurnOnLED( uint8_t led );
void winner( void );
void loser( void );
void low( void );
void TurnOnLEDDDDD( uint8_t led );

/*Global variables*/
uint8_t simonsMemory[SIMON_ACTIONS+1];

/*main program*/
int main(){
    while (1){
        Initial_state();
        simonSays();
    }
    return 0;
}

void Initial_state( void ){
    uint8_t button;
    do{
        winner();
        button = getButton();
    }
    while (button == NOT_PRESSED);
    delay(250);
    delay(250);

}

/*delay function*/
void delay(uint8_t ms){
    uint16_t cnt;
    asm volatile(
        "\n"
        "L_dl1%=:"      "\n\t"
        "mov %A0, %A2"  "\n\t"
        "mov %B0, %B2"  "\n\t"
        "L_dl2%=:"      "\n\t"
        "sbiw %A0, 1"   "\n\t"
        "brne L_dl2%="  "\n\t"
        "dec %1"        "\n\t"
        "brne L_dl1%="  "\n\t"
        : "=&w" (cnt)
        : "r" (ms), "r" (delay_count)
    );
}

/*Simon Say Game*/
void simonSays( void ){
    uint8_t idx = 0, i, button, win = 1, seed;
    seed = randomNumber(1);
    while ( (idx < SIMON_ACTIONS) && win ){
        simonsMemory[idx] = randomNumber(seed);
        seed = simonsMemory[idx];
        /*Shows the led sequency of Simons memory*/
        for(i = 0; i <= idx; i++){
            TurnOnLED(simonsMemory[i]);
            delay(250);
            delay(250);
            delay(250);
            led_off();
            delay(250);
            delay(250);
        }
        /*Get the button sequence press by the user*/
        for ( i = 0; i <= idx; i++){
            do{
                delay(20);
                button = getButton();
            } while (button == NOT_PRESSED);
            TurnOnLED(button);
            delay(250);
            delay(250);
            led_off();
            delay(250);
            /*If the user pressed the wrong button, a loser led sequence starts blinking*/
            if( button != simonsMemory[i] ){
                button = NOT_PRESSED;
                while (button == NOT_PRESSED)
                {
                    delay(5);
                    button = getButton();
                    loser();
                }
                
                win = 0;
                break;
            }
        }idx++;
    }if(win)
        winner();
}

void led_off( void ){
    PORTF = 0;
    DDRF = 0;
}

/*Pseudo random number generator*/
uint8_t randomNumber( uint8_t x ){
    /*Xn+1 = (aXn + c) mod m*/
    uint8_t m = 8, c = 3, a = 1 ;
    return (( (a*x)+c)%m);
}

/*Initialize AVR Ports*/
void initPorts( void ){
    /*
    DDK0 = 1 (OUTPUT)   PK0 = 0 (Logic 0)
    DDK1 = 1 (OUTPUT)   PK1 = 0 (Logic 0)
    DDK2 = 1 (OUTPUT)   PK2 = 0 (Logic 0)
    DDK3 = 0 (INPUT)    PK3 = 1 (Pxn)
    DDK4 = 0 (INPUT)    PK4 = 1 (Pxn)
    DDK5 = 0 (INPUT)    PK5 = 1 (Pxn)
    DDK6 = x            PK6 = x 
    DDK7 = x            PK7 = x 
    */
    DDRK = (1<<DDK0)|(1<<DDK1)|(1<<DDK2);
    delay(1);
    PORTK = (1<<PK5)|(1<<PK4)|(1<<PK3);
}


/*Get the current button pressed by the user; if no button pressed, return 10*/
uint8_t getButton( void ){
    uint8_t key = NOT_PRESSED;
    initPorts();
    uint8_t i,j;
    for ( i = 0; i < ROW; i++){
        PORTK = ~(1<<i);
        delay(10);
        for( j = 0; j < COL; j++){
            /*Debido a que mis conexiones del teclado use PK3 a PK5 (columnas) para identificar
            que boton se esta presionando, se hace un offset de 3 (COL) para aseguarme que la mascara solo se
            enfocara en traer los bits del puerto necesarios.*/
            if( !(PINK & (1<<(j+COL))) ){
                key = (i*ROW)+j;
                break;
            } 
        }
        PORTK |= (1<<i); 
        delay(10);
        if(key != NOT_PRESSED)
            break;
    }
    return key;
}
/**/
void TurnOnLED( uint8_t led ){
    uint8_t i = led;
    DDRF = 0x00;
    PORTF = 0x00;
    if( i < 8 ){
        if(i == 0 || i == 1){
            DDRF |= (1<<DDF1) | (1<<DDF0);
            if( i == 0 )
                setBitPort(PORTF, PF1);
            else
                setBitPort(PORTF, PF0);
        }else if (i == 2 || i == 3){
            DDRF |=  (1<<DDF1)|(1<<DDF2);
            if(i == 2)
                setBitPort(PORTF, PF2);            
            else
               setBitPort(PORTF, PF1);
        }else if(i == 4 || i == 5){
            DDRF |= (1<<DDF0)|(1<<DDF2);
            if(i == 4)
               setBitPort(PORTF, PF0);
            else
               setBitPort(PORTF, PF2);
        }else{
            DDRF |= (1<<DDF3)|(1<<DDF2);
            if(i == 6)   
                setBitPort(PORTF, PF3);
            else
                setBitPort(PORTF, PF2);
        }
    }
}

void winner( void ){
    int led_idx = 7;
    /* cambiar led_idx por getkey() dentro del while */
    while (led_idx >= 0){
        TurnOnLED(led_idx);
        delay(80);
        if(led_idx >= 0)
            led_idx--;
        else
            led_idx = 7;
    }
}

void loser( void ){
    /* cambiar led_idx por getkey() dentro del while */
    uint8_t led = 0xFF, aux, i=0;
    aux = led & (1 << i);
    if( aux ){
        TurnOnLED(i);
    }
    i++;
    i = i%8;
}

