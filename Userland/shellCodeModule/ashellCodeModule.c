#include <stdint.h>
#include "libc.h"
#include "liba.h"
#include "defines.h"

extern char bss;
extern char endOfBinary;

char buffer[100];

void * memset(void * destiny, int32_t c, uint64_t length);

int main() {
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);

	char* tomi = "Tomas De Lucca";

	//print(tomi);

	while(1){
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
