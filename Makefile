CC = gcc
IDIR = ./include
SDIR = ./src

all:
	$(CC) $(SDIR)/main.c -o srs.exe


clean:
	rm -f srs.exe
