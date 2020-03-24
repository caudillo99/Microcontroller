#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define BYTE unsigned char
struct keypad{
    BYTE qty;
    BYTE counter;
    BYTE alt[5];
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
    puts(">>>Mensaje final<<<");
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
                    if(key == keyboard[i].alt[0]){
                         /*En caso de que se haya pulsado la mismca tecla 
                        mas de una vez, se actualiza el nuevo caracter*/
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
                        /*Mientras el contador de caracteres que contiene cada tecla
                        se menor, se aumenta el contador con el fin de mostrar el 
                        siguiente caracter. Una vez que llega al maximo se reinicializa a 0*/
                        keyboard[i].counter += (keyboard[i].counter<keyboard[i].qty)? 1 : -keyboard[i].qty;  
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