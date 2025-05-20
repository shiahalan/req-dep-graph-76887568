CC = gcc
IDIR = ./include
SDIR = ./src
BIN = rdgg-76887568.exe

all:
	$(CC) $(SDIR)/main.c $(SDIR)/graphParser.c $(SDIR)/reportParser.c $(SDIR)/txtReader.c -o $(BIN)


clean:
	rm -f $(BIN)


run:
	./$(BIN)
