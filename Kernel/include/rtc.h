#ifndef __TomiOS__RTC__
#define __TomiOS__RTC__

#include "lib.h"
#include "defines.h"

void kinitRTC();
unsigned char kaccessRTC(unsigned char data);
unsigned char kgetSecond();
unsigned char kgetMinute();
unsigned char kgetHour();
unsigned char kgetDayOfWeek();
unsigned char kgetDayOfMonth();
unsigned char kgetMonth();
unsigned char kgetYear();
void getCurrentDate(DATE* date);

#endif
