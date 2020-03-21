#define BYTE unsigned char
#define WORD unsigned int
#define PA 0x40
#define PB 0x41
#define PC 0x42
#define RCtr 0x43
#define PTOs_all_out 0x80
#define PA_PB_OUT 0x89
#define PB_PC_OUT 0x90
#define PC_PA_OUT 0x82

/*ASM Routines*/
extern char getch(void);
extern void putchar(char c);
extern BYTE inportb(WORD port);
extern void outportb(WORD port, BYTE dato);
extern void clrscr(void);
/*C functions*/
void printBin( BYTE dato );
BYTE getData(void);
void puts(char *Str);
void SetBitPort(WORD Puerto, BYTE num_bit);
void ClrBitPort(WORD Puerto, BYTE num_bit);
void NotBitPort(WORD Puerto, BYTE num_bit);
BYTE TstBitPort(WORD Puerto, BYTE num_bit);
void ReverseBitsPort(WORD Puerto);
void delay(BYTE time);
void setOnLed(BYTE Port_ON, BYTE Port_OFF);
void printLeds(BYTE data);

void main( void ){
    BYTE data;
    while(1){
        data = getData();
        puts("\n\r");
        printBin(data);
        printLeds(data);
        getch();
        clrscr();
    }
}
void printBin( BYTE dato ){
    BYTE msk=0x80;
    do{
        putchar( (dato & msk) ? '1' : '0' );
        msk>>=1;
    }while( msk );
}
void puts(char *str){
    while (*str){
        putchar(*str++);
    }
    
}
BYTE getData(void){
    BYTE bits, i, aux;
    i = bits = 0;
    outportb(RCtr,0x9B);
    puts("Captura de bits\n\r\n\r");

    while(i < 8){
        puts(" Bit ");
        putchar(i + '0');
        putchar(':');
        putchar(' ');
        getch();
        aux = TstBitPort(PC,4);
        bits |= (aux<<i);
        putchar(aux+'0');
        puts("\n\r");
        i++;
    }
    return bits;
}

/*Given a bit number of a specific, set the bit*/
void SetBitPort(WORD Puerto, BYTE num_bit){
    outportb( Puerto , inportb( Puerto )|( 0x01 << num_bit ) );
}
/*Given a bit number of a specific, clear the bit*/
void ClrBitPort(WORD Puerto, BYTE num_bit){
    outportb( Puerto , inportb( Puerto )&( ~(0x01) << num_bit ) );
}
/*Given a bit number of a specific, invert the bit*/
void NotBitPort(WORD Puerto, BYTE num_bit){
    outportb( Puerto , inportb( Puerto )^( (0x01) << num_bit ) );
}
/*Given a bit number of a specific Port, return the value of that bit*/
BYTE TstBitPort(WORD Puerto, BYTE num_bit){
    BYTE bit = (inportb(Puerto) & (0x01 << num_bit)) ?  1: 0;
    return bit;
}
/*Given a Port, reverse the bits. Eg: 1101 0110 -> 0110 1011*/
void ReverseBitsPort(WORD Puerto){
    unsigned char i = 0;
    while ( i<8 ){
        if( TstBitPort(Puerto, 0x01<<i) ){
            SetBitPort(Puerto,i);
        }else 
            ClrBitPort(Puerto, i);
        i++;
    }
}
void delay(BYTE time){
    while(time--);
}
void setOnLed(BYTE Port_ON, BYTE Port_OFF){
    SetBitPort(Port_ON, 1);
    ClrBitPort(Port_OFF, 1);
}
void printLeds(BYTE data){
    BYTE i = 0, aux;
    while (1){
        aux = data & (0x01<<i);
        if (aux){
            if(i == 0 || i == 1){
                outportb(RCtr, PA_PB_OUT);
                if(i == 0)
                    setOnLed(PB,PA);
                else
                    setOnLed(PA, PB);
            }else if (i == 2 || i == 3){
                outportb(RCtr, PB_PC_OUT);
                if(i == 2)
                    setOnLed(PC, PB);
                else
                    setOnLed(PB, PC);
            }else{
                outportb(RCtr, PC_PA_OUT);
                if(i==4)
                    setOnLed(PA,PC);
                else
                    setOnLed(PC, PA);
            }delay(1000);
        }i = ++i % 6;   
    }
}