#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "design.h"

#define MINE 'M'

char **logic_field_init(int width, int height);
void logic_field_colaps(int width, char **field);

void logic_fill_a(int width, int height, char **field);
void logic_fill_c(int width, int height, char **field, int numb_of_mine);
void logic_place_mine(int width, int height, char **field, int numb_of_mine);
void logic_place_numb(int width, int height, char **field);

int logic_count_surounding_bombs(int width, int height, char**field, int x, int y);
#endif
