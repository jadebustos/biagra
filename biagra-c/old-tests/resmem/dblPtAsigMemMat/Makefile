CC=gcc

dblPtAsigMemMat : resmem.o dblPtAsigMemMat.o
	gcc -o dblPtAsigMemMat resmem.o dblPtAsigMemMat.o

resmem.o : resmem.c
	gcc -c resmem.c

dblPtAsigMemMat.o : dblPtAsigMemMat.c
	gcc -c dblPtAsigMemMat.c

limpiar clean:
	rm resmem.o dblPtAsigMemMat.o
