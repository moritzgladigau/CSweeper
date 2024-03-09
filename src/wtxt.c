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
		if (strcmp(FILE_NAME_SAVE, file_name) == 0) {
			create_save_file();
		}
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
		printf(BOLD GREEN "Es wurde erfolgreich ein Save file für Sie angelegt.\n" RESET);
		file = fopen(path, "a");
		fprintf(file, "Save C-Minesweeper " VERSION "\t~\n");
		fprintf(file, "move_key_up:\t%i\t~\n", move_key_up);
		fprintf(file, "move_key_down:\t%i\t~\n", move_key_down);
		fprintf(file, "move_key_left:\t%i\t~\n", move_key_left);
		fprintf(file, "move_key_right:\t%i\t~\n", move_key_right);
		fprintf(file, "open_key:\t%i\t~\n", open_key);
		fprintf(file, "flag_key:\t%i\t~\n", flag_key);
		fprintf(file, "quit_key:\t%i\t~\n", quit_key);
		fprintf(file, "help_key:\t%i\t~\n", help_key);

		fclose(file);
		free(path);
		return SUCCESS;
	}

	printf(BOLD RED "Es konte keine Save file für Sie angelegt.\n" RESET);
	free(path);
	return ERROR;
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
    char *path = malloc(strlen(FILE_DIRECTORY) + strlen(file_name) + 1);

    if (path == NULL) {
        printf(BOLD RED "Speicherzuweisung fehlgeschlagen!\n" RESET);
        return NULL;
    }

    strcpy(path, FILE_DIRECTORY);
    strcat(path, file_name);

    return path;
}
