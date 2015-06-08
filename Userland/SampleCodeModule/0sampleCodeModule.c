#include <stdint.h>
#include "lib.h"
#include "defines.h"

extern char bss;
extern char endOfBinary;

void * memset(void * destiny, int32_t c, uint64_t length);
void initCommandList();
void processAction(char* buffer);
int commandSelector(char* command);
char* echo(char* str);
char* clear(char* str);
char* help(char* str);

CommandDescriptor commands[TOTAL_COMMANDS];

int main() {
	//Clean BSS
	memset(&bss, 0, &endOfBinary - &bss);

	print("Boot time: ");

	DATE date;
	getTime(&date);

	char buffer[100];
	initCommandList();

	itoa_d(date.hour, buffer);
	print(buffer);
	putChar(':');
	itoa_d(date.minute, buffer);
	print(buffer);
	putChar('\n');

	while(1){
			print("console$:> ");
			read(buffer,'\n');
			processAction(buffer);
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

void initCommandList(){
	commands[0].key = "echo";
	commands[0].argc = MAX_INT;
	commands[0].action = &echo;
	commands[0].use = "Repeats text following command.";

	commands[1].key = "clear";
	commands[1].argc = 0;
	commands[1].action = &clear;
	commands[1].use = "Cleans the terminal screen.";

	commands[2].key = "help";
	commands[2].argc = 0;
	commands[2].action = &help;
	commands[2].use = "Displays list of commands.";

}

void processAction(char* buffer){
	char* message;
	if(strlen(buffer) == 0)
		return;
	int commandId = commandSelector(firstWord(buffer));
	if(commandId == -1){
		message = firstWord(buffer);
		message = strcat(message, " is not a valid command.\n");

	}else if((commands[commandId].argc == MAX_INT) ||
			 		(numWords(buffer)-1 == commands[commandId].argc)){
		message = (*((commands[commandId]).action))(strcut(buffer,
				 																							strlen(commands[commandId].key)+1,
																											strlen(buffer)-1));
	}else {
		message = "Number of arguments is incorrect.\n";
	}

	print(message);
}

int commandSelector(char* command){
	for(int i=0; i<TOTAL_COMMANDS;i++){
		if(strEquals(command, commands[i].key)){
			return i;
		}
	}
	return -1;
}

char* echo(char* str){
	return str[0];
}

char* clear(char* str){
	clearScreen();
	return "lucas";
}

char* help(char* str){
	char* message;
	message[0] = '\0';
	for(int i=0; i<TOTAL_COMMANDS;i++){
		message = strcat(message, "-");
		message = strcat(message, commands[i].key);
		message = strcat(message, ": ");
		message = strcat(message, commands[i].use);
		message = strcat(message, "\n");
	}
	return message;
}
