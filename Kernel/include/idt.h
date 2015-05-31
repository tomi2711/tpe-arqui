//
//  idt.h
//  TomiOS
//
//  Created by Tomas De Lucca on 24/5/15.
//  Copyright (c) 2015 Tomas De Lucca. All rights reserved.
//

#ifndef __TomiOS__idt__
#define __TomiOS__idt__

#include "interrupt.h"
#include "types.h"
#include "keyboard.h"

#define IDT_SIZE 256

void kIdtInit(void);

#endif /* defined(__TomiOS__idt__) */
