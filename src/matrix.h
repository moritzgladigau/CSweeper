#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0;
#define ALLOCATION_ERROR 1;

int createMatrix(int*** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
void fillMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);






#endif
