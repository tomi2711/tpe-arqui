#ifndef LIB_H
#define LIB_H

#include <stdint.h>
#include "display.h"
#include "keyboard.h"

extern void kout(unsigned short port, unsigned char data);
extern unsigned char kin(unsigned short port);

void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);
int kstrlen(char* str);
char* kstrcat(char *dest, const char *src);
void kitoa(int n, char s[]);
void kitoa_d(int n, char s[]);
void kreverse(char s[]);

void kWrite(char* str, int length);
void kRead(char* buffer, int delimiter);

#endif
