#include "UART.h"
#include "Timer.h"
#include "song.h"
#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	char song_names[][20] = {"ImperialMarch",
		"AngelesAzules",
		"DragonBallGT",
		"Clocks",
		"Mario"
	};
	char str[10];
	sei();
	UART_init(0,0,8,1,2);
    UART0_AutoBaudRate();
    UART_clrscr(0);
    UART_gotoxy(0,5,1);
    UART_puts(0,"Autobauding Done. UBRR =");
    itoa(str,UBRR0 ,10);
    UART_puts(0, str);
    UART_puts(0, "\n\r");
	
	Timer0_Ini();
	DDRH |= (1<<PH6);
	
	while(1){
		if ( UART_available(0) ){
			
			switch (UART_getchar(0)){
				case 'p':
				// Play Song
				case 'P': 
					UART_clrscr(0);
    				UART_gotoxy(0,5,1);
					UART_puts(0, "Now playing:");
					UART_puts(0, song_names[song_idx]);
					UART_puts(0,"\r\n");
					Timer2_Play(playlist[song_idx], songs_size[song_idx]);
					break;
				//Increase Volume
				case 'V': 
					Timer2_Volume(VOL_UP);
					break;
				//Decrease Volume
				case 'v':
					Timer2_Volume(VOL_DOWN);
					break;
				//Next song
      			case 'n':
				case 'N': 
					song_idx = (song_idx+1)%song_cnt;
					Timer2_Play(playlist[song_idx], songs_size[song_idx]);
					UART_clrscr(0);
    				UART_gotoxy(0,5,1);
					UART_puts(0, "Now playing:");
					UART_puts(0, song_names[song_idx]);
					UART_puts(0,"\r\n");
					break;
				//Previous song
				case 'b':
      			case 'B':
				  	song_idx = (!song_idx ) ? song_cnt-1 : song_idx-1;
					Timer2_Play(playlist[song_idx], songs_size[song_idx]);
					UART_clrscr(0);
		    		UART_gotoxy(0,5,1);
					UART_puts(0, "Now playing:");
					UART_puts(0, song_names[song_idx]);
					UART_puts(0,"\r\n");
					break;
				//
      			default:
						break;

			}
		}
	}
	return 0;
}
