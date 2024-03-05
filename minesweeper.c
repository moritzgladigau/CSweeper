#include <stdio.h>
#include "logic.h"
#include "userinput.h"
#include "design.h"

int main (void) 
{
	int width = 8, height = 8;
	double mine_perc = 15.6;
	int numb_of_mine;
	int difficulty = 1;
	int curser[] = {0, 0};
	char *name = "user";
	char **a_field;
	char **c_field;

	srand(time(NULL));

	printf("Hello World\n");

	/* Funktionen Testen */ 	

	/* Programm Start */
	if (design_menu_main(&width, &height, &mine_perc, name, &difficulty) == 0) {
		(strcmp(name, "user") != 0) ? free(name) : (void)0;
		return 0;
	}

	numb_of_mine = (width * height) * mine_perc / 100;

	/* Felder Allocieren und Fuellen */
	a_field = logic_field_init(width, height);
	if (a_field == NULL) {
		printf(BOLD RED "ERROR: Das Spielfeld konnte nicht erstellt werden\n" RESET);
		(strcmp(name, "user") != 0) ? free(name) : (void)0;
		return 0;
	}
	logic_fill_a(width, height, a_field);

	c_field = logic_field_init(width, height);
	if (c_field == NULL) {
		printf(BOLD RED "ERROR: Das Controll-feld konnte nicht erstellt werden\n" RESET);
		(strcmp(name, "user") != 0) ? free(name) : (void)0;
		logic_field_colaps(width, a_field);
		return 0;
	}
	logic_fill_c(width, height, c_field, numb_of_mine);

	design_print_field(width, height, curser, c_field);



	/* Programm Ende */
	logic_field_colaps(width, a_field);
	logic_field_colaps(width, c_field);
	(strcmp(name, "user") != 0) ? free(name) : (void)0;
	return 0;
}
