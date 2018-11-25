CC=gcc

matriznula : resmem.o matriz.o matriznula.o
	gcc -o matriznula resmem.o matriz.o matriznula.o

resmem.o : resmem.c
	gcc -c resmem.c

matriz.o : matriz.c
	gcc -c matriz.c

matriznula.o : matriznula.c
	gcc -c matriznula.c

limpiar clean:
	rm resmem.o matriz.o matriznula.o
