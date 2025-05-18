#include <stdio.h>
#include <string.h>
#include "../include/reportParser.h"

int parseReport(char* f) {
    // Remove newline character from the string
    f[strcspn(f, "\n")] = 0;
    // Open the input file for reading and output file for writing
    FILE *inputFile = fopen(f, "r");
    if (inputFile == NULL)
        return 1;
    FILE *outputFile = fopen("SRS-Report.txt", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    fprintf(outputFile, "Dependency Report\n\n");

    // Searches for ### indicating beginning of a module
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
        
        fprintf(outputFile, "Module Name: ");
        strip = module + 7;
        fprintf(outputFile, "%s", strip);
        fprintf(outputFile, "\n");
    
        fprintf(outputFile, "Description: ");
        strip = desc + 15;
        fprintf(outputFile, "%s", strip);

        fprintf(outputFile, "Dependencies: ");
        strip = dep + 14;
        fprintf(outputFile, "%s", strip);

        fprintf(outputFile, "\n\n");
    }
    
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}