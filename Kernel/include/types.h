#ifndef __TomiOS__types__
#define __TomiOS__types__

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long ddword;

typedef struct IDT_Entry{
  word offset_l;
  word selector;
  byte zero;
  byte type_attr;
  word offset_m;
  dword offset_h;
  dword zeroo;
} IDTEntry;

typedef struct IDTR_Desc {
  word limit;
  ddword base;
} IDTR;

#endif /* defined(__TomiOS__types__) */
