#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MINE 9

void logic_set_mines(int **matrix, int rows, int cols, float mine_percentage); 
int logic_count_surounding_mine(int **matrix, int rows, int cols, int x, int y); 
void logic_set_numbers(int **matrix, int rows, int cols);
void logic_fill_matrix(int **matrix, int rows, int cols, float mine_percentage);
int logic_key_aktion(); 




#endif
