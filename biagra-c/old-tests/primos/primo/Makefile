
CC=gcc

primo : primos.o primo.o
	gcc -o primo primos.o primo.o

primos.o : primos.c
	gcc -c primos.c

primo.o : primo.c
	gcc -c primo.c

limpiar clean:
	rm primos.o primo.o
