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
    FILE *outputFile = fopen("rdgg-report-76887568.md", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        return 1;
    }

    // Searches for ### indicating beginning of a module
    int lineNum = 0;
    char lineBuf[512];
    while (fgets(lineBuf, sizeof(lineBuf), inputFile) != NULL) {
        lineNum++;
        if (lineBuf[0] == '#' && lineBuf[1] == ' ') {
            for (int i = 0; i < 3; i++) {
                fprintf(outputFile, "%s", lineBuf);
                lineNum++;
                if (fgets(lineBuf, sizeof(lineBuf), inputFile) == NULL) {
                    break;
                }
            }
            fprintf(outputFile, "%s", "\n");
            continue;
        }

        if (strstr(lineBuf, "ID: REQ") != NULL) {
            char *reqPtr = strstr(lineBuf, "REQ");
            char reqName[512];
            if (reqPtr != NULL) {
                strncpy(reqName, reqPtr, sizeof(reqName) - 1);
                reqName[sizeof(reqName) - 1] = '\0';
                reqName[strcspn(reqName, "\n")] = '\0';
            }

            fprintf(outputFile, "%s", "Line ");
            fprintf(outputFile, "%d: ", lineNum);
            fprintf(outputFile, "%s", reqName);
            fprintf(outputFile, "%s\n", " --");

            char parents[512];
            while(fgets(parents, sizeof(parents), inputFile) != NULL) {
                lineNum++;
                if (strstr(parents, "Parent") != NULL) {
                    break;
                }
            }

            char *strip = strchr(parents, ':');
            if (strip != NULL) {
                strip++;
                while (*strip == ' ' || *strip == '\t') {
                    strip++;
                }
                if (*strip != '-' && *strip != '\n') {
                    char buf[512];
                    strncpy(buf, strip, sizeof(buf));
                    buf[sizeof(buf) - 1] = '\0';

                    char *token = strtok(buf, ",");
                    while (token != NULL) {
                        while (*token == ' ' || *token == '\t') {
                            token++;
                        }
                        token[strcspn(token, "\n")] = '\0';
                        fprintf(outputFile, "%s", "Line ");
                        fprintf(outputFile, "%d: ", lineNum);
                        token[strcspn(token, "\n")] = '\0';
                        fprintf(outputFile, "%s", token);
                        fprintf(outputFile, " -> %s\n", reqName);
                        token = strtok(NULL, ",");
                    }
                }
            }

            char children[512];
            while(fgets(children, sizeof(children), inputFile) != NULL) {
                lineNum++;
                if (strstr(children, "Children") != NULL) {
                    break;
                }
            }

            strip = strchr(children, ':');
            if (strip != NULL) {
                strip++;
                while (*strip == ' ' || *strip == '\t') {
                    strip++;
                }
                if (*strip != '-' && *strip != '\n') {
                    char buf[512];
                    strncpy(buf, strip, sizeof(buf));
                    buf[sizeof(buf) - 1] = '\0';

                    char *token = strtok(buf, ",");
                    while (token != NULL) {
                        while (*token == ' ' || *token == '\t') {
                            token++;
                        }
                        token[strcspn(token, "\n")] = '\0';
                        fprintf(outputFile, "%s", "Line ");
                        fprintf(outputFile, "%d: ", lineNum);
                        fprintf(outputFile, "%s -> ", reqName);
                        token[strcspn(token, "\n")] = '\0';
                        fprintf(outputFile, "%s\n", token);
                        token = strtok(NULL, ",");
                    }
                }
            }
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}