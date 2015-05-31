#ifndef __TomiOS__keyboard__
#define __TomiOS__keyboard__

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void kKeyboardInit();
void keyboard_handler_main(void);

#endif
