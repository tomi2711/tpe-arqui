#include "idt.h"

#pragma pack(1)

IDTR idtr;

void keyboard_init(){
  kout(0x21 , 0xFD);
}

void setIDTEntry(IDTEntry* idt, byte index, ddword handler, word selector, byte type_attr){
    idt[index].offset_l = handler & 0xFFFF;
    idt[index].offset_m = (handler & 0xFFFF0000) >> 16;
    idt[index].offset_h = (handler & 0xFFFFFFFF00000000) >> 32;
    idt[index].type_attr = type_attr;
    idt[index].selector = selector;
    idt[index].zero = 0;
    idt[index].zeroo = 0;
}

void kIdtInit(void) {

    kGetIDTR(&idtr);

    kSetHandler(0x21, &keyboard_handler, idtr.base);

    kEnableInterrupts();
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

  //char key[4];

  //t_itoa(keycode,key);

  //d_putString("AAAAAAAAAA");*/
}
