#include "matrix.h"
#include <stdio.h>

// Create a Pointer to a Matrix[rows][cols]
// Set the Allocated Space free with the Funktion down below "freeMatrix(...)"
// Catch all Errors by calling the Funktion in a if(create Matrix(...) != SUCCESS){...} 
int createMatrix(int*** matrix, int rows, int cols) {
	
	*matrix = (int**)calloc(rows, sizeof(int*));

	// Catch ERROR
	if(*matrix == NULL) {
		fprintf(stderr, "ERROR: ALLOCATION_ERROR\n");
		return ALLOCATION_ERROR;
	}

	for(int i = 0; i < rows; i++) {
		(*matrix)[i] = (int*)calloc(cols, sizeof(int));
		// Catch ERROR
		if((*matrix)[i] == NULL) {
			for(int j = 0; j < i; j++) {
				free((*matrix)[j]);
			}
			free(*matrix);
			fprintf(stderr, "ERROR: ALLOCATION_ERROR\n");
			return ALLOCATION_ERROR;
		}
	}

	return SUCCESS; 
}

// Gives the allocated space free
void freeMatrix(int** matrix, int rows) {
	for(int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
				
// TODO: Dose nothing smart right now
void fillMatrix(int** matrix, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			matrix[i][j] = -1;
		}
	}
}

// Simpel print of a Matrix in the Terminal line
void printMatrix(int** matrix, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}
}


