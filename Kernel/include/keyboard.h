#ifndef __TomiOS__KEYBOARD__
#define __TomiOS__KEYBOARD__

#include "defines.h"

void kKBInitialize();
void kKBKeyReceived(unsigned char keycode);
void kKBInsertKey(unsigned char asciiValue);
unsigned char kKBGetKey();
bool kKBIsAlpha(unsigned char keycode);
bool kKBBufferIsEmpty();

#endif
