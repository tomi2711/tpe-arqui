#ifndef __TomiOS__LIB__
#define __TomiOS__LIB__

#include "libasm.h"
#include "defines.h"

void print(char* str);
void read(char* str, char delimiter);
void getTime(DATE * date);
void setTime(unsigned char timeModifier, unsigned char value);
void clearScreen();
int strlen(char* str);
void putChar(char c);
void itoa_d(int n, char s[]);

#endif
