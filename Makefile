CC = gcc
IDIR = ./include
SDIR = ./src
BIN = srs.exe

all:
	$(CC) $(SDIR)/main.c $(SDIR)/graphParser.c $(SDIR)/reportParser.c $(SDIR)/txtReader.c -o $(BIN)


clean:
	rm -f srs.exe


run:
	./$(BIN)
