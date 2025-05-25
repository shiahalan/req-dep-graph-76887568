#include <stdio.h>
#include "../include/txtReader.h"

void readFile(char* f) {
	// Opens the file for reading
	FILE *file = fopen(f, "r");
	if (file == NULL) {
		printf("File not found...\n");
		return;
	}

	//  Reads the file line by line and prints it to the console
	char lineBuf[256];
	while (fgets(lineBuf, sizeof(lineBuf), file)) {
		printf("%s", lineBuf);
	}

	fclose(file);
}

void threeLines(char* f) {
	FILE *file = fopen(f, "r");
	if (file == NULL) {
		printf("File not found...\n");
		return;
	}

	// Reads the first three lines of the file and prints them to the console
	char lineBuf[256];
	for (int i = 0; i < 3; i++) {
		if (fgets(lineBuf, sizeof(lineBuf), file)) {
			printf("%s", lineBuf);
			continue;
		}
		break;
	}

	fclose(file);
}