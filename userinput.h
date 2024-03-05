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

void clear(void);
void flush(void);
int get_user_numb(int length);
char *get_user_name(int length);

#endif
