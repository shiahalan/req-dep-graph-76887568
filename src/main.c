#include <stdio.h>
#include "../include/txtReader.h"
#include "../include/graphParser.h"
#include "../include/reportParser.h"


int main(){
	printf("Generating SRS-Dependency-Graph.txt");
	// If-else, if failed say something and exit
	//
	printf ("Generating SRS-Report.txt");
	// If-else, if failed say somethign and exit
	readfile("SRS-Dependency-Graph.txt");
	readfile("SRS-Report.txt");
}
