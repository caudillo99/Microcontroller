#define BYTE unsigned char
#define WORD unsigned int
#define PA 0x40
#define PB 0x41
#define PC 0x42
#define RCtr 0x43
#define PTOs_all_out 0x80
/*ASM Routines*/
extern void puts(char *Str);
extern char getch(void);
extern BYTE inportb(WORD port);
extern void outportb(WORD port, BYTE dato);
/*C functions*/
void SetBitPort(WORD Puerto, BYTE num_bit);
void ClrBitPort(WORD Puerto, BYTE num_bit);
void NotBitPort(WORD Puerto, BYTE num_bit);
BYTE TstBitPort(WORD Puerto, BYTE num_bit);
void ReverseBitsPort(WORD Puerto);
char dato;

void main( void ){
    puts("Practica 5b\n\r"); /* imprimir mensaje */
    outportb(RCtr, PTOs_all_out); /* inicializar 8255 */
    outportb(PA,0x55); /* presentar 55h en el Pto A */
    while(1){
        dato = getch(); /* leer tecla */
        outportb(PB,dato); /* presentar tecla en PB */
        printBin(dato);
        puts("\n\r");
    }
}
/* función simple para desplegar un byte en formato binario */
void printBin( BYTE dato ){
    BYTE msk=0x80;
    do{
        putchar( (dato & msk) ? '1' : '0' );
        msk>>=1;
    }while( msk );
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
