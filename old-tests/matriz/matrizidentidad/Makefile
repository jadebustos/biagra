CC=gcc

matrizidentidad : resmem.o matriz.o matrizidentidad.o
	gcc -o matrizidentidad resmem.o matriz.o matrizidentidad.o

resmem.o : resmem.c
	gcc -c resmem.c

matriz.o : matriz.c
	gcc -c matriz.c

matrizidentidad.o : matrizidentidad.c
	gcc -c matrizidentidad.c

limpiar clean :
	rm resmem.o matriz.o matrizidentidad.o
