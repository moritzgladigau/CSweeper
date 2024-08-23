#ifndef TEXT_H
#define TEXT_H

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

// The German Text
void text1_de();
void text2_de();
void text3_de(int row, int col, float mine_percentage, int level); 
void text4_de(int item); 

// The Englisch Text
void text1_en();
void text2_en();
void text3_en(int row, int col, float mine_percentage, int level); 
void text4_en(int item); 

#endif // TEXT_H
