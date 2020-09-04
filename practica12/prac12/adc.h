#ifndef _ADC_H
#define _ADC_H
#define delay_count 16000000/4000
#define LED_P (1<<PF4)
#define LED_M (1<<PF5)
#include <inttypes.h>

void ADC_Init(void);
uint16_t ADC_Read( uint8_t channel );
uint16_t measureDischargeTime( void );
void delay(uint8_t ms);
void init_port( void );
void PrintAdc(void);
void blink(void);

#endif 
