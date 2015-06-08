#include "shell.h"

void initCommandList();
void processAction(char* buffer);
int commandSelector(char* command);
void shellLine();

int echo(char* args);
int clear(char* args);
int help(char* args);
int time(char* args);

/*char* daysName[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char* monthsName[12] = {"January","February","March","April","May","June","July","August","September","October",
                      "November","December"};*/

CommandDescriptor commands[TOTAL_COMMANDS];

void shell(){

  DATE date;
	getTime(&date);

	printf("Boot time: %d:%d\n", date.hour, date.minute);

	char buffer[100];
	initCommandList();

	while(1){
      shellLine();
			read(buffer,'\n');
			processAction(buffer);
	}

}

void initCommandList(){
	commands[0].key = "echo";
	commands[0].handler = &echo;
	commands[0].use = "Repeats text following command.";

	commands[1].key = "clear";
	commands[1].handler = &clear;
	commands[1].use = "Cleans the terminal screen.";

	commands[2].key = "help";
	commands[2].handler = &help;
	commands[2].use = "Displays list of commands.";

  commands[3].key = "time";
  commands[3].handler = &time;
  commands[3].use = "Displays current time.";
}

void shellLine(){
  printf("console$:> ");
}

void processAction(char* buffer){

  char command[MAX_COMMAND_LENGTH];
  char arguments[MAX_ARGUMENTS_LENGTH];

  split_args(buffer, command, arguments);

  if(strlen(command) == 0){
    return;
  }

  int commandId = commandSelector(command);
  int response = 0;

  if(commandId == -1){
    printf("%s is not a valid command.", command);
  } else {
    response = commands[commandId].handler(arguments);
  }

  if(response == 0)
    putChar('\n');
}

int commandSelector(char* command){

	for(int i=0; i<TOTAL_COMMANDS;i++){
		if(strEquals(command, commands[i].key)){
			return i;
		}
	}
	return -1;
}

int time(char* args){

  if(strlen(args)==0){
    DATE date;
    getTime(&date);
    printf("%d/%d/20%d - %d:%d:%d",date.d_month,date.month,date.year, date.hour, date.minute, date.second);
  } else {
    printf("%s is not a time command.", args);
  }
  return 0;
}

int echo(char* args){
  if(strlen(args) == 0)
    printf("");
  else printf(args);
	return 0;
}

int clear(char* args){
	clearScreen();
	return 1;
}

int help(char* args){
	for(int i=0; i<TOTAL_COMMANDS;i++){
    printf("- %s: %s\n",commands[i].key, commands[i].use);
	}
	return 0;
}
