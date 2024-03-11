#include "design.h"


void pic_minesweeper(void)
{
	printf(RED);
	printf("  _______  __                                                                   \n");
	printf(" |   |   ||__|.-----..-----..-----..--.--.--..-----..-----..-----..-----..----. \n");
	printf(" |       ||  ||     ||  -__||__ --||  |  |  ||  -__||  -__||  _  ||  -__||   _| \n");
	printf(" |__|_|__||__||__|__||_____||_____||________||_____||_____||   __||_____||__|   \n");
	printf("                                                           |__|                 \n");
	printf(RESET);
	printf("Press Enter: \n");
	flush();
}

/* Text */
void design_menu_content(void)
{
	printf(BOLD CYAN "1. Spiel Starten\n" RESET);
	printf("2. Schwierigkeit\n");
	printf("3. Spieler Name\n");
	printf("4. Anleitung\n");
	printf("5. Einstellungen\n");
	printf(BOLD "6. Spiel Beenden\n" RESET);
}

void design_dificulty_content(void)
{
	printf("1. Beginner\n");
	printf("2. Intermediate\n");
	printf("3. Expert\n");
	printf("4. User-Define\n");
	printf(BOLD CYAN "5. Back\n" RESET);
}

void design_settings_content(void)
{
	printf("1. Tastenbelegung\n");
	printf("2. Log Einsicht\n");
	printf(BOLD CYAN "3. Back\n" RESET);
}

void design_anleitung(void)
{
	clear();
	printf(UNDERLINE BOLD "\nAnleitung/ Hilfestellung\n" RESET);
	printf("In " BOLD "Minesweeper " RESET "geht es darum in einem vorgegebenen Feld eine bestimmte anzahl an " BOLD "Mienen " RESET "zu finden\nindem man diese mit " BOLD "Flagen " RESET "makiert.\n");
	printf("Um zu " BOLD "gewinnen " RESET "muss mann in dieser version " BOLD "alle Mienen markieren " RESET "und mindestens\n" BOLD "90%% aller uebrigen Felder aufdecken.\n" RESET);
	printf(GREEN "https://de.wikipedia.org/wiki/Minesweeper\n" RESET);
	printf(UNDERLINE BOLD "\nAktuelle Tastenbelegung\n" RESET);

	printf("\tUP: ");
	get_key_name(move_key_up);
	printf("DOWN: ");
	get_key_name(move_key_down);
	printf("LEFT: ");
	get_key_name(move_key_left);
	printf("RIGHT: ");
	get_key_name(move_key_right);
	printf("\n\tOPEN: ");
	get_key_name(open_key);
	printf("FLAG: ");
	get_key_name(flag_key);
	printf("HELP: ");
	get_key_name(help_key);
	printf("QUIT: ");
	get_key_name(quit_key);
	printf("\n\n");

	printf("Look by ");
	printf(BOLD GREEN "https://github.com/moritzgladigau/Minesweeper\n" RESET);

	printf("Um Fortzufahren ");
	get_user_numb(1);
}

/* Menu */
int design_menu_main(int *width, int *height, double *mine_perc, char **name, int *difficulty)
{
	int choice;
	do{
		do {
			clear();
			printf("%s\tKartengroesse %ix%i\t Mine_perc %.1f\t Name: %s\n\n", difficulty_to_char(*difficulty), *width, *height, *mine_perc, *name);
			design_menu_content();
			choice = get_user_numb(1);
		} while (choice < 1 || choice > 6);
	
		switch (choice) {
			case 1:
				printf("Spiel Start\n");
				break;
			case 2:
				design_menu_dificulty(width, height, mine_perc, difficulty);
				break;
			case 3:
				printf("Name Aendern\n");
				*name = get_user_name(MAX_NAME_LENGTH);
				if (name == NULL) {
					*name = "user";
				}
				break;
			case 4:
				design_anleitung();
				break;
			case 5:
				design_menu_settings();
				break;
			case 6:
				printf(BOLD RED "Programm Beenden\n" RESET);
				return 0;
		}
	} while (choice != 1);
	return 1;
}

void design_menu_dificulty(int *width, int *height, double *mine_perc, int *difficulty)
{
	int choice;
	do{
		do{
			clear();
			printf("%s\tKartengroesse %ix%i\t Mine_perc %.1f\n\n", difficulty_to_char(*difficulty),*width, *height, *mine_perc);
			printf("Schwierigkeit\n");
			design_dificulty_content();
			choice = get_user_numb(1);
		} while (choice < 1 || choice > 5);

		switch (choice) {
			case 1:
				printf("Beginner\n");
				*difficulty = 1;
				*width = 8;
				*height = 8;
				*mine_perc = 15.6;
				break;
			case 2:
				printf("Intermediate\n");
				*difficulty = 2;
				*width = 16;
				*height = 16;
				*mine_perc = 15.6;
				break;
			case 3:
				printf("Expert\n");
				*difficulty = 3;
				*width = 30;
				*height = 16;
				*mine_perc = 20.6;
				break;
			case 4:
				printf("User-Define\n");
				*difficulty = 4;
				printf(BOLD "INFO:\tWidth & Height > min.%02d\tMine_perc > min.1%% - max.99%%\n" RESET, FIELD_MIN);
				do{
					printf(UNDERLINE "Width-> " RESET);
					*width = get_user_numb(2);
				} while (*width < FIELD_MIN);
				do{
					printf(UNDERLINE "Height-> " RESET);
					*height = get_user_numb(2);
				} while (*height < FIELD_MIN);
				do{
					printf(UNDERLINE "Mine_perc-> " RESET);
					printf("Gebe eine Zahl (form xx.x) ein: ");
					scanf("%lf", mine_perc);
					flush();
				} while (*mine_perc < 1 || *mine_perc > 99);
				break;
			case 5:
				return;
		}
	} while (choice != 5);
}

void design_menu_settings(void)
{
	int choice;
	
	do{
		do{ 
			clear();
			printf(BOLD UNDERLINE "\nSettings\n" RESET);
			design_settings_content();
			choice = get_user_numb(1);
		} while (choice < 0 || choice > 3);

		switch (choice) {
			case 1:
				design_menu_key_assignment();
				break;
			case 2:
				printf(BOLD YELLOW "Coming Soon\n" RESET);
				get_user_numb(1);
				break;
		}
	} while (choice != 3);
}

void design_menu_key_assignment(void)
{
	int choice;
	int temp;

	do{
		do{
			clear();
			printf(BOLD UNDERLINE "\nkey_assignment\n" RESET);

			printf("1. UP: ");
			get_key_name(move_key_up);
			printf("\n2. DOWN: ");
			get_key_name(move_key_down);
			printf("\n3. LEFT: ");
			get_key_name(move_key_left);
			printf("\n4. RIGHT: ");
			get_key_name(move_key_right);
			printf("\n5. OPEN: ");
			get_key_name(open_key);
			printf("\n6. FLAG: ");
			get_key_name(flag_key);
			printf("\n7. HELP: ");
			get_key_name(help_key);
			printf("\n8. QUIT: ");
			get_key_name(quit_key);
			printf(BOLD CYAN "\n\n9. Back\n" RESET);

			print_multiple_occurrences();
			printf("Die Zahlen 1-9 duerfen nicht belegt werden\n");

			choice = get_user_numb(1);
		} while (choice < 0 || choice > 9);

		switch (choice) {
			case 1:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-UP: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				move_key_up = temp;
				get_key_name(move_key_up);
				flush();
				break;
			case 2:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-DOWN: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				move_key_down = temp;
				get_key_name(move_key_down);
				flush();
				break;
			case 3:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-LEFT: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				move_key_left = temp;
				get_key_name(move_key_left);
				flush();
				break;
			case 4:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-RIGHT: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				move_key_right = temp;
				get_key_name(move_key_right);
				flush();
				break;
			case 5:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-OPEN: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				open_key = temp;
				get_key_name(open_key);
				flush();
				break;
			case 6:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-FLAG: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				flag_key = temp;
				get_key_name(flag_key);
				flush();
				break;
			case 7:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-HELP: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				help_key = temp;
				get_key_name(help_key);
				flush();
				break;
			case 8:
				do{
					printf(UNDERLINE "NEW" RESET BOLD "-QUIT: " RESET);
					temp = get_user_key();
				} while ((temp > '0' && temp <= '9') || temp == '\n');
				quit_key = temp;
				get_key_name(quit_key);
				flush();
				break;
		}
	} while (choice != 9 || print_multiple_occurrences() != 0);
}



 /* logic */
void design_print_field(int width, int height, int curser[], char **field)
{
	int i, j;
	for (i = -1; i <= height; i++) {
		for (j = -1; j <= width; j++) {
			if (j == -1 || j == width) {
				BORDER_V();
			} else if (i == -1 || i == height) {
				BORDER_H();
			} else {
				if (curser[0] == j && curser[1] == i) {
					printf(CYAN "[%c]" RESET, field[i][j]);
				} else if (field[i][j] == '0') {
					printf("   ");
				} else if (field[i][j] == '1') {
					printf(BLUE " 1 " RESET);
				} else if (field[i][j] == '2') {
					printf(GREEN " 2 " RESET);
				} else if (field[i][j] == '3') {
					printf(RED " 3 " RESET);
				} else if (field[i][j] == '4') {
					printf(DARK_BLUE " 4 " RESET);
				} else if (field[i][j] == '5') {
					printf(DARK_RED " 5 " RESET);
				} else if (field[i][j] == '6') {
					printf(YELLOW " 6 " RESET);
				} else if (field[i][j] == '7') {
					printf(PURPLE " 7 " RESET);
				} else if (field[i][j] == '8') {
					printf(LIGHT_GRAY " 8 " RESET);
				} else if (field[i][j] == 'f') {
					printf(CYAN " F " RESET);
				} else {
					printf(" %c ", field[i][j]);
				}
			}
		}
		printf("\n");
	}
}

char *difficulty_to_char(int difficulty)
{
	switch (difficulty) {
		case 1:
			return "Beginner";
		case 2:
			return "Intermediate";
		case 3:
			return "Expert";
		case 4:
			return "User-Define";
		default:
            		return "Unknown";
	}
}

void info_texte(int c)
{
	switch (c) {
		case ERROR_IS_FLAG:
			printf(BOLD "INFO:" RESET " Das Feld kann nicht geoefnet werden.\n\t->Flage Entfernen mit der 'FLAG' Taste um es dann zu oeffnen.\n");
			break;
		case ERROR_IS_OPEN:
			printf(BOLD "INFO:" RESET " Das Feld ist bereits geoefnet und kann d.h. nicht mehr bearbeitet werden.\n");
			break;
		default:
			break;
	}
}

void get_key_name(int key_code) 
{
	if(key_code > 126) {
		switch (key_code) {
			case 183: printf("Arrow-Up\t"); break;
			case 184: printf("Arrow-Down\t"); break;
			case 185: printf("Arrow-Right\t"); break;
			case 186: printf("Arrow-Left\t"); break;
			default:  
				  printf(" \t"); break;
		}
	} else {
		printf("%c\t", key_code);
	}
}

int print_multiple_occurrences(void)
{
	enum Keys {
		MoveKeyUp = 1,
		MoveKeyDown = 2,
		MoveKeyLeft = 3,
		MoveKeyRight = 4,
		HelpKey = 8,
		OpenKey = 5,
		FlagKey = 7,
		QuitKey = 6
    	};

	int keys[] = {MoveKeyUp, MoveKeyDown, MoveKeyLeft, MoveKeyRight, HelpKey, OpenKey, FlagKey, QuitKey};
	int num_keys = sizeof(keys) / sizeof(keys[0]);
	int occurrences[8] = {0};
	int count = 0;
	int i, j;

	keys[0] = move_key_up;
	keys[1] = move_key_down;
	keys[2] = move_key_left;
	keys[3] = move_key_right;
	keys[4] = help_key;
	keys[5] = open_key;
	keys[6] = flag_key;
	keys[7] = quit_key;

	for (i = 0; i < num_keys - 1; i++) {
		for (j = i + 1; j < num_keys; j++) {
			if (keys[i] == keys[j]) {
				occurrences[i] = keys[i];
				count++;
			}
		}
	}

	for (i = 0; i < num_keys; i++) {
		if (occurrences[i] > 0) {
			printf(BOLD RED "ACHTUNG: " UNDERLINE);
			get_key_name(occurrences[i]);
			printf(RESET BOLD RED " ist mehrfach belegt!!!\n" RESET);
		}
	}
	return count;
}

