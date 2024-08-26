#include "userinput.h"
#include <stdio.h>

// Delete everything in the standard input buffer 
void flush() {
	char c = getchar();
	while(c != '\n' && c != EOF) {
		c = getchar();
	}
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
	return 1;
}

