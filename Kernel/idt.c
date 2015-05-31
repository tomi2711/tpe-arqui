#include "idt.h"

#pragma pack(1)

IDTR idtr;

void kIdtInit(void) {

    kGetIDTR(&idtr);

    kSetHandler(0x21, &keyboard_handler, idtr.base);

    kEnableInterrupts();
}
