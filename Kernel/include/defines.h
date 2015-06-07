#ifndef __TomiOS__DEFINES__
#define __TomiOS__DEFINES__

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long ddword;

#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH     80
#define SCREEN_HEIGHT 25

#define CURSOR_BLOCK  0x00
#define CURSOR_LINE 0x0E
#define NO_CURSOR 0x10

#define IDT_SIZE 256

#define PIC_DATA_PORT      0x21

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#define KEYBOARD_BUFFER_SIZE  32

#define NOT_PRINTABLE 0x0
#define TOTAL_KEYS  59

#define KEY_RELEASED  0x80

#define RS_PRESSED          0x36
#define RS_RELEASED         0xB6
#define LS_PRESSED          0x2A
#define LS_RELEASED         0xAA
#define CAPS_LOCK           0x3A
#define SPACEBAR            0x20

#define EMPTY 0xFF

typedef struct KB_STATUS {
        bool shiftEnabled;
        bool capsLockEnabled;
} kKBStatus;

typedef struct KB_BUFFER {
        word readIndex;
        word writeIndex;
        unsigned char buffer[KEYBOARD_BUFFER_SIZE];
} kKBBuffer;

typedef struct IDTR_DESC {
        word limit;
        ddword base;
} IDTR;

typedef enum COLOR {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        LIGHT_GRAY,
        DARK_GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_CYAN,
        LIGHT_RED,
        LIGHT_MAGENTA,
        YELLOW,
        WHITE
} Color;

typedef enum SYSTEM_CALLS {
        WRITE,
        READ,
        CLEAR_SCREEN,
        GET_TIME,
        SET_TIME
} SYSCALLS;

#define RTC_PORT		0x70
#define RTC_REGISTER_PORT	0x71

typedef struct U_DATE {
  unsigned char second;
  unsigned char minute;
  unsigned char hour;
  unsigned char d_week;
  unsigned char d_month;
  unsigned char month;
  unsigned char year;
} DATE;

enum RTC_CONVERSION {
	RTC_SECOND = 0,
	RTC_MINUTE = 2,
	RTC_HOUR = 4,
	RTC_D_WEEK = 6,
	RTC_D_MONTH = 7,
	RTC_MONTH = 8,
	RTC_YEAR = 9,
	RTC_SETUP_B = 0xB
};

#endif /* defined(__TomiOS__types__) */
