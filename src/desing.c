#include "desing.h"
#include "userinput.h"
#include <stdio.h>

// Print the Game field and shows the cursor on the Field
// Return the Number of fields that are visual or -1 if an Mine is Open
int desing_print_matrix(int **matrix, int rows, int cols, int x_cursor, int y_cursor) {
	int count = 0, value;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(i == y_cursor && j == x_cursor) {
				printf("[");
				value = get_ascii_to_print(matrix[i][j]); 
				printf("]");
			} else {
				printf(" ");
				value = get_ascii_to_print(matrix[i][j]);
				printf(" ");
			}
			if (value == 0 && count != -1) {
				count++;
			} else if (value == -1) {
				count = -1;
			}

		}
		printf("\n");
	}
	return count;
}


// Return Value 0 for all numbers 0 - 8, 1 for Flag or not open fields, -1 for a Mine 
// I can use the return value to count recode if a bomb is Open (Game Over) 
int get_ascii_to_print(int value) {
	switch (value) {
		case -2:
			printf("F");
			return 1;
			break;
		case -1:
			printf("-");
			return 1;
			break;
		case 0:
			printf(" ");
			return 0;
			break;
		case 1:
			printf(BLUE "1" RESET);
			return 0;
			break;
		case 2:
			printf(GREEN "2" RESET);
			return 0;
			break;
		case 3:
			printf(RED "3" RESET);
			return 0;
			break;
		case 4:
			printf(DARK_BLUE "4" RESET);
			return 0;
			break;
		case 5:
			printf(DARK_RED "5" RESET);
			return 0;
			break;
		case 6:
			printf(YELLOW "6" RESET);
			return 0;
			break;
		case 7:
			printf(PURPLE "7" RESET);
			return 0;
			break;
		case 8:
			printf(BLUE "8" RESET);
			return 0;
			break;
		case 9:
			printf("B");
			return -1;
			break;
		default:
			printf("?");
			return -1;
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
	


