#ifndef __TomiOS__DEFINES__
#define __TomiOS__DEFINES__

typedef enum SYSTEM_CALLS {
        WRITE,
        READ,
        CLEAR_SCREEN,
        GET_TIME,
        SET_TIME
} SYSCALLS;

typedef struct U_DATE {
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char d_week;
  unsigned char d_month;
  unsigned char month;
  unsigned char year;
} DATE;

#endif
