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
    outportb(CtlReg, 0x89);/*Setting the control register*/
    outportb(PA, i); /*Displaying a zero*/
    while (1){
        /*checking the buttons to increase or decrease 
        the display value*/
        if( (inportb(PC) & 0x03) == 0x02){
            if( i < 9)
                i++; 
        }
        if( (inportb(PC) & 0x03) == 0x01){
            if( i > 0)
                i--;
        }
        delay(1);
        /*Counting time until 200 ms to update the display*/
        ms++;
        /*Update the display*/
        if( ms == 200 ){
            displayDato(i);
            ms = 0;
        }
    }
}

void displayDato(BYTE n){
    static BYTE display7seg[9] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};
    outportb(PA, display7seg[n]);
}