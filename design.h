#ifndef DESIGN_H
#define DESIGN_H

#include <stdio.h>
#include "userinput.h"

/* ANSI Escape Codes for text color */
#define CYAN    "\x1B[36m"
#define BLUE 	"\x1b[34m"
#define GREEN 	"\x1b[32m"
#define RED 	"\x1b[31m"
#define PURPLE 	"\x1b[35m"
#define GRAY 	"\x1b[30m"
#define YELLOW  "\x1B[33m"
#define DARK_BLUE 	"\x1b[34;1m"
#define DARK_RED 	"\x1b[31;1m"
#define LIGHT_GRAY 	"\x1b[37m"

#define UNDERLINE "\033[4m"
#define BOLD "\033[1m"
#define RESET   "\x1B[0m"

#define BORDER_H() printf(CYAN "===" RESET)
#define BORDER_V() printf(CYAN "|" RESET)

#define FIELD_MIN 03

/* Text */
void design_menu_content(void);
void design_dificulty_content(void);
void design_anleitung(void);

/* Menu */
int design_menu_main(int *width, int *height, double *mine_perc, char *name, int *difficulty);
void design_menu_dificulty(int *width, int *height, double *mine_perc, int *difficulty);

/* logic */
void design_print_field(int width, int height, int curser[], char **field);
char *difficulty_to_char(int difficulty);


#endif
