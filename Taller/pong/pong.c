#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
typedef unsigned char byte_t;
typedef unsigned int word_t;
void setColorAndBackground(int ForgC, int BackC);
COORD coord={0,0};

struct item{
    byte_t bar[7];
    byte_t x;
    byte_t y;
    byte_t level;
};

typedef struct item item_t;

/*Function declaration*/
void startGame(item_t player[3]);
byte_t getKey(void);
void gameUpdate(item_t player[3]);
void movePlayer(item_t *player);
void checkBounds(item_t *player);
void moveBall(item_t *ball,item_t player ,signed char *m,signed char *left_right);
void gameOver(void);
byte_t checkColission(item_t player, item_t *ball);
void gotoxy(int x,int y);
void level(item_t player[3]);
void ready(void);

int main(){
    item_t player[3] = {
        {{219,219,219,219,219,219,0},0,0,0},
        {{219,219,219,219,219,219,0},16,24,0},
        {{254,0},0,1,0}
    };
    setColorAndBackground(255, 0);
    ready();
    startGame(player);
    return 0;
}
void ready(void){
    signed char i= 4;
    while(i-- ){
        system("cls");
        gotoxy(40,12);
        puts("GAME START IN:");
        gotoxy(47,13);
        putchar(i+'0');
        Sleep(800);
    }
}
void setColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
void startGame(item_t player[3]){
    signed char m = 1,left_right = 1;
    while(1){
        printf("\033[0m");
        level(player);
        gameUpdate(player);
        movePlayer(&player[1]);
        moveBall(&player[2], player[1],&m, &left_right);
    }
}

byte_t getKey(void){
    if(kbhit()){
        return getch();
    }
}
void gameUpdate(item_t player[3]){
    setColorAndBackground(255, 0);
    checkBounds(&player[1]);
    gotoxy(player[1].x, player[1].y);
    puts(player[1].bar);

    checkBounds(&player[2]);
    gotoxy(player[2].x, player[2].y);
    puts(player[2].bar);

    player[0].x = player[2].x;
    player[0].x-=2;
    checkBounds(&player[0]);
    gotoxy(player[0].x, player[0].y);
    puts(player[0].bar);
    system("cls");
}

void checkBounds(item_t *player){
    if(player->x > 79)  player->x = 80;
    if(player->x < 1 )  player->x = 1;
    if(player->y > 23)  player->y = 24;
    if(player->y < 1 )  player->y = 0;
}

void moveBall(item_t *ball, item_t player ,signed char *m, signed char *left_right){
    //checkBounds(ball);
    if(ball->y != 24){
        //printf("Ball-> x:%d\t y:%d\t m:%d\n", ball->x, ball->y, *m);
        //printf("Player-> x:%d\t y:%d\t m:%d", player.x, player.y, *m);
        ball->x += (*left_right);
        ball->y += (*m)+ball->level;
        if(!(ball->y-1) || checkColission(player, ball))
            (*m) *= -1;                             //Cambia la pendiente cuando choque con un jugador
        if(ball->x%80 == 0 || ball->x == 0)
            *(left_right) *= -1;                    //Cuando llegue a las paredes cambia de direccion de lado contrario.
    }
    else
        gameOver();
}
byte_t checkColission(item_t player, item_t *ball){
    byte_t collision = 0;
    if((ball->x >= player.x-1) && (ball->x <= player.x+6)){
        if(player.y-1 == ball->y)
            collision = 1;
    }
    return collision;
}
void movePlayer(item_t *player) {
    byte_t c;
    c = getKey();
    if(c == 'd')
        player->x+= player->level+1;
    if(c == 'a')
        player->x-=player->level+1;
    fflush(stdin);
}

void gameOver(){
    signed char i= 0;
    while(i++ < 4){
        system("cls");
        Sleep(500);
        gotoxy(40,12);
        puts("GAME OVER");
        Sleep(500);
    }
    exit (-1);
}

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void level(item_t player[3]){
    byte_t key = getKey();
    if(key == '1')
        player[2].level = 1;
    if(key == '2')
        player[1].level = 1;
    if(key == '3'){
        player[1].level = 1;
        player[2].level = 1;
    }
    if(key == '0'){
        player[1].level = 0;
        player[2].level = 0;
    }
    fflush(stdin);
}
