#include "keyboard.h"

void kKeyboardInit(){
  kout(0x21 , 0xFD);
}

void keyboard_handler_main(void) {

  unsigned char status;
  char keycode;

  kputString("Mac");

  kout(0x20, 0x20);
  kout(0xA0, 0x20);

  status = kin(KEYBOARD_STATUS_PORT);

  if (status & 0x01) {
  		keycode = kin(KEYBOARD_DATA_PORT);
  }
  
}
