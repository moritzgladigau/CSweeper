#include "text.h"
#include <stdio.h>

// Hier werden alle Texte auf Deutsch geschrieben.

void text1_de() {
	printf("Hallo Welt\n");
}

void text2_de() {
	printf(BOLD "Wahlen Sie einen Schwierigkeitsgrad aus: \n" RESET);
	printf("\t1. Einfach\n\t2. Normal\n\t3. Schwer\n\t4. Benutzerdefiniert\n");
}

void text3_de(int row, int col, float mine_percentage, int level) {
	printf("Du Spielst mit den Werten: %ix%i - %.1f%%", row, col, mine_percentage);
	switch (level) {
		case 1:
			printf(" -- Einfach\n");
			break;
		case 2:
			printf(" -- Normal\n");
			break;
		case 3:
			printf(" -- Schwer\n");
			break;
		case 4:
			printf(" -- Benutzerdefiniert\n");
			break;
	}

}

void text4_de(int item) {
	printf("Bitte geben Sie den folgenden Wert ein: \n");
	switch (item) {
		case 1:
			printf("Reihen: ");
			break;
		case 2:
			printf("Spalten: ");
			break;
		case 3:
			printf("Minendichte: ");
			break;
		default:
			break;
	}
}
