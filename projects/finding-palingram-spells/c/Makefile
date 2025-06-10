.PHONY: all clean

CC=cc

all: calculator

calculator: main.o
	$(CC) -o bin/calculator build/main.o

main.o: src/main.c
	$(CC) -c src/main.c -o build/main.o

clean:
	rm -f {bin,build}/*
