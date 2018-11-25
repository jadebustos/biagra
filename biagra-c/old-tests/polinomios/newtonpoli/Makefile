newtonpoli : resmem.o polinomios.o newtonpoli.o
	gcc -o newtonpoli resmem.o polinomios.o newtonpoli.o -lm

resmem.o : resmem.c
	gcc -c resmem.c

polinomios.o : polinomios.c
	gcc -c polinomios.c

newtonpoli.o : newtonpoli.c
	gcc -c newtonpoli.c

limpiar clean:
	rm resmem.o polinomios.o newtonpoli.o
