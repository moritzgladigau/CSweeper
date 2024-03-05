#include "logic.h"

char **logic_field_init(int width, int height)
{
	int i, j;
	char **field = calloc(width, sizeof(char*));
	if (field == NULL) {
		printf(BOLD RED "Feheler beim Allocieren der Breite des Feldes\n" RESET);
		free(field);
		return NULL;
	}

	for (i = 0; i < width; i++) {
		field[i] = calloc(height, sizeof(char));
		if (field[i] == NULL) {
			printf(BOLD RED "Feheler beim Allocieren der Hoehe des Feldes\n" RESET);
			for (j = 0; j < i; j++) {
				free(field[j]);
			}
			free(field);
			return NULL;
		}
	}
	return field;
}

void logic_field_colaps(int width, char **field)
{
	int i;
	for (i = 0; i < width; i++) {
		free(field[i]);
	}
	free(field);
}

void logic_fill_a(int width, int height, char **field)
{
	int i, j;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			field[j][i] = '-';
		}
	}
}

void logic_fill_c(int width, int height, char **field, int numb_of_mine)
{
	logic_place_mine(width, height, field, numb_of_mine);
	logic_place_numb(width, height, field);
}

void logic_place_mine(int width, int height, char **field, int numb_of_mine)
{
	int x, y;
	do{
		x = rand() % width;
		y = rand() % height;
		if (field[x][y] != MINE) {
			field[x][y] = MINE;
			numb_of_mine--;
		}
	} while(numb_of_mine != 0);

}

void logic_place_numb(int width, int height, char **field)
{
	int i, j;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			if (field[i][j] != MINE) {
				field[i][j] = logic_count_surounding_bombs(width, height, field, i, j) + '0';
			}
		}
	}
}

int logic_count_surounding_bombs(int width, int height, char**field, int x, int y)
{
	int i, cx, cy, count = 0;
	int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

	for (i = 0; i < 8; i++) {
		cx = x + dx[i];
		cy = y + dy[i];
		if (cx >= 0 && cx < width && cy >= 0 && cy < height) {
			if (field[cx][cy] == MINE) {
				count++;
			}
		}
	}
	return count;
}


