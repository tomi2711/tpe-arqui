#include "screensaver.h"

unsigned int miliseconds = 0;
unsigned int screenSaverTime = DEFAULT_SCREENSAVER_TIME;
bool isShowing = FALSE;

bool isScreenSaverShowing(){
    return isShowing;
}

void resetTime(){
    miliseconds = 0;
}

void screenSaverTick(){

    if(isShowing)
        return;

    miliseconds += 55;
    if(miliseconds>screenSaverTime){
        startScreenSaver();
    }
}

void startScreenSaver(){
    isShowing = TRUE;
    miliseconds = 0;
    ksetCursorStyle(NO_CURSOR);
    kBackupScreen();
    kclearScreen();
}

void stopScreenSaver(){
    isShowing = FALSE;
    kRestoreScreen();
    miliseconds = 0;
}

void setScreenSaverTime(int time){
    screenSaverTime = time;
}
