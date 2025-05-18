#include <stdio.h>
#include <string.h>
#include "../include/graphParser.h"

int generateDependency(char* f) {
	f[strcspn(f, "\n")] = 0;
	FILE *inputFile = fopen(f, "r");
	if (inputFile == NULL)
		return 1;
	FILE *outputFile = fopen("SRS-Dependency-Graph.txt", "w");
	if (outputFile == NULL) {
		fclose(inputFile);
		return 1;
	}

	fprintf(outputFile, "The \"->\" symbol indicates a dependency\n\n");

	char module[256];
	while (fgets(module, sizeof(module), inputFile) != NULL) {
		if (module[0] != '#' || module[1] != '#' || module[2] != '#')
			continue;

		char *strip;

		char tmp[256];
		char desc[256];
		char dep[256];

		module[strcspn(module, "\n")] = 0;

		fgets(tmp, sizeof(tmp), inputFile);
		fgets(desc, sizeof(desc), inputFile);
		fgets(dep, sizeof(dep), inputFile);
		
		strip = module + 7;
		strcat(strip, desc + 13);
		fprintf(outputFile, "%s", strip);

		strip = dep + 14;
		fprintf(outputFile, " -->");

		int i = 0;
		while (strip[i] != '\n') {
			if (strip[i] == ',') {
				fprintf(outputFile, "\n");
				fprintf(outputFile, " -->");
			} else {
				if (strip[i] != '`' && strip[i] != ' ')
					fprintf(outputFile, "%c", strip[i]);
			}
			i++;
		}
		fprintf(outputFile, "\n\n");
	}
	
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}	
