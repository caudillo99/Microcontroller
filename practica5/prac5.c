#include "Timer.h"

/*Prototype functions*/
void UpdateClock(void);
void DisplayClock(void);
void puts(char *str);
void PrintDec2d(BYTE data);
void Delay(BYTE ms);
void setDate(BYTE this_day, BYTE this_month, WORD this_year);
void setClock(BYTE hours, BYTE minutes, BYTE seconds);
/*==================================*/
void updateDate( void );
void displayDate( void );
void itoa(unsigned int number, char *str, unsigned char base);
BYTE anchor_day(WORD v_year);
BYTE doomsday(WORD v_year);
BYTE leapYear(WORD v_year);
BYTE lastDayOfTheMonth(WORD v_year, BYTE v_month, BYTE v_day );
BYTE specificDay( WORD v_year, BYTE v_month, BYTE v_day );

BYTE hrs = 0, min = 0, seg = 0, day = 0, month = 0;
WORD year = 0;
char str[5] = {0};

void main(){
	Timer_Ini();
  setDate(29,2,2020);
	setClock(23,59,49);
  while(1) {
	/*Verificacion para actualizar el reloj*/
    if(TimerSecFlag()) {
      updateDate();
      UpdateClock(); /*Ha pasado un segundo*/
      displayDate();
      DisplayClock(); /*Desplegar reloj en 0*/
    	poke(0x0, 0xffff, seg); /*Indicar el puerto*/
    } 
    Delay(100);
  }
}
void UpdateClock(void){
	seg++;
	if (seg == 60){
		seg = 0;
		min++;
		if (min == 60){
			min = 0; 
			hrs = ++hrs % 24;
		}
	}
}

void puts(char *str){
  while (*str) {
    putchar(*(str++));
  }
}
void DisplayClock(void){
  PrintDec2d(hrs);
  putchar(':');
  PrintDec2d(min);
  putchar(':');
  PrintDec2d(seg);
	putchar('\n');
	putchar('\r');
}

void Delay(BYTE i){
  while(--i);
}

void PrintDec2d(BYTE data){
  putchar(data/10+'0');
  putchar(data%10+'0');
}
void setClock(BYTE hours, BYTE minutes, BYTE seconds){
  hrs = hours;
  min = minutes;
  seg = seconds;
}

void setDate(BYTE this_day, BYTE this_month, WORD this_year){
  day = this_day;
  month = this_month;
  year = this_year;
}
/*============================================================*/
void updateDate( void ){
  if(seg==59 && min==59 && hrs==23){
    if( !lastDayOfTheMonth(year, month, day) ){
      day = 1;
      month = ++month % 13;
      if(!month){
        month = 1;
        year++;
      }
    }else
      day++;
  }
}

BYTE lastDayOfTheMonth(WORD v_year, BYTE v_month, BYTE v_day){
  BYTE lastday_month[13] = { 
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
  };
  BYTE aux = lastday_month[v_month - 1];
  if ( (v_month == 2) && leapYear(v_year) )
    aux++;
  return (v_day == aux) ? 1 : 0 ;
}

BYTE leapYear(WORD v_year){
  BYTE leap;
  if (!(v_year % 4)) {
    if (!(v_year % 100)) {
      if (! (v_year % 400))
        leap = 1;
      else
        leap = 0;
    }else
      leap = 1;
    }
  else
    leap = 0;
  return leap;
}

void displayDate( void ){
  itoa(day, str, 10);
  puts(str);
  putchar('/');
  itoa(month, str, 10);
  puts(str);
  putchar('/');
  itoa(year, str, 10);
  puts(str);
  putchar(32);
}

void itoa(unsigned int number, char *str, unsigned char base){
  unsigned char aux,i=0;
  char str_aux[16];
  while (number) {
    aux = number%base;
    number /= base;
    str_aux[i] = (aux<10) ? aux+'0' : aux+'A'-10;
    i++;
  }
  while (i) {
    *(str++) = str_aux[i-1];
    i--;
  }
  *str='\0';
}
