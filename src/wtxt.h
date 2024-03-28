#ifndef WORK_TXT_H
#define WORK_TXT_H

#include "design.h"
#include <time.h>

#define VERSION "v1.1.0-beta"

#define FILE_DIRECTORY "~/Library/Application\ Support/minesweeper/"
#define FILE_NAME_SAVE "Config_v.1.1.0-beta.txt"
#define FILE_NAME_LOG "game-log.txt"

int check_if_file_exist(char *file_name);
int create_save_file(void);
int create_log_file(void);
 
char *get_from_file_table(char *file_name, int row, int col);
char *concatenate_path(const char *file_name);

int get_max_row(char *file_name);
int get_game_id(void);
char *get_day(void);
char *get_clock(void);

void update_log_file(int width, int heigth, double mine_perc, double play_time, int difficulty, char *name, char *game_end, int open_fields);
int calculate_score(int fieldsize, double mine_perc, double play_time, int open_fields, char *game_end);
/* TODO: */

#endif
