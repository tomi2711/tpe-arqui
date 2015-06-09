#include "screensaver.h"

unsigned int miliseconds = 0;
unsigned int screenSaverTime = DEFAULT_SCREENSAVER_TIME;
unsigned int refreshRate;
bool isShowing = FALSE;

void kinitScreenSaver(){
    refreshRate = kinitQuotes();
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
      if(miliseconds>refreshRate)
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
    updateScreen();
}

void stopScreenSaver(){
    isShowing = FALSE;
    kRestoreScreen();
    miliseconds = 0;
}

void setScreenSaverTime(int time){
    screenSaverTime = time;
}
