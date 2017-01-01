CC=gcc

matriztraspuesta : resmem.o matriz.o matriztraspuesta.o
	gcc -o matriztraspuesta resmem.o matriz.o matriztraspuesta.o

resmem.o : resmem.c
	gcc -c resmem.c

matriz.o : matriz.c
	gcc -c matriz.c

matriztraspuesta.o : matriztraspuesta.c
	gcc -c matriztraspuesta.c

limpiar clean:
	rm resmem.o matriz.o matriztraspuesta.o
