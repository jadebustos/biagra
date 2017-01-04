CC=gcc

multiplicarpol : resmem.o polinomios.o multiplicarpol.o
	gcc -o multiplicarpol resmem.o polinomios.o multiplicarpol.o -lm

resmem.o : resmem.c
	gcc -c resmem.c

polinomios.o : polinomios.c
	gcc -c polinomios.c

multiplicarpol.o : multiplicarpol.c
	gcc -c multiplicarpol.c

limpiar clean :
	rm resmem.o polinomios.o multiplicarpol.o
