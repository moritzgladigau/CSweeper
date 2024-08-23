#include <stdio.h>
#include "matrix.h"
#include "desing.h"
#include "logic.h"
#include "userinput.h"

#include "text.h"
typedef void (*TextFunction)();

int main(void) {
	// Chose a Language
	int language, language_result;
	
	printf("\t1. ENGLISH\n\t2. DEUTSCH\n");
	printf("=> ");
	do{
		language_result = scanf("%i", &language);

		if (language_result == 0 || language < 1 || language > 2) {
			printf("ERROR => ");
			flush();
		}
	} while( language_result == 0 || language < 1 || language > 2);


	TextFunction text1_func, text2_func, text3_func;

	if (language == 1) {
		// Englisch
		text1_func = text1_en; // Weist die Funktionen zu
	} else {
		// Deutsch (Standard)
		text1_func = text1_de; // Weist die Funktionen zu
	}
	text1_func(); 

	// Start values for the game
	int row = 30;
	int col = 60;

	int x_curser = 0;
	int y_curser = 0;

	int** matrix1;
	int** matrix2;

	// initials a random time used to fill our game 
	srand(time(NULL));

	// initialise the matrix that we will use as reverence for the active game
	createMatrix(&matrix1, row, col);
	logic_fill_matrix(matrix1, row, col, 16.7);

	desing_print_matrix(matrix1, row, col, x_curser, y_curser);
	
	// Important: free the allocated space of the matrix
	freeMatrix(matrix1, row);
	
	// end the program
	return 0;
}
