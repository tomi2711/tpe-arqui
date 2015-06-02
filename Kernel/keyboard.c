#include "keyboard.h"
#include "keymap.h"



int shiftDown = 0;

void kKeyboardInit(){
  kout(0x21 , 0xFD);
  byte auxkeyMap[MAXPRINTABLE][2] = {
      {NOTPRINTABLE,NOTPRINTABLE},
      {'1','!'},
      {'2','@'},
      {'3','#'},
      {'4','$'},
      {'5','%'},
      {'6','&'},
      {'7','/'},
      {'8','('},
      {'9',')'},
      {'0','='},
      {'\'','?'},
      {'<','>'},
      {'\b','\b'},
      {'\t','\t'},
      {'q','Q'},
      {'w','W'},
      {'e','E'},
      {'r','R'},
      {'t','T'},
      {'y','Y'},
      {'u','U'},
      {'i','I'},
      {'o','O'},
      {'p','P'},
      {'+','['},
      {'*',']'},
      {'\n','\n'},
      {NOTPRINTABLE,NOTPRINTABLE},  // CTRL
      {'a','A'},
      {'s','S'},
      {'d','D'},
      {'f','F'},
      {'g','G'},
      {'h','H'},
      {'j','J'},
      {'k','K'},
      {'l','L'},
      {NOTPRINTABLE,NOTPRINTABLE},  // ñ
      {'{','{'},
      {'}','}'},
      {NOTPRINTABLE,NOTPRINTABLE},  // SHIFT IZQ
      {'\\','|'},
      {'z','Z'},
      {'x','X'},
      {'c','C'},
      {'v','V'},
      {'b','B'},
      {'n','N'},
      {'m','M'},
      {',',';'},
      {'.',':'},
      {'-','_'},
      {NOTPRINTABLE,NOTPRINTABLE},  // SHIFT DER
      {NOTPRINTABLE,NOTPRINTABLE},  // PTR SCREEN
      {NOTPRINTABLE,NOTPRINTABLE},  // ALT
      {0x20,0x20}                     // SPACE
  };

  for(int i=0;i<MAXPRINTABLE;i++)
    for (int j=0; j<2; j++) {
      keyMap[i][j] = auxkeyMap[i][j];
    }
}

void keyboard_handler_main(void) {

  unsigned char status;
  char keycode;

  //kputString("Mac");

  status = kin(KEYBOARD_STATUS_PORT);

  if (status & 0x01) {
  		keycode = kin(KEYBOARD_DATA_PORT);
      if(keycode & 0x80)    //key pressed
      {

      } else {    //key released
          if(keycode != NOTPRINTABLE){
              kputChar(keyMap[keycode-1][shiftDown]);
          }
      }
  }
  kout(0x20, 0x20);
  kout(0xA0, 0x20);
}
