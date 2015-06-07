#include "lib.h"

void print(char* str){
    int length = strlen(str);
    runSyscall(WRITE, 0x0, str, length);
}

void putChar(char c){
    runSyscall(WRITE,0x0,&c,1);
}

void read(char* buffer, char delimiter){
    runSyscall(READ, 0x0, (char*)buffer, delimiter);
}

void getTime(DATE * date){
    runSyscall(GET_TIME, 0x0, date, 0x0);
}

void setTime(unsigned char timeModifier, unsigned char value){
    runSyscall(SET_TIME, 0x0, value, timeModifier);
}

void clearScreen(){
    runSyscall(CLEAR_SCREEN,0x0,0x0,0x0);
}

int strlen(char* str){

    int i = 0;

    while(str[i++]!= 0);

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


void itoa(int n, char s[])
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
     s[i] = '\0';
     reverse(s);
}

void itoa_d(int n, char s[])
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
