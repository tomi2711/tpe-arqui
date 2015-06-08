#ifndef __TomiOS__LIB__
#define __TomiOS__LIB__

#include "libasm.h"
#include "defines.h"

void print(char* str);
void read(char* str, char delimiter);
void putChar(char c);

void getTime(DATE * date);
void setTime(unsigned char timeModifier, unsigned char value);

void clearScreen();

int strlen(char* str);
void itoa_d(int n, char s[]);
bool strEquals(char* str1, char* str2);
char* strcut(char* str, int start, int end);
char* firstWord(char* str);
int numWords(char* str);
char* strcat(char* str1, const char* str2);


#endif
