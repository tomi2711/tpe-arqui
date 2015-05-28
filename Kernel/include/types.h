#ifndef __TomiOS__types__
#define __TomiOS__types__

struct IDT_entry{
  unsigned short int offset_lowerbits;
  unsigned short int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned short int offset_middlebits;
  unsigned int offset_higherbits;
  unsigned int zeroo;
};

struct IDTDesc {
  unsigned short int limit;
  unsigned long int offset;
};

#endif /* defined(__TomiOS__types__) */
