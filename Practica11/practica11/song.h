#ifndef _SONGS_H
#define _SONGS_H
#include <avr/pgmspace.h>

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 494
#define aa 	493
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
#define hH 	987
#define bL 247
#define fS 370
#define cS 277
#define aL 220
#define gL 196
#define dS 311
#define gSL 208
#define cL 131
#define eL 165
#define aSL 233

/*Tempos*/
#define TEMPO	500
#define TEMPO_500 500
#define TEMPO_250 250
#define TEMPO_600 600
#define SILENCE 10

#define TOTAL_SONGS 5

/*Note structure*/
struct note{
	uint16_t freq;
	uint16_t delay;
};
typedef struct note note_t ;

/*song structure*/
struct song{
    PGM_P head;     /*pointer to a string in program space*/
    uint16_t size;  /*Total of notes*/
    uint32_t note_start_time;
    note_t current_note;
};
typedef struct song song_t;

/* Songs */
extern PROGMEM const note_t ImperialMarch[];
extern PROGMEM const note_t AngelesAzules[];
extern PROGMEM const note_t DragonBallGT[];
extern PROGMEM const note_t Clocks[];
extern PROGMEM const note_t Mario[];
extern PGM_P const playlist[];

/*Index*/
const uint8_t song_cnt;
extern uint8_t song_idx;
extern song_t current_song;

/*Array that contains the quantity of notes 
of all the songs in the playlist*/
extern const uint16_t songs_size[];

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#define GET_TOTAL_SONGS (ARRAY_SIZE(playlist))
#define VOL_UP 1
#define VOL_DOWN -1

#endif
