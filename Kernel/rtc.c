#include "rtc.h"

const char* daysName[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const char* monthsName[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio", "Agosto","Septiembre", "Octubre", "Noviembre","Diciembre"};

#define RTC_PORT		0x70
#define RTC_REGISTER_PORT	0x71

void ksetRTCConfig(unsigned int reg, unsigned char bit, unsigned char value){
	kout(RTC_PORT,reg);
	unsigned char data = kin(RTC_REGISTER_PORT);
	data = data & ~(1 << bit) | (value << bit);
	kout(RTC_PORT, reg);
	kout(RTC_REGISTER_PORT,data);
}

void kinitRTC(){
	ksetRTCConfig(RTC_SETUP_B,2,1);
}

unsigned char kaccessRTC(unsigned char data){
	kout(RTC_PORT, data);
	kin(RTC_REGISTER_PORT);
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
