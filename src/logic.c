#include "logic.h"
#include "userinput.h"

// Set up a Matrix for a Minesweeper Game by Setting MINES and the Visibility of them from another field.
// Don't forget to write: srand(time(NULL)); in your main for a randomised Matrix.
void logic_fill_matrix(int **matrix, int rows, int cols, float mine_percentage) {
	logic_set_mines(matrix, rows, cols, mine_percentage);
	logic_set_numbers(matrix, rows, cols);
}
	
// Set at random Places in a Matrix the value for a MINE
// Don't forget to write: srand(time(NULL)); in your main for a randomised Matrix.
void logic_set_mines(int **matrix, int rows, int cols, float mine_percentage) {
	int col_value, row_value;
	int number_of_mines = ceil(rows * cols * mine_percentage / 100);

	do{
		col_value = rand() % cols;
		row_value = rand() % rows;
		
		if(matrix[row_value][col_value] != MINE) {
			matrix[row_value][col_value] = MINE;
			number_of_mines--;
		}
	}while(number_of_mines != 0);
}

// Sets in a Matrix field the number of surrounding MINES count by the Funktion logic_count_surrounding_mine
void logic_set_numbers(int **matrix, int rows, int cols) {
	int count, row_pos, col_pos; 

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(matrix[i][j] != MINE) {
				matrix[i][j] = logic_count_surounding_mine(matrix, rows, cols, j, i);
			}
		}
	}

}

// Count how many MINES a field in a Matrix can see (min. 0 - max. 8) 
int logic_count_surounding_mine(int **matrix, int rows, int cols, int x, int y) {
	int count=0, cx, cy;

	int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int dy[] = {-1, -1, -1, 0 , 0, 1, 1, 1};

	for (int i = 0; i < 8; i++) {
		cx = x + dx[i];
		cy = y + dy[i];

		if(cx < cols && cx >= 0 && cy < rows && cy >= 0) {
			count = count + ((matrix[cy][cx] == MINE) ? 1 : 0);
		}
	}
	return count;
}

// Move the Cursor
int logic_key_aktion(int rows, int cols, int key, int *x_cursor, int *y_cursor, int **matrix1, int **matrix2) {
//	if (key == KEY_ARROW_DOWN || key == KEY_ARROW_UP || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT) {
		switch (key) {
			case KEY_ARROW_UP:
				*y_cursor = ((*y_cursor) - 1 >= 0) ? (*y_cursor) - 1 : rows - 1;
				break;
			case KEY_ARROW_DOWN:
				*y_cursor = ((*y_cursor) + 1 < rows) ? (*y_cursor) + 1 : 0;
				break;
			case KEY_ARROW_LEFT:
				*x_cursor = ((*x_cursor) - 1 >= 0) ? (*x_cursor) - 1 : cols - 1;
				break;
			case KEY_ARROW_RIGHT:
				*x_cursor = ((*x_cursor) + 1 < cols) ? (*x_cursor) + 1 : 0;
				break;
			case 'o':
				matrix2[*y_cursor][*x_cursor] = (matrix2[*y_cursor][*x_cursor] == -2) ? matrix2[*y_cursor][*x_cursor] : matrix1[*y_cursor][*x_cursor];
				break;
			case 'f':
				if (matrix2[*y_cursor][*x_cursor] < 0) {
					matrix2[*y_cursor][*x_cursor] = (matrix2[*y_cursor][*x_cursor] == -2) ? -1 : -2; 
				}
				break;
		}
//	}
	return 1;

}
