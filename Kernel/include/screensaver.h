#ifndef __TomiOS__SCREENSAVER__
#define __TomiOS__SCREENSAVER__

#include "defines.h"
#include "lib.h"
#include "display.h"

void screenSaverTick();
void startScreenSaver();
void stopScreenSaver();
void setScreenSaverTime(int time);
bool isScreenSaverShowing();
void resetTime();

#endif
