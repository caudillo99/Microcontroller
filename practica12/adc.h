#ifndef ADC_H
#define ADC_H

#include <inttypes.h>

void ADC_Init(void);
uint16_t ADC_Read( uint8_t channel );
uint16_t measureDischargeTime( void );


#endif // !ADC