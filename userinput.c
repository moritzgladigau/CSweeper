#include "userinput.h"

void clear(void) {
	system(CLEAR_COMMAND);
}

void flush(void)
{
        char c;
        while ((c = getchar()) != EOF && c != '\n');
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
