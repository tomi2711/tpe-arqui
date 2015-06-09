#ifndef __TomiOS__DEFINES_U__
#define __TomiOS__DEFINES_U__

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

#define TOTAL_COMMANDS 5

#define MAX_COMMAND_LENGTH 30
#define MAX_ARGUMENTS_LENGTH 80

#define MAX_VALUE_SIZE 20
#define MAX_KEY_SIZE  20

#define MAX_SCREENSAVER_TIME 999999999
#define MIN_SCREENSAVER_TIME 1000

typedef enum SYSTEM_CALLS {
        WRITE = 0x4,
        READ = 0x3,
        CLEAR_SCREEN = 0x2,
        GET_TIME = 0xD,
        SET_TIME = 0x19,
        SET_SCREENSAVER_TIME = 0x22
} SYSCALLS;

typedef enum ARGS_PARSE {
        ERROR = -1,
        ONLY_KEY = 1,
        KEY_VALUE = 2
} ArgsParseStatus;

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

typedef struct CommandDesc {
        char* key;
        action handler;
        char* use;
} CommandDescriptor;

#endif
