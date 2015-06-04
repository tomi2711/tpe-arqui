//
//  interrupt.h
//  TomiOS
//
//  Created by Tomas De Lucca on 24/5/15.
//  Copyright (c) 2015 Tomas De Lucca. All rights reserved.
//

#ifndef __TomiOS__interrupt__
#define __TomiOS__interrupt__

#include "defines.h"

extern void kEnableInterrupts();
extern void kDisableInterrupts();
extern void kSetHandler(byte index, ddword handler, ddword idtStart);
extern void kGetIDTR(IDTR* idtr);

// Handlers

extern void keyboardInterruptHandler(void);

#endif /* defined(__TomiOS__interrupt__) */
