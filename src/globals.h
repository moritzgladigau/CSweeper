// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include "text.h"

// Deklariere die Funktionszeiger als extern
extern void (*text1_func)();
extern void (*text2_func)();
extern void (*text3_func)(int row, int col, float mine_percentage, int level);
extern void (*text4_func)(int item);

#endif // GLOBALS_H
