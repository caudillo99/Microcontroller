void putchar( char dato );
void puts( char *str );
char getch( void );
void printdec(unsigned char dato );
char msg[]="Hola UABC\r\n";
unsigned char i=0;

int main ( void ){
  while(1){
      printdec(i++);
      puts( msg );
      getch();
  }
  return 0;
}

void puts ( char *str ){
  while( *str )
    putchar( *str++ );
}
void putchar ( char dato ){
  asm mov dl,dato
  asm mov ah,2
  asm int 21h
}

char getch( void )
{
  char dato;
  asm mov ah,8
  asm int 21h
  asm mov dato,al
  return dato;
}

void printdec ( unsigned char dato )
{
  putchar( dato/100 + 0x30 );
  dato%=100;
  putchar( dato/10 + 0x30 );
  putchar( dato%10 + 0x30 );
}
