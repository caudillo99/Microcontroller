#ifndef UART
#define UART

#include <inttypes.h>
/* QUEUE SIZE*/
#define BUFFER_SIZE 64

typedef struct {
  char buffer[BUFFER_SIZE];
  volatile unsigned char head; /**head**/
  volatile unsigned char tail; /**tail**/
}ring_buffer_t;


/**BOOL VALUES*/
enum bool{false,true};

/** ANSI color codes **/
enum color {BLACK = 30, RED, GREEN, YELLOW, BLUE, MANETA, CYAN, WHITE};

  /** PROTOTYPES **/
void UART_init(uint8_t com, uint16_t baud_rate, uint8_t size, uint8_t parity, uint8_t stop);
void UART_putchar(uint8_t com,char data);
char UART_getchar(uint8_t com);
void UART_puts(uint8_t com, char *str);
void UART_gets(uint8_t com, char *str);
uint8_t UART_available(uint8_t com);
void UART_gotoxy(uint8_t com, uint8_t x, uint8_t y);
void UART_setColor(uint8_t com, uint8_t color);
void UART_clrscr(uint8_t com);
unsigned int atoi(const char *str);
void itoa(char *str, uint64_t number, unsigned char base);
void UART0_AutoBaudRate( void );


/**MACRO FUCNTIONS*/
#define FREQ 16000000
#define OUTPUT_BUFFER_FULL ((output_queue.head) == ((output_queue.tail+1) % BUFFER_SIZE))
#define OUTPUT_BUFFER_EMPTY (output_queue.head == output_queue.tail)

#define INPUT_BUFFER_FULL ((input_queue.head) == ((input_queue.tail + 1) % BUFFER_SIZE))
#define INPUT_BUFFER_EMPTY (input_queue.head == input_queue.tail)

#endif
