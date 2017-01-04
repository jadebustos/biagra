CC=gcc

derivadapol : resmem.o polinomios.o derivadapol.o
	gcc -o derivadapol resmem.o polinomios.o derivadapol.o -lm

resmem.o : resmem.c
	gcc -c resmem.c

polinomios.o : polinomios.c
	gcc -c polinomios.c

derivadapol.o : derivadapol.c
	gcc -c derivadapol.c

limpiar clean:
	rm resmem.o polinomios.o derivadapol.o
