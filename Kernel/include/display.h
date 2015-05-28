#ifndef __TomiOS__display__
#define __TomiOS__display__

#include "lib.h"

#define SCREEN_WIDTH     80
#define SCREEN_HEIGHT	25

#define CURSOR_BLOCK	0x00
#define CURSOR_LINE	0x0E
#define NO_CURSOR	0x10

typedef enum COLOR{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    YELLOW,
    WHITE
} Color;

// Optional initializer
void kinitScreen();

// Erase content
void kclearScreen(void);

// Handle scrolling
void kscrollDown(int n);

// Handle text cursor
void kputNewLine();
void kforwardCursor();
void kcursorTick();

// Insert text
void kputChar(char c);
void kputString(char* str);

// Screen height and width in number of lines
int kgetScreenHeight();
int kgetScreenWidth();

// Theming
void ksetBackgroundColor(Color color);
void ksetDefaultTextColor(Color color);
void ksetCursorStyle(unsigned char style);

#endif
