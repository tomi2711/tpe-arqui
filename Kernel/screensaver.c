#include "screensaver.h"

unsigned int miliseconds = 0;
unsigned int screenSaverTime = DEFAULT_SCREENSAVER_TIME;
bool isShowing = FALSE;
ScreenSaver screenSavers[NUM_SCREENSAVERS];

void kinitScreenSaver(){
    screenSavers[0] = newScreenSaver("\"frase 1\"","-autor1");
    screenSavers[1] = newScreenSaver("\"frase 2\"","-autor2");
    screenSavers[2] = newScreenSaver("\"frase 3\"","-autor3");
    screenSavers[3] = newScreenSaver("\"frase 4\"","-autor4");
    screenSavers[4] = newScreenSaver("\"frase 5\"","-autor5");
    screenSavers[5] = newScreenSaver("\"frase 6\"","-autor6");
    screenSavers[6] = newScreenSaver("\"frase 7\"","-autor7");
    screenSavers[7] = newScreenSaver("\"frase 8\"","-autor8");
    screenSavers[8] = newScreenSaver("\"frase 9\"","-autor9");
    screenSavers[9] = newScreenSaver("\"frase 10\"","-autor10");
    screenSavers[10] = newScreenSaver("\"frase 11\"","-autor11");
}

bool isScreenSaverShowing(){
    return isShowing;
}

void resetTime(){
    miliseconds = 0;
}

void screenSaverTick(){

  miliseconds += 55;

  if(isShowing){
      if(miliseconds>SCREENSAVER_CHANGE_TIME)
          startScreenSaver();
      return;
  }

  if(miliseconds>screenSaverTime){
      kBackupScreen();
      startScreenSaver();
  }
}

void startScreenSaver(){
    isShowing = TRUE;
    miliseconds = 0;
    ksetCursorStyle(NO_CURSOR);
    kclearScreen();
    showRandomScreensaver();
}

void stopScreenSaver(){
    isShowing = FALSE;
    kRestoreScreen();
    miliseconds = 0;
}

void setScreenSaverTime(int time){
    screenSaverTime = time;
}

void showRandomScreensaver(){
    int id= krandom(NUM_SCREENSAVERS);
    char* phrase = screenSavers[id].phrase;
    char* author = screenSavers[id].author;
    int cursorJ = 8;
    int cursorI = (kgetScreenWidth()-kstrlen(phrase))/2;
    kmoveCursor(cursorI, cursorJ);
    kputString(phrase);
    kputNewLine();
    cursorI = kgetScreenWidth()-kstrlen(author);
    kmoveCursor(cursorI-5,cursorJ+1);
    kputString(author);
    char* msg = "[Press any key to continue]";
    cursorJ = kgetScreenHeight()-3;
    cursorI = (kgetScreenWidth()-kstrlen(msg))/2;
    kmoveCursor(cursorI,cursorJ);
    kputString(msg);
}

ScreenSaver newScreenSaver(char* phrase, char* author){
  ScreenSaver screenSaver;
  screenSaver.phrase = phrase;
  screenSaver.author = author;
  return screenSaver;
}
