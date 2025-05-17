#include <stdio.h>
#include "../include/txtReader.h"
#include "../include/graphParser.h"
#include "../include/reportParser.h"


int main(){
	printf("Generating SRS-Dependency-Graph.txt\n");
	// If-else, if failed say something and exit
	//
	printf ("Generating SRS-Report.txt\n");
	// If-else, if failed say somethign and exit
	readFile("SRS-Dependency-Graph.txt");
	readFile("SRS.md");
}
