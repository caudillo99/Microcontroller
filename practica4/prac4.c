/*
Practica 4. Decodificadores de memoria
Diego Caudillo Sanchez
uPyuC
*/
typedef unsigned char BYTE;
typedef unsigned int WORD;
/*Declaring ASM procedures*/
extern char getchar(void);
extern void putchar(BYTE c);
extern BYTE peek(WORD segment, WORD offset );
extern void poke(WORD segment, WORD offset , BYTE data);
/*Header functions*/
WORD checkAddressBus(WORD segment, WORD offset, BYTE lines);
BYTE checkDataBus(WORD segment, WORD offset);
void dataBusStatus(BYTE busLines, BYTE address_lines);
void addressBusStatus(WORD busLines, BYTE data_lines);
void checkMemoryAddress(WORD segment, WORD offset, WORD last_address, WORD *fail_address);
void puts(char *str);
void printToBase(WORD data, BYTE base);

const BYTE ADDRESS_LINES = 11;
const BYTE DATA_LINES = 8;
const WORD OFFSET = 0x2200;
const BYTE SEGMENT = 0;
const WORD MAX_OFFSET = 0x7FF;

void main() {
    while (1){
        addressBusStatus(checkAddressBus(SEGMENT, OFFSET, ADDRESS_LINES), ADDRESS_LINES);
        dataBusStatus(checkDataBus(SEGMENT, OFFSET), DATA_LINES);
        getchar();
    }
}

WORD checkAddressBus(WORD segment, WORD offset, BYTE lines){
    WORD status = 0, memLocation;
    BYTE pattern = 0xAA;
    /*Filling each line to zero*/
    for (memLocation = 1 ; memLocation < (1<<lines) ; memLocation <<= 1){
        poke(segment, offset+memLocation, status);
    }
    poke(segment, offset, pattern);
    /*Checking all the addresses bus lines*/
    for ( memLocation = 1 ; memLocation < (1<<lines) ; memLocation <<= 1 )
    {
        if( peek(segment, offset + memLocation) == pattern || peek(segment, offset + memLocation) ){
            status |= memLocation;
        }
    }
    checkMemoryAddress(segment, offset, MAX_OFFSET, &status);
    return status;
}

void checkMemoryAddress(WORD segment, WORD offset, WORD last_address, WORD *fail_address){
    WORD memLocation, aux_memLocation;
    BYTE data = 1, data_tmp;
    for ( memLocation = 1; memLocation < last_address; memLocation <<= 1){
        poke(segment, offset, 0xFF);
        poke(segment, offset + memLocation, data);
        for (aux_memLocation = memLocation; aux_memLocation < last_address; aux_memLocation <<= 1){
            if (aux_memLocation != memLocation){
                data_tmp = peek(segment, offset+aux_memLocation);
                if(data == data_tmp)
                    *fail_address |= memLocation;
            }
        }
        data_tmp = peek(segment, offset+memLocation);
        if(data_tmp != data)
            *fail_address |= memLocation;
        
        data_tmp = peek(segment, 0);
        if(data_tmp == data)
            *fail_address |= memLocation;
        data++;
    }
}

BYTE checkDataBus(WORD segment, WORD offset){
    BYTE pattern, busLine=0;
    for (pattern = 1; pattern; pattern <<= 1){
        poke(segment, offset, pattern);
        if(peek(segment, offset) != pattern)
            busLine |= pattern;
    }
    return busLine;
}
void addressBusStatus(WORD busLines, BYTE address_lines){
    WORD index = 0;
    puts("<<<<<< ADDRESS BUS TEST>>>>>>>");
    puts("\r\n");
    while (index < address_lines){
        puts("LINE ");
        putchar( (index < 10)? index+'0' : index+'0'+7 );
        puts(":");
        if (busLines & (0x0001 << index))
            puts("Error");
        else
            puts("OK!");
        puts("\r\n");
        index++;
    }
    
    puts("\r\n");
    puts("<<<<<< MEMORY ADDRESS TEST>>>>>>>");
    puts("\r\n");
    printToBase(busLines, 2);
    puts("\r\n");
    puts("\r\n");
}
void dataBusStatus(BYTE busLines, BYTE data_lines){
    BYTE index = 0;
    puts("<<<<<<DATA BUS TEST>>>>>>>");
    puts("\r\n");
    while (index < data_lines){
        puts("LINE ");
        putchar(index+'0');
        puts(":");
        if (busLines & (0x01 << index))
            puts("Error");
        else
            puts("OK!");
        puts("\r\n");
        index++;
    }
}

void puts(char *str){
    while (*str){
        putchar(*str++);
    }   
}

void printToBase(WORD data, BYTE base){
    BYTE aux;
    while (data)
    {
        aux = data%base;
        if(aux > 9) 
            aux += '0'+ 7;
        else 
            aux += '0';
        putchar(aux);
        data /= base;
    }
}