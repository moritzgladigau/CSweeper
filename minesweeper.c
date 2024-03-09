#include <stdio.h>
#include "logic.h"
#include "userinput.h"
#include "design.h"

#define ERROR 0
#define SUCCESS 1

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
	
	time_t t_start, t_end;
	double t_diff;

	srand(time(NULL));

	printf("Hello World\n");

	/* Funktionen Testen */ 	

	

	/* Programm Start */
	do{
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

		time(&t_start);

		while (input != QUIT && info != GAME_END && logic_check(width, height, a_field, c_field, numb_of_mine, count_open) != GAME_END) {
			clear();	

			printf("%s\tMapsize: %ix%i\tMine_Perc: %0.1f\t\tName: %s\n", difficulty_to_char(difficulty), width, height, mine_perc, name);
			printf("Open: %i/%i\t", count_open, (width * height - numb_of_mine));
			printf("Flag: %i/%i\t\t", count_flag, numb_of_mine);
			printf("Help: ");
			get_key_name(help_key);
			printf("\tTime: %.0fsec\n\n", t_diff);

			design_print_field(width, height, curser, a_field);
			info_texte(info);
			input = handle_userinput(width, height, curser);
			info = logic_key_aktion(width, height, input, curser, a_field, c_field, &count_open, &count_flag, numb_of_mine); 
			flush();

			time(&t_end);
			t_diff = difftime(t_end, t_start);
		}

		clear();
		printf(BOLD CYAN "Spielfeld\n" RESET);
		design_print_field(width, height, curser, a_field);
		printf(BOLD CYAN "Loesungsfeld\n" RESET);
		design_print_field(width, height, curser, c_field);

		if (info == GAME_END) {
			printf(BOLD RED "Du hast leider verloren :/\n" RESET);
		}
		if (logic_check(width, height, a_field, c_field, numb_of_mine, count_open) == GAME_END) {
			printf(BOLD CYAN "Du hast gewonnen :)\n");
		}
		

		/* Programm Ende */
		logic_field_colaps(width, a_field);
		logic_field_colaps(width, c_field);

		if (input == QUIT) {
			printf(BOLD RED "Spiel Abgebrochen & Programm Beenden\n" RESET);
			break;
		} else {
			printf(BOLD CYAN "Wollen Sie weiter Spielen? [y|n]\n" RESET);
			if (get_user_key() == 'n') {
				printf(BOLD RED "Programm Beenden\n" RESET);
				break;
			}
			curser[0] = 0;
			curser[1] = 0;
			input = 0;
			info = 0;
			count_open = 0;
			count_flag = 0;
			flush();
		}
	} while (1);

	(strcmp(name, "user") != 0) ? free(name) : (void)0;
	return 0;
}
