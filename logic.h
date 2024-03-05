#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include "design.h"

char **logic_field_init(int width, int height);
void logic_field_colaps(int width, char **field);

void logic_fill_a(int width, int height, char **field);
#endif
