#ifndef WORK_TXT_H
#define WORK_TXT_H

#include "design.h"

#define VERSION "v1.1.0-beta"

#define FILE_DIRECTORY "../txt/"
#define FILE_NAME_SAVE "save.txt"
#define FILE_NAME_LOG "game-log.txt"

int check_if_file_exist(char *file_name);
int create_save_file(void);
 
char *get_from_file_table(char *file_name, int row, int col);
char *concatenate_path(const char *file_name);


/* TODO: */
int get_max_row(char *file_name);

#endif
