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

void kWriteHandler(const char* str, int length){
    kputString(str);
    ksetBackspaceLimit();
}
