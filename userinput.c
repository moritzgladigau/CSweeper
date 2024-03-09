#include "userinput.h"

int move_key_up = 'w';
int move_key_down = 's';
int move_key_left = 'a';
int move_key_right = 'd';
int help_key = 'h';
int open_key = 'o';
int flag_key = 'f';
int quit_key = 'q';

void clear(void) {
	system(CLEAR_COMMAND);
}

void flush(void)
{
        char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int get_user_numb(int length)
{
	int re = 0, i, c;
	printf("Gebe eine Zahl (%i.stellige) ein: ", length);

	for (i = 0; i < length; i++) {
		if ((c = getchar()) >= '0' && c <= '9') {
			re = re * 10 + (c - '0');
		} else {
			break;
		}
	}
	flush();
	return re;
}

char *get_user_name(int length)
{
	char *temp;
	char *name = calloc(length + 1, sizeof(char));
	if (name == NULL) {
		printf(BOLD RED "ERROR: Speicherplatz fuer den Namen konnte nicht Allociert werden\n");
		return NULL;
	}
	do{
		printf("Geben Sie einen Namen ein: ");
		scanf("%s", name);
	} while(strlen(name) > MAX_NAME_LENGTH);

	temp = realloc(name, sizeof(char) * (strlen(name) + 1));
	if (temp == NULL) {
		printf(BOLD RED "ERROR: Speicherplatz fuer den Namen konnte nicht Allociert werden\n");
		free(name);
		return NULL;
	} else {
		name = temp;
	}
	
	flush();
	return name;
}


int get_user_key(void)
{
	int re, c;
	re = getchar();
	if (re == 27) {
		c = getchar();
		re += c;
		if (c == 91) {
			c = getchar();
			re += c;
		}
	}
	return re;	
}

int handle_userinput(int width, int height, int curser[])
{
	int k = get_user_key();
	int i, j;
	
	if (k > '0' && k <= '9') {
		j = k;
		k = get_user_key();
		for (i = 0; i < j; i++) {
			if (k == move_key_up || k == move_key_down || k == move_key_left || k == move_key_right) {
				curser_move(width, height, curser, k);
			}
		}
		return SUCCESS;
	} else if (k == move_key_up || k == move_key_down || k == move_key_left || k == move_key_right) {
		curser_move(width, height, curser, k);
		return SUCCESS;
	} else if (k == help_key) {
		design_anleitung();
	} else if (k == open_key) {
		return OPEN;
	} else if (k == flag_key) {
		return FLAG;
	} else if (k == quit_key) {
		return QUIT;
	} else {
		printf("falsche eingabe\n");
		return ERROR;
	}
	return SUCCESS;
}

void curser_move(int width, int height, int curser[], int key)
{

	if (key == move_key_up) {
		curser[1]--;
	} else if (key == move_key_down) {
		curser[1]++;
	} else if (key == move_key_left) {
		curser[0]--;
	} else if (key == move_key_right) {
		curser[0]++;
	}

	if (curser[0] < 0) {
		curser[0] = width - 1;
	}
	if (curser[0] >= width) {
		curser[0] = 0;
	}
	if (curser[1] < 0) {
		curser[1] = height - 1;
	}
	if (curser[1] >= height) {
		curser[1] = 0;
	}
}
