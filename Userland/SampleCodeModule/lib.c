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

    while(str[i++] != '\0');

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

bool strEquals(char* str1, char* str2){

    if(strlen(str1) != strlen(str2)){
        return FALSE;
    }else{
        for(int i=0;i<strlen(str1); i++){
            if(str1[i] != str2[i]){
                return FALSE;
            }
        }
    }

    return TRUE;
}


char* firstWord(char* str){

  int i=0;
  for(i=0; (str[i] != ' ' && str[i] != '\0');i++);
  return strcut(str,0,i-1);
}

int numWords(char* str){

    if(str[0] == '\0'){
        return 0;
    }

    int counter = 1;

    for(int i=0;i<strlen(str);i++){
        if(str[i] == ' '){
            counter++;
        }
    }

    return counter;
}

char* strcut(char* str, int start, int end){
    char* newstr;
    int i = 0;
    if((start<end) && (end < strlen(str))){
        for(i = start; i<=end; i++){
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
