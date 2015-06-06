#ifndef __TomiOS__handlers__
#define __TomiOS__handlers__

#include "defines.h"
#include "lib.h"
#include "keyboard.h"
#include "display.h"

void keyboardHandler();
void kSyscallHandler(ddword a, ddword b, ddword c, ddword d);

#endif
