#include "lib.h"

// Printing

void putString(char* str){
        int length = strlen(str);
        int i = 0;

        while(i<length){
          putChar(str[i++]);
        }
}

void putChar(char c){
        runSyscall(WRITE,0x0,&c,1);
}

void printf(char* fmt, ...){

        va_list args;

        va_start(args, fmt);

        int i;
        int lenght = strlen(fmt);

        for(i=0; i<lenght; i++) {

          if(fmt[i] == '%'){

              char next = fmt[i+1];

              if(next == 0){
                return;
              } else if(next == 'd'){
                int n = va_arg(args, int);
                char* buffer[numberLength(n)];
                itoa(n, buffer);
                putString(buffer);
                i++;
              } else if(next == 's'){
                char* s = va_arg(args, char*);
                putString(s);
                i++;
              } else if(next == 'c'){
                char c = va_arg(args, int);
                putChar(c);
                i++;
              } else if(next == 'n'){
                int n = va_arg(args, int);
                char* buffer[numberLength(n)];
                itoa_d(n, buffer);
                putString(buffer);
                i++;
              }

          } else {
            putChar(fmt[i]);
          }

        }

        va_end(args);
}

// Reading

char getChar(){
        char c;
        runSyscall(READ, 0x0, &c, 1);
        return c;
}

void read(char* buffer, char delimiter){
        int i = 0;
        char c;

        do {
            c = getChar();
            if(c == '\b'){
              if(i>0){
                  buffer[i--] = ' ';
              }
            } else{
                buffer[i++] = c;
            }
        } while (c != delimiter);

        buffer[i-1] = 0;
}

// Time

void getTime(DATE * date){
        runSyscall(GET_TIME, 0x0, date, 0x0);
}

void setTime(unsigned char timeModifier, unsigned char value){
        runSyscall(SET_TIME, 0x0, value, timeModifier);
}

void clearScreen(){
        runSyscall(CLEAR_SCREEN,0x0,0x0,0x0);
}

void setScreenSaverTime(int miliseconds){
        runSyscall(SET_SCREENSAVER_TIME, 0x0,0x0,miliseconds);
}

// Helpers

void split(char* buffer, char* command, char* arguments){

  int i = 0;
  int j = 0;
  char c;

  do {
    c = buffer[i];
    command[i++] = c;

    if(c == ' ')
      break;

  } while( c != 0);

  command[i-1] = 0;

  if(c!=' '){
    arguments[j] = 0;
    return;
  }

  do {
    c = buffer[i++];
    arguments[j++] = c;

  } while(c != 0);

  arguments[j-1] = 0;
}

void clean(char* buffer, int size){

    int i = 0;

    while(i<size){
      buffer[i++] = 0;
    }
}

int split_args(char* buffer, char* key, char* value){

    int i = 0;
    int j = 0;
    char c = buffer[i];
    int length = strlen(buffer);

    if(c != '-')
      return ERROR;

    do {
      c = buffer[i];
      key[i++] = c;

      if(c == ' ')
        break;

    } while( c != 0);

    key[i-1] = 0;

    c = buffer[i];

    if(c == '-'){
        moveToBegining(buffer, i);
        return ONLY_KEY;
    }

    do {
      c = buffer[i++];
      value[j++] = c;

      if(c == ' ')
        break;

    } while(c != 0);

    value[j-1] = 0;

    moveToBegining(buffer, i);

    return KEY_VALUE;
}

void moveToBegining(char* buffer, int index){

    int j = 0;
    char c;

    if(index<strlen(buffer)){
      while((c = buffer[index++]) != 0){
          buffer[j++] = c;
      }
    }

    int length = strlen(buffer);

    buffer[j] = 0;

    while(j<length){
      buffer[j++] = 0;
    }
}

int numberLength (int i) {

  int counter = 1;

  while(i!=0){
      i=i/10;
      counter++;
  }

  return counter;
}

int strlen(char* str){

        int i = 0;

        while(str[i++] != '\0') ;

        return (i-1);
}

void reverse(char s[])
{
        int i, j;
        char c;

        for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}


void itoa(int n, char* s)
{
        int i, sign;

        if ((sign = n) < 0)
                n = -n;

        i = 0;

        do {
              s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);

        if (sign < 0)
            s[i++] = '-';

        s[i] = '\0';

        reverse(s);
}

int isNumber (unsigned char n)
{
  int t = ('0' <= n && n <= '9');
  return t;
}

int atoi(const char * str)
{
	  int i = 0;
    int total = 0;
	  while (str[i] != '\0') {
        if(!isNumber(str[i])){
            return -1;
        }
		    total = total*10 + str[i] - '0';
		    i++;
	  }

	  return total;
}

void itoa_d(int n, char* s)
{
     int i, sign;

     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     if (i<2){
			s[i++] = '0';
     }
     s[i] = '\0';
     reverse(s);
}

bool strEquals(char* str1, char* str2){

        if(strlen(str1) != strlen(str2)) {
                return FALSE;
        }else{
                for(int i=0; i<strlen(str1); i++) {
                        if(str1[i] != str2[i]) {
                                return FALSE;
                        }
                }
        }

        return TRUE;
}
