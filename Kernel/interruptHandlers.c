#include "interruptHandlers.h"

void keyboardHandler(void) {

        unsigned char status;
        unsigned char keycode;

        status = kin(KEYBOARD_STATUS_PORT);

        if (status && 0x01) {

                keycode = kin(KEYBOARD_DATA_PORT);

                kKBKeyReceived(keycode);

        }
}

void kSyscallHandler(ddword a, ddword b, ddword c, ddword d){

        switch (a) {
        case WRITE:
                kWrite((char*)c, (int) d);
                ksetBackspaceLimit();
                break;
        case READ:
                kRead((char*)c, (char) d);
                break;
        case CLEAR_SCREEN:
                kclearScreen();
                break;
        default:
                break;
        }

}
