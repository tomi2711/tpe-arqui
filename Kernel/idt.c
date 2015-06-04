#include "idt.h"

IDTR idtr;

void kIDTInitialize(void) {

        kGetIDTR(&idtr);
        kDisableInterrupts();

        kSetHandler(0x21, (ddword)&keyboardInterruptHandler, idtr.base);

        kEnableInterrupts();

        kout(PIC_DATA_PORT, 0xFD); // Set interrupt mask to only allow keyboard
}
