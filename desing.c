#include "design.h"

/* Text */
void design_menu_content(void)
{
	printf("1. Spiel Starten\n");
	printf("2. Schwierigkeit\n");
	printf("3. Spieler Name\n");
	printf("4. Anleitung\n");
	printf("5. Einstellungen\n");
	printf("6. Programm Beenden\n");
}

void design_dificulty_content(void)
{
	printf("1. Beginner\n");
	printf("2. Intermediate\n");
	printf("3. Expert\n");
	printf("4. User-Define\n");
	printf("5. Back\n");
}

/* Menu */
int design_menu_main(int *width, int *height, double *mine_perc, char *name, int *difficulty)
{
	int choice;
	do{
		do {
			clear();
			printf("%s\tKartengroesse %ix%i\t Mine_perc %.1f\t Name: %s\n\n", difficulty_to_char(*difficulty), *width, *height, *mine_perc, name);
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
				name = get_user_name(MAX_NAME_LENGTH);
				if (name == NULL) {
					name = "user";
				}
				break;
			case 4:
				printf("Case 4");
				break;
			case 5:
				printf("Case 5");
				break;
			case 6:
				printf("Case 6");
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
					printf(GRAY " 8 " RESET);
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
