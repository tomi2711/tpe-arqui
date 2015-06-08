#ifndef __TomiOS__DEFINES_U__
#define __TomiOS__DEFINES_U__

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

#define TOTAL_COMMANDS 4

#define MAX_COMMAND_LENGTH 30
#define MAX_ARGUMENTS_LENGTH 80

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

typedef int (*action)(char*);

typedef struct CommandDesc{
  char* key;
  action handler;
  char* use;
} CommandDescriptor;

#endif
