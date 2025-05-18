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
