#include "wtxt.h"
 
int check_if_file_exist(char file_name)
{
	FILE *file;

	file = fopen(file_name, "r");

	if (file == NULL) {
		printf(BOLD RED " '%s' existiert nicht!\n" RESET);
		return ERROR;
	}
	return SUCCSESS;
}
