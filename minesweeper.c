#include <stdio.h>
#include "logic.h"
#include "userinput.h"
#include "design.h"

#define ERROR 0
#define SUCCSES 1

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

	int input = 0, info = 0;
	int count_open = 0;
	int count_flag = 0;

	srand(time(NULL));

	printf("Hello World\n");

	/* Funktionen Testen */ 	

	/* Programm Start */
	if (design_menu_main(&width, &height, &mine_perc, &name, &difficulty) == 0) {
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



	while (input != QUIT && info != GAME_END && logic_check(width, height, a_field, c_field, numb_of_mine, count_open) != GAME_END) {
		clear();	
		printf("%s\tMapsize: %ix%i\tMine_Perc: %0.1f\t\tName: %s\n", difficulty_to_char(difficulty), width, height, mine_perc, name);
		printf("Open: %i/%i\t", count_open, (width * height - numb_of_mine));
		printf("Flag: %i/%i\n\n", count_flag, numb_of_mine);
		design_print_field(width, height, curser, a_field);
		info_texte(info);
		input = handle_userinput(width, height, curser);
		info = logic_key_aktion(width, height, input, curser, a_field, c_field, &count_open, &count_flag, numb_of_mine); 
		flush();
	}

	/* Programm Ende */
	logic_field_colaps(width, a_field);
	logic_field_colaps(width, c_field);
	(strcmp(name, "user") != 0) ? free(name) : (void)0;
	return 0;
}
