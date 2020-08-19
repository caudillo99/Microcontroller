#include <inttypes.h>

#define NOT_PRESSED 1
#define ROW 3
#define COL 3
uint8_t getKey( void );

uint8_t getKey(){   
    uint8_t key = NOT_PRESSED, mask;
    uint8_t i, j;
    mask = 0xfe;
    for ( i = 0; i < ROW; i++){
            
        for ( j = 0;  j < COL; j++){
        }
        
        /* code */
    }
    

} 