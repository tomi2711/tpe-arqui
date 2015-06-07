#ifndef __TomiOS__INTERRUPTS__
#define __TomiOS__INTERRUPTS__

#include "defines.h"

extern void kEnableInterrupts();
extern void kDisableInterrupts();
extern void kSetHandler(byte index, ddword handler, ddword idtStart);
extern void kGetIDTR(IDTR* idtr);

// Handlers

extern void keyboardInterruptHandler();
extern void syscallInterruptHandler();

#endif /* defined(__TomiOS__interrupt__) */
