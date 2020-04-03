#define INTR 8
#define MAPPED_PORT 0xffff

#define enter() putchar('\n'),putchar('\r')


typedef unsigned int WORD;
typedef unsigned char BYTE;

BYTE TimerSecFlag(void);
void Timer_Ini(void);

extern void pokeW(WORD seg, WORD offset, WORD value);
extern void poke(BYTE seg, BYTE offset, BYTE value);
extern void putchar(BYTE c);
