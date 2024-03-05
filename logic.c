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
