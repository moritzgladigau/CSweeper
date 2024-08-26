#include <stdio.h>
#include "matrix.h"
#include "desing.h"
#include "logic.h"
#include "userinput.h"

#include "text.h"

void (*text1_func)();
void (*text2_func)();
void (*text3_func)(int row, int col, float mine_percentage, int level);
void (*text4_func)(int item);
void (*text5_func)();

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

	if (language == 1) {
		// Englisch
		text1_func = text1_en; // Weist die Funktionen zu
		text2_func = text2_en;
		text3_func = text3_en;
		text4_func = text4_en;
		text5_func = text5_en;
	} else {
		// Deutsch (Standard)
		text1_func = text1_de; // Weist die Funktionen zu
		text2_func = text2_de;
		text3_func = text3_de;
		text4_func = text4_de;
		text5_func = text5_de;

	}
	text1_func(); 
	flush();

	// Start values for the game
	int row = 30;
	int col = 60;
	float mine_percentage = 16.7;

	int x_cursor = 0;
	int y_cursor = 0;

	int** matrix1;
	int** matrix2;

	int level;
	char buffer[100];
	int key, i, count = 0;

	// initials a random time used to fill our game 
	srand(time(NULL));

	// Start of the visible program 
	// Menu and User inputs
	level = print_level_menu(&row,&col, &mine_percentage); 
	text3_func(row, col, mine_percentage, level);

	// initialise the matrix that we will use as reverence for the active game
	createMatrix(&matrix1, row, col);
	logic_fill_matrix(matrix1, row, col, mine_percentage);

	createMatrix(&matrix2, row, col);
	fillMatrix(matrix2, row, col);
	

//	desing_print_matrix(matrix1, row, col, x_cursor, y_cursor);
	
	// Game Loop, EXIT using 'q'
	do {
		count = desing_print_matrix(matrix2, row, col, x_cursor, y_cursor);
		if (count == -1) {
			break;
		}

		text5_func();
		// Read user input into String
		fgets(buffer, sizeof(buffer), stdin);

		// Divine Between user enter a Number (repeat) and the Acton Key (key)
		key = userinput(buffer, 1);

		// If user enter a Movement Key and a number repeat the user Key in the Background
		// Else do the Key Acton just ones (open a field or flag it)
		if (key == KEY_ARROW_UP || key == KEY_ARROW_DOWN || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT) {
			for (i = 0; i < userinput(buffer, 2); i++) {
				logic_key_aktion(row, col, key, &x_cursor, &y_cursor, matrix1, matrix2);
			}
		} else {
			logic_key_aktion(row, col, key, &x_cursor, &y_cursor, matrix1, matrix2);
		}

		text3_func(row, col, mine_percentage, level);
		printf("Map: %i/%i\n", count, row * col);
			
	} while (key != 'q');
	
	
	// Important: free the allocated space of the matrix
	freeMatrix(matrix1, row);
	freeMatrix(matrix2, row);
	
	// end the program
	return 0;
}
