#include "userinput.h"
#include <stdio.h>

// Delete everything in the standard input buffer 
void flush() {
	char c = getchar();
	while(c != '\n' && c != EOF) {
		c = getchar();
	}
}

// Calculate a number out of all preset keys (important for arrow and Funktion keys): Arrow-Up = ^[[A = 156
int userinput_get_input() {
	char c = getchar(), c1;
	// Check if it starts with an ESC Sequence
	if (c == '\033') {
		c1 = getchar();
		if (c1 == '[') {
			// Which arrow Key
			c = getchar();
			if (c == 'A') {
				return KEY_ARROW_UP;
			} else if (c == 'B') {
				return KEY_ARROW_DOWN;
			} else if (c == 'C') {
				return KEY_ARROW_RIGHT;
			} else if (c == 'D') {
				return KEY_ARROW_LEFT;
			} else {
				printf("ERROR: Key\n");
				return -1;
			}
		}
		// TODO: else if(...) for the F- Funktion keys
	} else if (isdigit(c)) {
		return -1 * userinput_get_number(c);
	}

	printf("Key: %c\n", c);
	return c;
}

// Get a number or return an error = 0 
int userinput_get_number(int c) {
	int numb = 0, puffer = c, i = 0;
	
	do {
		if (isdigit(puffer)) {
			numb *= (i++ == 0) ? 1 : 10;
			numb += puffer - '0';
		} else {
			break;
		}
	} while((puffer = getchar()) != '\n' && puffer != EOF); 

	return numb;
}

// Get the user input use search 1. to get the pressed Key and 2. to get an number
int userinput(char str[], int search) {
	int length = strlen(str);
	int i, numb = 0, step = 0;

	for (i = 0; i < length; i++) {
		switch (search) {
			case 1:
				if (str[i] == '\033') {
					// Is ESC Symbol
					if (str[i+1] == '[') {
						// Is Arrow Key
						if (str[i+2] == 'A') {
							return KEY_ARROW_UP;
						} else if (str[i+2] == 'B') {
							return KEY_ARROW_DOWN;
						} else if (str[i+2] == 'C') {
							return KEY_ARROW_RIGHT;
						} else if (str[i+2] == 'D') {
							return KEY_ARROW_LEFT;
						} else {
							printf("ERROR: Key\n");
							return -1;
						}
					}
				} else if (isdigit(str[i]) || isblank(str[i]) || str[i] == ' ') {
					continue;
				} else if (!isblank(str[i])) {
					// get ASCII code 
					return str[i];
				}
				break;
			case 2:
				if (isdigit(str[i])) {
					// Calculate Number change to negative value
					do {
						numb *= (step++ == 0) ? 1 : 10;
						numb += str[i++] - '0';
					} while (isdigit(str[i]));
					return numb;
				}
				break;
		}
	}
	return 0;
}

