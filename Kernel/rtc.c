#include "rtc.h"

void ksetRTCConfig(unsigned int reg, unsigned char bit, unsigned char value){
	kout(RTC_PORT,reg);
	unsigned char data = kin(RTC_REGISTER_PORT);
	data = data & ~(1 << bit) | (value << bit);
	kout(RTC_PORT, reg);
	kout(RTC_REGISTER_PORT,data);
}

void getCurrentDate(DATE* date){
	date->second = kgetSecond();
	date->minute = kgetMinute();
	date->hour = kgetHour();
	date->d_month = kgetDayOfMonth();
	date->d_week = kgetDayOfWeek();
	date->month = kgetMonth();
	date->year = kgetYear();
};

void setCurrentDate(DATE* date){
	ksetSecond(date->second);
	ksetMinute(date->minute);
	ksetHour(date->hour);
	ksetDayOfMonth(date->d_month);
	ksetMonth(date->month);
	ksetYear(date->year);
}

void kinitRTC(){
	ksetRTCConfig(RTC_SETUP_B,2,1);
}

unsigned char kaccessRTC(unsigned char data){
	kout(RTC_PORT, data);
	kin(RTC_REGISTER_PORT);
}

void kwriteRTC(unsigned char data, unsigned char rtc_modifier){
		if(data==0xFF)
			return;

		kout(RTC_PORT, rtc_modifier);
		kout(RTC_REGISTER_PORT, data);
}

void ksetSecond(unsigned char data){
		kwriteRTC(data, RTC_SECOND);
}

void ksetMinute(unsigned char data){
		kwriteRTC(data, RTC_MINUTE);
}

void ksetHour(unsigned char data){
		kwriteRTC(data, RTC_HOUR);
}

void ksetDayOfMonth(unsigned char data){
		kwriteRTC(data, RTC_D_MONTH);
}

void ksetMonth(unsigned char data){
		kwriteRTC(data, RTC_MONTH);
}

void ksetYear(unsigned char data){
		kwriteRTC(data, RTC_YEAR);
}

unsigned char kgetSecond(){
	return kaccessRTC(RTC_SECOND);
}

unsigned char kgetMinute(){
	return kaccessRTC(RTC_MINUTE);
}

unsigned char kgetHour(){
	return kaccessRTC(RTC_HOUR);
}

unsigned char kgetDayOfWeek(){
	return kaccessRTC(RTC_D_WEEK);
}

unsigned char kgetDayOfMonth(){
	return kaccessRTC(RTC_D_MONTH);
}

unsigned char kgetMonth(){
	return kaccessRTC(RTC_MONTH);
}

unsigned char kgetYear(){
	return kaccessRTC(RTC_YEAR);
}
