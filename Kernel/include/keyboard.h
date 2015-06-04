#ifndef __TomiOS__keyboard__
#define __TomiOS__keyboard__

#include "defines.h"

void kKBInitialize();
void kKBKeyReceived(unsigned char keycode);
void kKBInsertKey(unsigned char asciiValue);
unsigned char kKBGetKey();
bool kKBIsAlpha(unsigned char keycode);
bool kKBBufferIsEmpty();

#endif
