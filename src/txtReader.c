#include <stdio.h>
#include "../include/txtReader.h"

void readFile(char* f) {
	FILE *file = fopen(f, "r");
	if (file == NULL) {
		printf("File not found...");
		return;
	}

	char lineBuf[256];
	while (fgets(lineBuf, sizeof(lineBuf), file)) {
		printf("%s", lineBuf);
	}

	fclose(file);
}
