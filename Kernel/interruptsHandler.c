#include "interruptsHandler.h"

void keyboardHandler(void) {

        unsigned char status;
        unsigned char keycode;

        status = kin(KEYBOARD_STATUS_PORT);

        if (status && 0x01) {

                keycode = kin(KEYBOARD_DATA_PORT);

                kKBKeyReceived(keycode);
        }
}

void syscallHandler(ddword a, ddword b, ddword c, ddword d){

        DATE date;

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
        case GET_TIME:
                getCurrentDate((DATE*) c);
                break;
        case SET_TIME:
                break;
        default:
                break;
        }
}
