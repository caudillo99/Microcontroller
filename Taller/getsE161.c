#include<stdio.h>
#include<conio.h>

struct keypad{
    char key;
    unsigned char qty;
    unsigned char counter;
};
typedef struct keypad keypad_t;
void getsE161( char *str );


int main(int argc, char const *argv[]){ 
    char str[80];
    
    getsE161(str);
    return 0;
}

char getKey(void){
    return ( kbhit() ? getch() : 0);
}

/*
DUDA: COMO ES LA VERIFICACION PARA ESCRIBIR EL SIGUIENTE CARACTER?
SE TENDRA QUE PRESIONAR A(ADVANCE) CADA QUE SE QUIERA ESCRIBIR OTRO
CARACTER O CUANDO SE PRESIONA OTRA TECLA DISTINTA A LA ANTERIORMENTE
PRESIONADA, AVANZA A LA ESCRITURA DEL NUEVO CARACTER?
*/
void getsE161(char *str){
    unsigned char i;
    keypad_t keyboard[16] = {
        {'1', 1, 0},{'2', 3, 0},{'3', 3, 0},{'A', 3, 0},
        {'4', 3, 0},{'5', 3, 0},{'6', 3, 0},{'B', 3, 0},
        {'7', 4, 0},{'8', 3, 0},{'9', 4, 0},{'C', 3, 0},
        {'*', 0, 0},{'0', 0, 0},{'#', 0, 0},{'D', 3, 0}
    }; 
    char c;
    do{
        c = getKey();
        if(c){
            for (i = 0; i < 16; i++){
                if(c == keyboard[i].key){
                    keyboard[i].counter++;
                    break;
                }
            }
            if(keyboard[i].counter){
                putchar(keyboard[i].key);
            }
        }
    } while (c != 13);
}