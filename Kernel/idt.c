#include "idt.h"

IDTR idtr;

void kIDTInitialize(void) {

        kGetIDTR(&idtr);
        kDisableInterrupts();

        kSetHandler(0x21, (ddword)&keyboardInterruptHandler, idtr.base);
        kSetHandler(0x70, (ddword)&writeHandler, idtr.base);
        kSetHandler(0x90, (ddword)&clearScreenHandler, idtr.base);

        kEnableInterrupts();

        kout(PIC_DATA_PORT, 0xFD); // Set interrupt mask to only allow keyboard
}
