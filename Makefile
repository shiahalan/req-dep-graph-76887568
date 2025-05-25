CC = gcc
IDIR = ./include
SDIR = ./src
BIN = rdgg-76887568.exe
OUTPUT = rdgg-report-76887568.md SRS-Dependency-Graph.txt

all:
	$(CC) $(SDIR)/main.c $(SDIR)/graphParser.c $(SDIR)/reportParser.c $(SDIR)/txtReader.c -o $(BIN) $(SDIR)/requirementList.c


clean:
	rm -f $(BIN) $(OUTPUT)


run:
	./$(BIN)
