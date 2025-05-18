#include <stdio.h>
#include "../include/txtReader.h"
#include "../include/graphParser.h"
#include "../include/reportParser.h"


int main(){
	char fileName[256];
	printf("\nEnter name of SRS markdown file: ");
	fflush(stdout);
	fgets(fileName, sizeof(fileName), stdin);

	if (generateDependency(fileName) == 1) {
		printf("File not found... Exiting...\n\n");
		return 1;
	}

	printf("\n- Generating SRS-Dependency-Graph.txt file...\n");
	printf ("- Generating SRS-Report.txt file...\n");
	fflush(stdout);
	
	char tmp[256];
	printf("\nPress enter to view dependency graph in terminal: ");
	fflush(stdout);
	fgets(tmp, sizeof(tmp), stdin);
	printf("\n\n");

	readFile("SRS-Dependency-Graph.txt");

	printf("\nPress enter to view SRS report in terminal: ");
	fflush(stdout);
	fgets(tmp, sizeof(tmp), stdin);
	printf("\n\n");

	readFile("SRS-Report.txt");
}
