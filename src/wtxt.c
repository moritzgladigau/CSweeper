#include "wtxt.h"
 
int check_if_file_exist(char *file_name)
{
	FILE *file;
	char *path = concatenate_path(file_name); 
	char *temp = NULL;

	file = fopen(path, "r");
	free(path);

	if (file == NULL) {
		printf(BOLD RED " '%s' existiert nicht!\n" RESET, file_name);
		return ERROR;
	}

	printf(BOLD GREEN " '%s' exitiert bereits!\n" RESET, file_name);
	fclose(file);

	if (strcmp(FILE_NAME_SAVE, file_name) == 0) {
		temp = get_from_file_table(file_name, 2, 2);
		if (temp != NULL) {
			move_key_up = atoi(temp);
			free(temp);
		}           

		temp = get_from_file_table(file_name, 3, 2);
		if (temp != NULL) {
			move_key_down = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 4, 2);
		if (temp != NULL) {
			move_key_left = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 5, 2);
		if (temp != NULL) {
			move_key_right = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 6, 2);
		if (temp != NULL) {
			open_key = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 7, 2);
		if (temp != NULL) {
			flag_key = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 8, 2);
		if (temp != NULL) {
			quit_key = atoi(temp);
			free(temp);
		}

		temp = get_from_file_table(file_name, 9, 2);
		if (temp != NULL) {
			help_key = atoi(temp);
			free(temp);
		}

	}

	return SUCCESS;
}

int create_save_file(void)
{
	FILE *file;

	char *path = concatenate_path(FILE_NAME_SAVE);

	file = fopen(path, "w");

	if (file != NULL) {
		printf(BOLD GREEN "Es wurde erfolgreich ein %s file für Sie angelegt.\n" RESET, FILE_NAME_SAVE);
		file = fopen(path, "a");
		free(path);
		fprintf(file, "Config C-Minesweeper " VERSION "\t~\n");
		fprintf(file, "move_key_up:\t%i\t~\n", move_key_up);
		fprintf(file, "move_key_down:\t%i\t~\n", move_key_down);
		fprintf(file, "move_key_left:\t%i\t~\n", move_key_left);
		fprintf(file, "move_key_right:\t%i\t~\n", move_key_right);
		fprintf(file, "open_key:\t%i\t~\n", open_key);
		fprintf(file, "flag_key:\t%i\t~\n", flag_key);
		fprintf(file, "quit_key:\t%i\t~\n", quit_key);
		fprintf(file, "help_key:\t%i\t~\n", help_key);

		fclose(file);
		return SUCCESS;
	}

	printf(BOLD RED "Es konte keine %s file für Sie angelegt.\n" RESET, FILE_NAME_SAVE);
	free(path);
	return ERROR;
}

int create_log_file(void)
{
	FILE *file;
	char *path = concatenate_path(FILE_NAME_LOG);

	file = fopen(path, "w");
	free(path);

	if (file == NULL) {
		printf(BOLD RED "Es konte keine %s file für Sie angelegt.\n" RESET, FILE_NAME_LOG);
		return ERROR;
	}

	fprintf(file, "Log C-Minesweeper " VERSION "\t~\n");
	fprintf(file, "Game-ID\tDay\tTime\tUsername\tGame-End\tDifficulty\tFieldsize\tMine-Perc\tPlaying-Time\tScore\t~\n");

	printf(BOLD GREEN "Es wurde erfolgreich eine Log Datei Angelegt.\n");

	fclose(file);
	return SUCCESS;
}



char *get_from_file_table(char *file_name, int row, int col)
{
	FILE *file;
	char *path = concatenate_path(file_name);
	int i;
	char buffer[100];
	char *token;
	char *result = NULL;

	file = fopen(path, "r");
	free(path);

	if (file == NULL) {
		printf(BOLD RED " '%s' existiert nicht!\n" RESET, file_name);
		return NULL;
	}

	for (i = 0; i < row; i++) {
		if (fgets(buffer, sizeof(buffer), file) == NULL) {
			printf(BOLD RED "Es gibt keine %i Zeilen\n" RESET, row);
			fclose(file);
			return NULL;
		}
	}
	fclose(file);

	/* printf("Buffer: \n%s\n", buffer); */
	
	token = strtok(buffer, "\t");
	for (i = 0; i < col; i++) {
		if (token == NULL) {
			printf(BOLD RED "Es gibt keine %i Spalten\n" RESET, col);
			return NULL;
		}
		if (i == col - 1) { 
			result = calloc(strlen(token) + 1, sizeof(char));
			if (result != NULL) {
				strcpy(result, token);
			}
			break;
		}
		token = strtok(NULL, "\t");
	}

	/* printf(GREEN "result: %s\n" RESET, result); */
	return result;
}

char *concatenate_path(const char *file_name) {

	/* INFO: C-89 Ausnahme */
	const char *home_directory = getenv("HOME");
	
	char *path = malloc(strlen(home_directory) + strlen(FILE_DIRECTORY) + strlen(file_name) + 1);	

	if (home_directory == NULL) {
	    	printf(BOLD RED "Home-Verzeichnis nicht gefunden!\n" RESET);
	    	return NULL;
	}

	if (path == NULL) {
		printf(BOLD RED "Speicherzuweisung fehlgeschlagen!\n" RESET);
		return NULL;
	}	
	strcpy(path, FILE_DIRECTORY);
	strcat(path, file_name);	
	return path;
}

int get_max_row(char *file_name)
{
	FILE *file;
	char *path = concatenate_path(file_name);
	int count = 0;
	char buffer[100];

	file = fopen(path, "r");
	free(path);

	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		count++;
	}

	fclose(file);
	return count;
}

int get_game_id(void)
{
	int re;

	if(strcmp(get_from_file_table(FILE_NAME_LOG, get_max_row(FILE_NAME_LOG), 1), "Game-ID") == 0) {
		return 1;
	}

	re = atoi(get_from_file_table(FILE_NAME_LOG, get_max_row(FILE_NAME_LOG), 1)) + 1;
	return re;
}

char *get_day(void)
{
	time_t t;
        struct tm *info;
        static char time_string[10];

        time(&t);

        info = localtime(&t);

        sprintf(time_string, "%02d.%02d.%02d", info->tm_mday, info->tm_mon + 1, info->tm_year % 100);

        return time_string;
}

char *get_clock(void)
{
        time_t t;
        struct tm *info;
        static char time_string[6];

        time(&t);

        info = localtime(&t);

        sprintf(time_string, "%02d:%02d", info->tm_hour, info->tm_min + 1);

        return time_string;
}

void update_log_file(int width, int height, double mine_perc, double play_time, int difficulty, char *name, char *game_end, int open_fields)
{
	FILE *file;
	char *path = concatenate_path(FILE_NAME_LOG);

	file = fopen(path, "a");
	free(path);

	fprintf(file, "%i\t", get_game_id());
	fprintf(file, "%s\t", get_day());
	fprintf(file, "%s\t", get_clock());
	fprintf(file, "%s\t", name);
	fprintf(file, "%s\t", game_end);
	fprintf(file, "%s\t", difficulty_to_char(difficulty));
	fprintf(file, "%ix%i\t", width, height);
	fprintf(file, "%.1f\t", mine_perc);
	fprintf(file, "%.0fs\t", play_time);
	fprintf(file, "%i\t", calculate_score(width * height, mine_perc, play_time, open_fields, game_end));
	fprintf(file, "~\n");

	fclose(file);
}

int calculate_score(int fieldsize, double mine_perc, double play_time, int open_fields, char *game_end)
{
	int score;
	double end;
	double g1 = 0.3;
	double g2 = 0.2;
	double g3 = 0.15;
	double g4 = 0.2;
	double g5 = 0.15;

	end = (strcmp(game_end, "Win") == 0) ? 1.0 : 0.5;

	score = g1 * end + g2 * fieldsize + g3 * mine_perc + g4 * 1 / play_time + g5 * open_fields; 
	return score;
}
	
