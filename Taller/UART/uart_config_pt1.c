#include <avr/io.h>
#define UCSRB 0X01
#define UCSRC 0X02
#define UBBRL 0x04
#define UBBRH 0x05
#define FREQ  16000000
uint8_t UART_Config (uint8_t com, uint16_t velocidad, uint8_t ndatos, uint8_t paridad, uint8_t bit_paro);
void main( void ){
    UART_Config (0, 19200, 8, 1, 1);
}

uint8_t UART_Config (uint8_t com, uint16_t velocidad, uint8_t ndatos, uint8_t paridad, uint8_t bit_paro){
    uint8_t *USART, UCSZ = 0X01, USBS = 0X03, UPM = 0X04, status;
    uint32_t BAUD;
    USART = (uint8_t*)(0xC0 + (com*8)); /*Apunta al USART (0,1,2 o 3)*/
    BAUD = FREQ / (uint32_t)(16*(uint32_t)velocidad - 1);
    *(USART+UCSRB) = (uint8_t);
    if( (com>=0 || com <=3) && (velocidad>=300 || velocidad<=115200)  && (ndatos>=5 || ndatos<=8) && (paridad>=1 || paridad<=2) && (bit_paro==1 || bit_paro==2) ){
        /*Set frame format*/
        *(USART+UCSRC) = (uint8_t)((bit_paro << USBS) | ((ndatos-0x05) << UCSZ) | (paridad << UPM));
        /*Set baud rate*/
        *(USART+UBBRL) = (uint8_t)BAUD;
        *(USART+UBBRH) = (uint8_t)(BAUD >> 8);
        status = 1;
    }else
        status = 0;
    return status;
}