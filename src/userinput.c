#include "userinput.h"

// Delete everything in the standard input buffer 
void flush() {
	char c = getchar();
	while(c != '\n' && c != EOF) {
		c = getchar();
	}
}

// Calculate a number out of all preset keys (important for arrow and Funktion keys): Arrow-Up = ^[[A = 156
int userinput_get_input() {
	int key, puffer;

	while((puffer = getchar()) != '\n' && puffer != EOF) {
		key += puffer;
	}
	return key - 1;
}

// Get a number or return an error = 0 
int userinput_get_number() {
	int numb = 0, puffer, i = 0;
	
	while((puffer = getchar()) != '\n' && puffer != EOF) {
		if (isdigit(puffer)) {
			numb *= (i++ == 0) ? 1 : 10;
			numb += puffer - '0';
		} else {
			break;
		}
	}

	return numb;
}

