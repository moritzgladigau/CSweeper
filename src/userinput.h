#ifndef USERINPUT_H
#define USERINPUT_H


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define KEY_ARROW_UP 183
#define KEY_ARROW_DOWN 184
#define KEY_ARROW_LEFT 186
#define KEY_ARROW_RIGHT 185
#define KEY_F1 186
#define KEY_F2 187
#define KEY_F3 188
#define KEY_F4 189
#define KEY_F5 346
#define KEY_F6 348
#define KEY_F7 349
#define KEY_F8 350
#define KEY_F9 342
#define KEY_F10 343
#define KEY_F12 346


void flush(); 
int userinput(char str[], int search); 



#endif
