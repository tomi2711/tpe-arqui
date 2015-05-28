#include "idt.h"

struct IDT_entry IDT[IDT_SIZE];
struct IDTDesc idtDescriptor;

void kIdtInit(void) {

  unsigned long keyboard_address;
  unsigned long idt_address;

  /* populate IDT entry of keyboard's interrupt */
  	keyboard_address = (unsigned long)keyboard_handler;
  	IDT[0x21].offset_lowerbits = keyboard_address & 0x000000ff;
  	IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
  	IDT[0x21].zero = 0;
  	IDT[0x21].type_attr = INTERRUPT_GATE;
  	IDT[0x21].offset_middlebits = (keyboard_address & 0x0000ff00) >> 16;
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;
    IDT[0x21].zeroo = 0;

  /*     Ports
  	*	 PIC1	PIC2
  	*Command 0x20	0xA0
  	*Data	 0x21	0xA1
  	*/

  /* ICW1 - begin initialization */
  kout(0x20 , 0x11);
  kout(0xA0 , 0x11);

  /* ICW2 - remap offset address of IDT */
  /*
  	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
  	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
  	*/
  kout(0x21 , 0x20);
  kout(0xA1 , 0x28);

  /* ICW3 - setup cascading */
  kout(0x21 , 0x00);
  kout(0xA1 , 0x00);

  /* ICW4 - environment info */
  kout(0x21 , 0x01);
  kout(0xA1 , 0x01);

  /* Initialization finished */

  /* mask interrupts */
  kout(0x21 , 0xff);
  kout(0xA1 , 0xff);

  idt_address = (unsigned long) IDT;

  idtDescriptor.limit = (sizeof(struct IDT_entry) * IDT_SIZE) - 1;
  idtDescriptor.offset = idt_address;

  //load_idt(&idtDescriptor);
  sti_enable();
}

void keyboard_init(){
  kout(0x21 , 0xFD);
}

void keyboard_handler_main(void) {

  //unsigned char status;
  //char keycode;

  kout(0x20, 0x20);
  kout(0x20, 0xA0);

  kputString("Mac");

  //status = kin(KEYBOARD_STATUS_PORT);

  /*if (status & 0x01) {
  		keycode = kin(KEYBOARD_DATA_PORT);
  }

  //char key[4];

  //t_itoa(keycode,key);

  d_putString("AAAAAAAAAA");*/
}
