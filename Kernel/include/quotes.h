#ifndef __QUOTES__H__
#define __QUOTES__H__

#include "lib.h"
#include "display.h"
#include "defines.h"

int kinitQuotes();
void updateScreen();
void showRandomScreensaver();
ScreenSaver newScreenSaver(char* phrase, char* author);

#endif
