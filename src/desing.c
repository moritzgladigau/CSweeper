#include "desing.h"
#include <stdio.h>

// Print the Game field and shows the cursor on the Field
void desing_print_matrix(int **matrix, int rows, int cols, int x_cursor, int y_cursor) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(i == y_cursor && j == x_cursor) {
				printf("[");
				get_ascii_to_print(matrix[i][j]); 
				printf("]");
			} else {
				printf(" ");
				get_ascii_to_print(matrix[i][j]);
				printf(" ");
			}
		}
		printf("\n");
	}
}


// TODO: Return Value idea: CONTINUE if value -1->8, FLAG if value -2, BOMB if value 9
// I can use the return value to count recode if a bomb is Open (Game Over) 
void get_ascii_to_print(int value) {
	switch (value) {
		case -2:
			printf("F");
			break;
		case -1:
			printf("-");
			break;
		case 0:
			printf(" ");
			break;
		case 1:
			printf(BLUE "1" RESET);
			break;
		case 2:
			printf(GREEN "2" RESET);
			break;
		case 3:
			printf(RED "3" RESET);
			break;
		case 4:
			printf(DARK_BLUE "4" RESET);
			break;
		case 5:
			printf(DARK_RED "5" RESET);
			break;
		case 6:
			printf(YELLOW "6" RESET);
			break;
		case 7:
			printf(PURPLE "7" RESET);
			break;
		case 8:
			printf(BLUE "8" RESET);
			break;
		case 9:
			printf("B");
			break;
		default:
			printf("?");
			break;
	}
}



