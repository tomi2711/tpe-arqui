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

// Helpers

void split_args(char* buffer, char* command, char* arguments){

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


char* firstWord(char* str){

        int i=0;
        for(i=0; (str[i] != ' ' && str[i] != '\0'); i++) ;
        return strcut(str,0,i-1);
}

int numWords(char* str){

        if(str[0] == '\0') {
                return 0;
        }

        int counter = 1;

        for(int i=0; i<strlen(str); i++) {
                if(str[i] == ' ') {
                        counter++;
                }
        }

        return counter;
}

char* strcut(char* str, int start, int end){
        char* newstr;
        int i = 0;
        if((start<end) && (end < strlen(str))) {
                for(i = start; i<=end; i++) {
                        newstr[i-start]=str[i];
                }
                newstr[i-start]='\0';
        }

        return newstr;
}


char* strcat(char *dest, const char *src)
{
        int i,j;
        for (i = 0; dest[i] != '\0'; i++)
                ;
        for (j = 0; src[j] != '\0'; j++)
                dest[i+j] = src[j];
        dest[i+j] = '\0';
        return dest;
}
