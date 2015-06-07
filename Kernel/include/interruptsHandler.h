#ifndef __TomiOS__HANDLERS__
#define __TomiOS__HANDLERS__

#include "defines.h"
#include "lib.h"
#include "keyboard.h"
#include "display.h"
#include "rtc.h"

void keyboardHandler();
void syscallHandler(ddword a, ddword b, ddword c, ddword d);

#endif
