CC = gcc

all: app run

run:
	./main.o exit.csv caso.txt palavras.html

app:
	$(CC) -Wall palavra.c main.c -o main.o

help:
	./main.o exit.csv caso.txt palavras.html -h

version:
	./main.o exit.csv caso.txt palavras.html -v

clean:
	rm -rf *.o exit.csv palavras.html