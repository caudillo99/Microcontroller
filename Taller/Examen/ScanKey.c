/*
Alumno: Caudillo Sanchez Diego
Matricula: 1249199
Materia: Microcontroladores y microprocesadores
Ejercicio - ScanKey
Docente: Dr. Leocundo Aguilar Noriega
Fecha de entrega: 19/06/2020
*/

#define ROWS 4
#define COLS 4
#define NOT_PRESSED -1

#define PA 0x40
#define PB 0x41
#define PC 0x42

#define BYTE unsigned char
#define WORD unsigned int

/*Descripción: Función que rastrea y determina que tecla ha sido oprimida.
Parámetros: Ninguno
Valor de retorno: Retorna un dato de tipo char, indicando la tecla oprimida en el teclado. Caso contrario retorna -1, indicando que no se encontró tecla presionada.
*/
char key( void );

char key( void ){
    BYTE i, j;
    char key = NOT_PRESSED;

    for ( i = 0; i < ROWS; i++){
        /*Debido a la configuración del circuito del teclado,
        se van probando (Set bit) las columnas (PC1-PC4). Con
        el fin de indentificar si alguna columna (PC4-PC7) se
        enciende (1 lógico)*/
        ClrBitPort(PC, i+ROWS);
        /*Se van reccoriendo los renglones en busca de un 0 lógico 
        en alguno de los puertos correspodientes (PC1-PC4)*/
        for ( j = 1; i <= COLS; j++){
            if( !GetBitPort(PC, j+COLS) ){
            /*Si se encuentra un 0 en algún renglón, para determinar
            el valor de la tecla basta con multiplicar el valor del indice
            de los renglones (i), y sumandole el valor de la columna (j).*/
                key += (i*ROWS) + j;
                break;
            }
        }
        /*Se apaga el bit de la columna probada*/
        SetBitPort(PC, i);
        /*Sale del ciclo en caso de haber encontrado la tecla presionada*/
        if (key != NOT_PRESSED)
            break;
    }
    return key;
}
