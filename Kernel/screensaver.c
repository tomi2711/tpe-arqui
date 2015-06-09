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
    ksetBackgroundColor(CYAN);
    ksetDefaultTextColor(BLUE);
    isShowing = TRUE;
    miliseconds = 0;
    kclearScreen();
    ksetCursorStyle(NO_CURSOR);
    updateScreen();
}

void stopScreenSaver(){
    isShowing = FALSE;
    ksetBackgroundColor(DEFAULT_BG_COLOR);
    ksetDefaultTextColor(DEFAULT_TEXT_COLOR);
    kRestoreScreen();
    miliseconds = 0;
}

void setScreenSaverTime(int time){
    screenSaverTime = time;
}
