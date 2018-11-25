CC=gcc

dblPtAsigMemMatTrInf : resmem.o dblPtAsigMemMatTrInf.o
	gcc -o dblPtAsigMemMatTrInf resmem.o dblPtAsigMemMatTrInf.o

resmem.o : resmem.c
	gcc -c resmem.c

dblPtAsigMemMatTrInf.o : dblPtAsigMemMatTrInf.c
	gcc -c dblPtAsigMemMatTrInf.c

limpiar clean:
	rm resmem.o dblPtAsigMemMatTrInf.o
