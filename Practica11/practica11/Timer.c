#include <avr/interrupt.h>
#include <inttypes.h>
#include "Timer.h"
#include "song.h"
#include "UART.h"

uint32_t ms = 0; /*time in milliseconds*/
uint32_t silence_start = 0;
uint16_t played_notes = 0;
uint8_t play = 0; /*0 means not playing a song; 1 means playing a song*/
uint8_t volume_idx = 0;
uint8_t pause = 0;
uint8_t first = 0;
uint8_t volume[] = {0,1,2,8,20,50};
/* 	Permanece igual, ocasionando una interrupción 
	cada 1 ms en modo CTC. */
void Timer0_Ini ( void ){
	DDRB |= (1 << PB7); //OC0A
    TCNT0 = 0x00 ;     //Initialize the counter
    OCR0A = 249; //Set the TOP value
    TCCR0A |= (1<<WGM01);  //ctc mode
    TCCR0B |= (1<<CS00) | (1<<CS01);//Timer0 start 64 prescaler
    TIMSK0 |= (1<<OCIE0A); //Timer/Counter0 Output Compare Match A Interrupt Enable

	sei();
}

ISR(TIMER0_COMPA_vect){
	ms++; /*Update time*/
	if(play){
		if(!pause){
			if( (ms - current_song.note_start_time) >= current_song.current_note.delay ){
				pause = 1; /*Set pause flag*/
				silence_start = ms; /*At this time, the silence started*/
				Timer2_Freq_Gen( 0 ); /*The volume is 0*/

				/*Read next note to be played*/
				current_song.current_note.freq  = pgm_read_word(current_song.head + (played_notes*4) ); /*points at freq*/
				current_song.current_note.delay = pgm_read_word(current_song.head + ((played_notes*4)+2) );
				played_notes++;

				/*When the song get at the final note it resets the counters*/
				if(played_notes - 1 == current_song.size){
					play = 0;
					played_notes = 0;
				}
			}
		}
		else if ( (ms - silence_start) >= SILENCE){	/*Set a delay of 10ms to distinguish between notes*/
			pause = 0; /*Disable pause flag*/
			if(current_song.current_note.freq){
				Timer2_Freq_Gen(TICKS(current_song.current_note.freq)); /*Set the frequency of a given notes*/
				current_song.note_start_time = ms; /* */
			}
		}
	}
}

/* Si "ticks" es mayor que 0 entonces, inicializa y habilita el
Generador de Frecuencia del Timer2 con el tope dado por "ticks".
De lo contrario se requiere deshabilitar el Generador, generando de
esta forma el silencio (0 lógico). */
void Timer2_Freq_Gen(uint8_t ticks){
	if( !ticks ){
		TCCR2B = 0; /*Timer 2 Off*/
	}else{
		TCCR2A = (1 << WGM21) | (1 << WGM20) | (1 << COM2B1); /*Fast PWM; Clear OC2B on Compare Match*/
		TCCR2B = (1 << WGM22) | (1 << CS22)|(1 << CS21); /*Set prescaler at 1024*/
		OCR2A = ticks - 1; /*Set the TOP*/
		Timer2_Volume(0);
	}
}

/* Función que establece las condiciones necesarias para que
el generador recorra el arreglo de notas. */
void Timer2_Play(const note_t song[], uint16_t len){
	/*Gettin' the current song of the list*/
	current_song.head = song;
	current_song.size = len;

	/*Take in mind that we work in little endian, so the first word is equal to the frecuency 
	that's store in Memory Program, so we need to do an offset of 2 to get at the delay value */
	current_song.current_note.freq  = pgm_read_word(&song[0]); /*Points at the freq  */
	current_song.current_note.delay = pgm_read_word(&song[2]); /*Points at the delay */

	/*Sets flags that indicates the start of the first song*/
	play  = 1;
	first = 1;
	played_notes = 0;
}

/* Ajusta el ciclo de trabajo para incrementar o decrementar, de forma
logarítmica, el volumen de las notas que se están generando. */
void Timer2_Volume(int8_t direction){
	if( (direction == VOL_UP) && ((volume_idx+1) < 6) ){
		volume_idx++;	
	}else if ( (direction == VOL_DOWN) && ( 0 <= (volume_idx-1) ) ){
		volume_idx--;
	}

	if( !volume[volume_idx] ){
		TCCR2B = 0; /*Timer 2 Off*/
	}else if (play){
		TCCR2B = (0x07 << CS00) | (1 << WGM22); /*Prescaler set to 1024*/
		OCR2B = (OCR2A*volume[volume_idx])/100;
	}
}
