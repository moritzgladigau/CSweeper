#include "text.h"
#include <stdio.h>

// Here all Texts are in Englisch.

void text1_en() {
	printf("Hello World\n");
}

void text2_en() {
    printf(BOLD "Select a difficulty level:\n" RESET);
    printf("\t1. Easy\n\t2. Normal\n\t3. Hard\n\t4. Custom\n");
}

void text3_en(int row, int col, float mine_percentage, int level) {
    printf("You are playing with the settings: %ix%i - %.1f%%", row, col, mine_percentage);
    switch (level) {
    case 1:
        printf(" -- Easy\n");
        break;
    case 2:
        printf(" -- Normal\n");
        break;
    case 3:
        printf(" -- Hard\n");
        break;
    case 4:
        printf(" -- Custom\n");
        break;
}
}

void text4_en(int item) {
    printf("Please enter the following value: \n");
    switch (item) {
        case 1:
            printf("Rows: ");
            break;
        case 2:
            printf("Columns: ");
            break;
        case 3:
            printf("Mine density: ");
            break;
        default:
            break;
    }
}
