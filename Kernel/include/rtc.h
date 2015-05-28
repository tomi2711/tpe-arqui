#ifndef __TomiOS__rtc__
#define __TomiOS__rtc__

#include "lib.h"

enum DAYS {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum MONTHS {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

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

void kinitRTC();
unsigned char kgetSecond();
unsigned char kgetMinute();
unsigned char kgetHour();
unsigned char kgetDayOfWeek();
unsigned char kgetDayOfMonth();
unsigned char kgetMonth();
unsigned char kgetYear();

#endif
