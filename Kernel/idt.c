#include "idt.h"

IDTR idtr;

void kIDTInitialize(void) {

        kGetIDTR(&idtr);
        kDisableInterrupts();

        kSetHandler(0x20, (ddword)&TTInterruptHandler, idtr.base);
        kSetHandler(0x21, (ddword)&keyboardInterruptHandler, idtr.base);
        kSetHandler(0x80, (ddword)&syscallInterruptHandler, idtr.base);

        kEnableInterrupts();

        kout(PIC_DATA_PORT, 0xFC); // Set interrupt mask to only allow keyboard
}
