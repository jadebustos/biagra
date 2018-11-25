CC=gcc

dblPtAsigMemVec : resmem.o dblPtAsigMemVec.o
	gcc -o dblPtAsigMemVec resmem.o dblPtAsigMemVec.o

resmem.o : resmem.c
	gcc -c resmem.c

dblPtAsigMemVec.o : dblPtAsigMemVec.c
	gcc -c dblPtAsigMemVec.c

limpiar clean:
	rm resmem.o dblPtAsigMemVec.o
