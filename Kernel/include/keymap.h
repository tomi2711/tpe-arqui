#ifndef __TomiOS__keymap__
#define __TomiOS__keymap__

#include "types.h"

#define MAXPRINTABLE 57
#define NOTPRINTABLE 0X0

byte keyMap[MAXPRINTABLE][2] = {
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

#endif
