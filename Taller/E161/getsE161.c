/*
Alumno:Caudillo Sanchez Diego
Matricula: 1249199
Materia:Microcontroladores y microprocesadores
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define BYTE unsigned char
struct keypad{
    BYTE qty; /*cantidad de caracteres que tiene la tecla*/
    BYTE counter; /*contador de la tecla actual*/
    BYTE alt[5]; /*caracteres alternos que tiene la tecla*/
};
typedef struct keypad keypad_t;

void getsE161( char *str );
BYTE toUpper(BYTE c);
BYTE toLower(BYTE c);
void clear (void);
void clearCounter(void);
void backspace(void);

keypad_t keyboard[13] = {
        {1, 0, {'0'}},                {1, 0,{'1'}},                  {4, 0, {'2','A','B','C'}}, 
        {4, 0, {'3','D','E','F'}},    {4, 0,{'4','G','H','I'}},      {4, 0, {'5','J','K','L'}}, 
        {4, 0, {'6','M','N','O'}},    {5, 0,{'7','P','Q','R','S'}},  {4, 0, {'8','T','U','V'}}, 
        {5, 0, {'9','W','X','Y','Z'}}, {1,0,{'*'}},{1,0,{'#'}}
    }; 

int main(int argc, char const *argv[]){ 
    char str[80] ;
    getsE161(str);
    puts(" ");
    system("cls");
    puts("*** Mensaje final ***");
    puts(str);
    
    return 0;
}

/*Funcion que convierte de minusculas a mayusculas*/
BYTE toUpper(BYTE c){
    return (c >= 'a' && c <= 'z') ? c-32 : c;  
}
/*Funcion que convierte de mayusculas a minusculas*/
BYTE toLower(BYTE c){
    return (c >= 'A' && c <= 'Z') ? c+32 : c; 
}

/*Funcion que es teclado */
void getsE161(char *str){
    BYTE i,key, upper = 0, aux, c;
    const char *const str_aux = str;
    do{
        while ( kbhit() ){
            key = getch(); /*Recibe la tecla pulsada por el usuario*/
            if(toUpper(key) != 'A'){
                /*Revisa en el arreglo de teclas si se encuentra la tecla pulsada*/
                for(i = 0; i < 13; i++){
                    /*En caso de que se haya pulsado la mismca tecla 
                    mas de una vez, se actualiza el nuevo caracter*/
                    if(keyboard[i].counter == keyboard[i].qty)
                        keyboard[i].counter = 0;
                    if(key == keyboard[i].alt[0]){
                        backspace();
                        c = keyboard[i].alt[keyboard[i].counter];
                        /*imprime en minusculas si la bandera es 0
                        de lo contrario imprime en mayusculas*/
                        if(!upper){
                            putchar( toLower(c) );
                            *str = toLower(keyboard[i].alt[keyboard[i].counter]);
                        }else {
                            putchar( toUpper(c) );
                            *str = toUpper(keyboard[i].alt[keyboard[i].counter]);
                        }
                        /*Accede al siguiente caracter de la tecla pulsada*/
                        keyboard[i].counter++;  
                        break; 
                    }
                    switch ( toUpper(key) ){
                        case 'B':    
                            *str = 0;
                            if(str_aux != str)
                                str--;
                            break;
                        case 'C': upper = !upper;
                            break;
                        case 'D': key = 13;
                            break;
                    }
                }
            }else{
                clearCounter();
                putchar(' ');
                str++;
            }
            aux = key;
        }
    } while (key != 13);
    *str++ = '\0';
}
/*Funcion que reinicializa los contadores
de la posicion de cada tecla*/
void clearCounter(void){
    for(BYTE i = 0; i<13 ; i++)
        keyboard[i].counter = 0;
}
void backspace(void){
    putchar(8);
    putchar(' ');
    putchar(8);
}