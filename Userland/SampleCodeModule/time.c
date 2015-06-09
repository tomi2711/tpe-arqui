#include "time.h"

char* daysName[8] = {"", "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char* monthsName[13] = {"", "January","February","March","April","May","June","July","August","September","October",
                      "November","December"};

int handleTime(char* key, char* value);

DATE newDate;

void cleanDate(DATE *date){
    date->second = 0xFF;
    date->minute = 0xFF;
    date->hour = 0xFF;
    date->d_week = 0xFF;
    date->d_month = 0xFF;
    date->month = 0xFF;
    date->year = 0xFF;
}

void printDate(DATE *date){
  printf("%s %d %s 20%n - %n:%n:%n",daysName[date->d_week],date->d_month,monthsName[date->month],date->year, date->hour, date->minute, date->second);
}

int time(char* args){

  DATE date;
  getTime(&date);

  if(strlen(args) == 0){
    printDate(&date);
    return 0;
  }

  char key[MAX_KEY_SIZE];
  char value[MAX_VALUE_SIZE];

  cleanDate(&newDate);

  int total = 0;

  while(strlen(args)!=0){

    clean(value, MAX_VALUE_SIZE);

    int code = split_args(args,key,value);

    if(code == ERROR){
      printf("All values must have keys. ");
      return 0;
    }

    total += handleTime(key, value);
  }

  // set date handler

  if(total!=TIME_NOT_CHANGED){
    setTime(&newDate);
    printf("The time was changed.\n");
    getTime(&date);
    printDate(&date);
  }

  return 0;
}

char validate(DateModifiers modifier, char* value){

  unsigned int input = (unsigned int) atoi(value);

  if(input == -1)
    return -1;

  switch (modifier) {
    case SECOND:
      if(input < 60 && input >= 0)
        return input;
      break;
    case MINUTE:
      if(input < 60 && input >= 0)
        return input;
      break;
    case HOUR:
      if(input < 24 && input >= 0)
        return input;
      break;
    case D_MONTH:
      if(input < 32 && input >= 1)
        return input;
      break;
    case MONTH:
      if(input < 13 && input >= 0)
        return input;
      break;
    case YEAR:
      if(input < 99 && input >= 0)
        return input;
      break;
    default:
    break;
  }

  return -1;
}

void printHelp(){

  printf("The available commands are: \n\n");
  printf("\t-ssecond\t\tSets the system's current seconds.\n");
  printf("\t-sminute\t\tSets the system's current minutes.\n");
  printf("\t-shour\t\tSets the system's current hour.\n");
  printf("\t-sdate\t\tSets the system's current date.\n");
  printf("\t-smonth\t\tSets the system's current month.\n");
  printf("\t-syear\t\tSets the system's current year. Format: YY.\n");
  printf("\n");

}

int handleTime(char* key, char* value){

      if(strEquals(key, "-ssecond")){
          char input = validate(SECOND, value);
          if(input>=0){
             newDate.second = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if(strEquals(key, "-sminute")) {
          char input = validate(MINUTE, value);
          if(input>=0){
             newDate.minute = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if(strEquals(key, "-shour")) {
          char input = validate(HOUR, value);
          if(input>=0){
             newDate.hour = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if(strEquals(key, "-sdate")) {
          char input = validate(D_MONTH, value);
          if(input>=0){
             newDate.d_month = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if(strEquals(key, "-smonth")) {
          char input = validate(MONTH, value);
          if(input>=0){
             newDate.month = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if(strEquals(key, "-syear")) {
          char input = validate(YEAR, value);
          if(input>=0){
             newDate.year = input;
          } else {
            printf("Illegal input in %s. ",key);
            return TIME_NOT_CHANGED;
          }
      } else if (strEquals(key, "-help")){
        printHelp();
        return TIME_NOT_CHANGED;
      } else {
        printf("%s key is unsupported. See -help. ", key);
        return TIME_NOT_CHANGED;
      }

    return TIME_CHANGED;
}
