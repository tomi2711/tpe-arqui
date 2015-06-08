#include "interruptsHandler.h"

void keyboardHandler(void) {

        unsigned char status = kin(KEYBOARD_STATUS_PORT);
        unsigned char keycode = kin(KEYBOARD_DATA_PORT);

        if(isScreenSaverShowing()){
            stopScreenSaver();
            return;
        }

        if (status && 0x01) {
                kKBKeyReceived(keycode);
        }

        resetTime();
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

void TTHandler(){
    screenSaverTick();
}
