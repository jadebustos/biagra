CC=gcc

evaluarpoli: resmem.o polinomios.o evaluarpoli.o
	gcc -o evaluarpoli resmem.o polinomios.o evaluarpoli.o -lm

resmem.o: resmem.c
	gcc -c resmem.c

polinomios.o : polinomios.c
	gcc -c polinomios.c

evaluarpoli.o : evaluarpoli.c
	gcc -c evaluarpoli.c

limpiar clean:
	rm resmem.o polinomios.o evaluarpoli.o
