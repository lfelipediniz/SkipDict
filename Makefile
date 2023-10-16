all: item.o lista.o main.o dicionario.o skiplist.o
	gcc item.o lista.o main.o dicionario.o skiplist.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

lista.o:
	gcc -c lista.c -o lista.o

dicionario.o:
	gcc -c dicionario.c -o dicionario.o
	 	 
main.o:
	gcc -c main.c -o main.o

skiplist.o:
	gcc -c skiplist.c -o skiplist.o

reset: clean all run

clean:
	rm *.o main

run: 
	./main
