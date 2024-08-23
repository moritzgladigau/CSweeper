#ifndef DESING_H
#define DESING_H

#include <stdio.h>

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


void desing_print_matrix(int **matrix, int rows, int cols, int x_cursor, int y_cursor);
void get_ascii_to_print(int value); 


#endif
