#include "desing.h"
#include "userinput.h"
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

// Ask wich level (Simpel to Hard) you want to play returns the number of the level
int print_level_menu(int *row, int *col, float *mine_percentage) {
	int choice; 
	int puffer;
	
	text2_func();
	do {
		printf("=> ");
		scanf("%i", &choice);	
		if (choice == 0) {
			printf(RED "FLUSH" RESET);
			flush();
		}
	}while(choice < 1 || choice > 4);
	flush();

	switch (choice) {
		case 1:
			*row = 8;
			*col = 8;
			*mine_percentage = 15.6;
			break;
		case 2:
			*row = 16;
			*col = 16;
			*mine_percentage = 15.6;
			break;
		case 3:
			*row = 30;
			*col = 16;
			*mine_percentage = 20.6;
			break;
		case 4:
			do {
				text4_func(1);
				puffer = scanf("%i", row);
				flush();
			} while (puffer == 0);

			do {
				text4_func(2);
				puffer = scanf("%i", col);
				flush();
			} while (puffer == 0);

			do {
				text4_func(3);
				puffer = scanf("%f", mine_percentage);
				flush();
			} while (puffer == 0);
			break;
	}
	return choice;
}	
	


