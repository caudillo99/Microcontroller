/*AMS routines*/
extern void putchar(char dato);
extern char getchar(void);
/*C functions*/
void gets(char *str);
void puts(char *str);
void itoa(unsigned int number, char *str, unsigned char base);
unsigned int atoi(char *str);

unsigned char doomsday(unsigned int year);
unsigned char anchor_day(unsigned int year);
unsigned int substr(char *str, unsigned char init, unsigned char end);
unsigned char leap_year(unsigned int year);
unsigned char check_lastday(unsigned int year, unsigned char month, unsigned char day);
unsigned char specific_day(unsigned int year, unsigned char month, unsigned char day);

char *day[] = {"Domingo", "Lunes", "Martes", "Miercoles",
                "Jueves", "Viernes", "Sabado"
              };
char *month[] = {
                "Enero","Febrero", "Marzo", "Abril",
                "Mayo", "Junio", "Julio", "Agosto",
                "Septiembre","Octubre", "Noviembre", "Diciembre"
              };
unsigned char lastday_month[] = { 31, 28, 31, 30,
                                  31, 30, 31, 31,
                                  30, 31, 30, 31
                                };
unsigned char weekday[] = {3,28,7,4,9,6,11,8,5,10,7,12};
unsigned char doomsdays_year[] = {2,0,5,3};
unsigned char c;

void main ( void ){
  char input[12];
  char x[5];
  unsigned char cur_day;
  while(1){
    puts("Date: ");
    gets(input);
    cur_day = specific_day(substr(input,6,9),substr(input,3,4),substr(input,0,1));
    if(cur_day != 7){
      puts(day[cur_day]);
      putchar(' ');
      itoa(substr(input,0,1),x,10);
      puts(x);
      puts(" de ");
      puts(month[substr(input,3,4)-1]);
      puts(" del anio ");
      itoa(substr(input,6,9),x,10);
      puts(x);
    }else
      puts("Fecha invalida!");
    putchar('\n');
    getchar();
  }
}

void gets(char *str){
  const unsigned char limit = 21;
  const char *const aux = str;
  c=getchar();

  while (c != 13) {
    if (c == 8) {
      if (str != aux) {
        putchar(' ');
        putchar(c);
        str--;
      }
      else putchar(' ');
    }
    else if(str >= aux+limit-1){
      putchar(8);
      putchar(' ');
      putchar(8);
    }
    else
      *(str++) = c;
    c = getchar();
  }
  *str = '\0';
}

void puts(char *str){
  while (*str) {
    putchar(*(str++));
  }
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

unsigned int atoi(char *str){
  unsigned int num=0;
  while (*str) {
    num*=10;
    num+=((*str++)-'0');
  }
  return num;
}

/*Return the Doomsday of given a year*/
unsigned char doomsday(unsigned int year){
  unsigned char dooms = 0, two_dig;
  two_dig = (year%100) ;
  dooms = (two_dig / 12);
  dooms += (two_dig - (dooms*12));
  dooms += (two_dig % 12) / 4;
  dooms += doomsdays_year[anchor_day(year)];
  while (dooms >= 7) {
    dooms -= 7;
  }
  return dooms;
}

/* Return the century anchor day*/
unsigned char anchor_day(unsigned int year){
	unsigned int remainder = year%400;
	if(remainder < 100)
    remainder = 0;
	else if(remainder < 200)
    remainder = 1;
	else if(remainder < 300)
    remainder = 2;
	else
    remainder = 3;
  return remainder;
}

/*Convert string to integer with a given index value*/

unsigned int substr(char *str, unsigned char init, unsigned char end ){
  char aux[6],i=0;
  while (init+i <= end) {
    aux[i] = *(str+init+i);
    i++;
  }
  aux[i] = '\0';
  return (atoi(aux));
}

unsigned char leap_year(unsigned int year){
  unsigned char leap;
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0)
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

unsigned char check_lastday(unsigned int year, unsigned char month, unsigned char day){
  unsigned char aux = lastday_month[month - 1], res = 0;
  if (year <= 9999 && month <=12) {
    if(month == 2 && leap_year(year)){
      aux++;
    }
    if(day <= aux && day > 0){
      res = 1; /*1 means success  0 means fails*/
    }
  }
  return res;
}

unsigned char specific_day(unsigned int year, unsigned char month, unsigned char day){
  char dday = doomsday(year);
  unsigned char aux = weekday[month-1];
  if(check_lastday(year, month, day))
  {
    if(month == 2 && leap_year(year)){
      aux++;
    }
    if(day != dday){
      if (day > aux){
        while (day > aux){
          dday++;
          aux++;
          if (dday > 6){
            dday = 0;
          }
        }
      }else{
        while (day < aux) {
          dday--;
          aux--;
          if(dday < 0){
            dday = 6;
          }
        }
      }
    }else {
      dday = day;
    }
  }else {
    dday = 7;
  }
  return dday;
}
