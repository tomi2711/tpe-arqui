#include "screensaver.h"

unsigned int miliseconds = 0;
unsigned int screenSaverTime = DEFAULT_SCREENSAVER_TIME;
bool isShowing = FALSE;
ScreenSaver screenSavers[NUM_SCREENSAVERS];

void kinitScreenSaver(){
    screenSavers[0] = newScreenSaver("\"Hodor, Hodor\"","-Hodor");
    screenSavers[1] = newScreenSaver("\"Be yourself; everyone else is already taken\"",
                                    "-Oscar Wilde");
    screenSavers[2] = newScreenSaver("\"Two things are infinite: the universe and human stupidity; and I\'m not sure about the universe\"",
                                    "-Albert Einstein");
    screenSavers[3] = newScreenSaver("\"Those who believe in telekinetics, raise my hand\"",
                                    "-Kurt Vonnegut");
    screenSavers[4] = newScreenSaver("\"What the world needs is more geniuses with humility, there are so few of us left\"",
                                      "-Oscar Levant");
    screenSavers[5] = newScreenSaver("\"Your time is limited, so don\'t waste it living someone else\'s life\"",
                                    "-Steve Jobs");
    screenSavers[6] = newScreenSaver("\"Whatever the mind of man can conceive and believe, it can achieve\"",
                                    "-Napoleon Hill");
    screenSavers[7] = newScreenSaver("\"You miss 100\% of the shots you don\'t take\"",
                                    "-Wayne Gretzky");
    screenSavers[8] = newScreenSaver("\"Winning isn\'t everything, but wanting to win is\"",
                                    "-Vince Lombardi");
    screenSavers[9] = newScreenSaver("\"If you\'re going to be thinking, you may as well think big\"",
                                    "-Donald Trump");
    screenSavers[10] = newScreenSaver("\"Never put off until tomorrow what you can do the day after tomorrow\"",
                                    "-Mark Twain");
    screenSavers[11] = newScreenSaver("\"Always remember that you are absolutely unique. Just like everyone else\"",
                                    "-Margaret Mead");
    screenSavers[12] = newScreenSaver("\"If you fall, I\'ll always be there\"",
                                    "-The floor");
    screenSavers[13] = newScreenSaver("\"Always borrow money from a pessimist. He won\'t expect it back\"",
                                    "-Oscar Wilde");
    screenSavers[14] = newScreenSaver("\"If you steal from one author, it\'s plagiarism; if you steal from many, it\'s research\"",
                                    "-Wilson Mizner");
    screenSavers[15] = newScreenSaver("\"The quieter you become, the more you are able to hear\"",
                                    "-Richard Alpert");
    screenSavers[16] = newScreenSaver("\"The measure of intelligence is the ability to change\"",
                                    "-Albert Einstein");
    screenSavers[17] = newScreenSaver("\"You know nothing Jon Snow\"",
                                    "-Ygritte");
    screenSavers[18] = newScreenSaver("\"Hope is a good thing, maybe the best of things, and no good thing ever dies\"",
                                    "-Andy Dufresne");
    screenSavers[19] = newScreenSaver("\"Houston, we have a problem\"",
                                    "-James A. Lovell");
    screenSavers[20] = newScreenSaver("\"Keep your friends close, but your enemies closer\"",
                                    "-Vito Corleone");
    screenSavers[21] = newScreenSaver("\"To infinity... and beyond\"",
                                    "-Buzz Lightyear");
    screenSavers[22] = newScreenSaver("\"Why so serious?\"",
                                    "-The Joker");
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
    kmoveCursor(cursorI-5,cursorJ+2);
    kputString(author);
    char* msg = "[Press any key to exit screensaver]";
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
