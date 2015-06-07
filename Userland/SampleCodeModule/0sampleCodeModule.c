#include <stdint.h>
#include "lib.h"
#include "defines.h"

extern char bss;
extern char endOfBinary;

void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);

	print("Boot time: ");

	DATE date;
	getTime(&date);

	char* buffer[100];

	itoa_d(date.hour, buffer);
	print(buffer);
	putChar(':');
	itoa_d(date.minute, buffer);
	print(buffer);
	putChar('\n');

	while(1){
			print("console$:> ");
			read(buffer,'\n');
			print(buffer);
	}

	return 0xDEADBEEF;
}

void * memset(void * destiation, int32_t c, uint64_t length) {
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)destiation;

	while(length--)
		dst[length] = chr;

	return destiation;
}
