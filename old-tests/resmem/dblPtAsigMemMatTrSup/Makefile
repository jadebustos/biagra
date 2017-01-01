CC=gcc

dblPtAsigMemMatTrSup : resmem.o dblPtAsigMemMatTrSup.o
	gcc -o dblPtAsigMemMatTrSup resmem.o dblPtAsigMemMatTrSup.o

resmem.o : resmem.c
	gcc -c resmem.c

dblPtAsigMemMatTrSup.o : dblPtAsigMemMatTrSup.c
	gcc -c dblPtAsigMemMatTrSup.c

limpiar clean:
	rm resmem.o dblPtAsigMemMatTrSup.o
