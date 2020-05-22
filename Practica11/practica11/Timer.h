#ifndef _TIMER_H
#define _TIMER_H
#include "song.h"

#define TEMPO	500
#define SILENCE 10
#define PRESCALER 1024
#define TICKS(f) ((16000000/PRESCALER)/(f))


void Timer0_Ini ( void );
void Timer2_Freq_Gen(uint8_t ticks);
void Timer2_Play(const struct note song[],unsigned int len);
void Timer2_Volume(int8_t direction);

#endif
