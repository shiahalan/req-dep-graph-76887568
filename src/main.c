#include <stdio.h>
#include "../include/txtReader.h"
#include "../include/graphParser.h"
#include "../include/reportParser.h"
#include "../include/requirementList.h"


int main(){
	char fileName[256];
	printf("\nEnter name of SRS markdown file: ");
	// fgets reads before printing, so we need to flush stdout
	fflush(stdout);
	fgets(fileName, sizeof(fileName), stdin);

	// Check if the file exists
	if (generateDependency(fileName) == 1) {
		printf("File not found... Exiting...\n\n");
		return 1;
	}

	if (parseReport(fileName) == 1) {
		printf("File not found... Exiting...\n\n");
		return 1;
	}

	printf("\nFirst three lines of given file:\n");
	threeLines(fileName);
	printf("\n- Generating SRS-Dependency-Graph.txt file...\n");
	printf ("- Generating rdgg-report-76887568.md file...\n");
	fflush(stdout);
	
	char tmp[256];
	printf("\nPress enter to view dependency graph in terminal: ");
	fflush(stdout);
	fgets(tmp, sizeof(tmp), stdin);
	printf("\n\n");

	// Output generated files to terminal
	readFile("SRS-Dependency-Graph.txt");

	printf("\nPress enter to view SRS report in terminal: ");
	fflush(stdout);
	fgets(tmp, sizeof(tmp), stdin);
	printf("\n\n");

	readFile("rdgg-report-76887568.md");
}
