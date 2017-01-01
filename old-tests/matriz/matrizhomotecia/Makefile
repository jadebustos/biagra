CC=gcc

matrizhomotecia : resmem.o matriz.o matrizhomotecia.o
	gcc -o matrizhomotecia resmem.o matriz.o matrizhomotecia.o

resmem.o : resmem.c
	gcc -c resmem.c

matriz.o : matriz.c
	gcc -c matriz.c

matrizhomotecia.o : matrizhomotecia.c
	gcc -c matrizhomotecia.c

limpiar clean:
	rm resmem.o matriz.o matrizhomotecia.o
