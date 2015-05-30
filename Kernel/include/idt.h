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
#include "lib.h"
#include "naiveConsole.h"

#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8E00
#define KERNEL_CODE_SEGMENT_OFFSET 0x08
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void kIdtInit(void);

#endif /* defined(__TomiOS__idt__) */
