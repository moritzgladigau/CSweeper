#ifndef USERINPUT_H
#define USERINPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "design.h"

#if defined(_WIN32)
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__linux__)
    #define CLEAR_COMMAND "clear"
#endif

#define MAX_NAME_LENGTH 10

/* Define Key */
#define ARROW_KEY_UP 183
#define ARROW_KEY_DOWN 184
#define ARROW_KEY_LEFT 186
#define ARROW_KEY_RIGHT 185

#define OPEN -1
#define FLAG 'f'
#define QUIT -3
#define ERROR 0
#define SUCCSES 1

void clear(void);
void flush(void);
int get_user_numb(int length);
char *get_user_name(int length);
int get_user_key(void);

int handle_userinput(int width, int height, int curser[]);
void curser_move(int width, int height, int curser[], int key);
#endif
