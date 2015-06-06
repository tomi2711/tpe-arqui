#include "libc.h"

void print(char* str){

    int i = 0;

    while(str[i] != 0){
      i++;
    }

    int t = 4;

    runSyscall(WRITE, 0x0, str, i);
}

void read(char* buffer, char delimiter){
    runSyscall(READ, 0x0, buffer, delimiter);
}
