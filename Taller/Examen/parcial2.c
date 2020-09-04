#include <inttypes.h>
#define PC 0x42
#define TOTAL_OUTPUTS 6
int main() {
    while (1){
    }
    
    return 0;
}

/*El dato se debe introducit por bit
Sacar por el PC4*/
void WriteLCD( uint8_t tipo, uint8_t dato){
    uint8_t i=0;
    if( tipo )
        SetBitPort(PC, 0);
    else
        ClrBitPort(PC, 0);
    while(i < TOTAL_OUTPUTS){
        //Verifica el valor del bit
        if( dato & (1<<i))
            SetBitPort(PC,4);
        else     
            ClrBitPort(PC,4);
        //Cambio de en flanco de bajada
        SetBitPort(PC,1);
        ClrBitPort(PC,1);
        i++;
    }
}