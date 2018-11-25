CC=gcc

esmatriznula : resmem.o tipomatriz.o esmatriznula.o
	gcc -o esmatriznula resmem.o tipomatriz.o esmatriznula.o

resmem.o : resmem.c
	gcc -c resmem.c

tipomatriz.o : tipomatriz.c
	gcc -c tipomatriz.c

esmatriznula.o : esmatriznula.c
	gcc -c esmatriznula.c

limpiar clean:
	rm resmem.o tipomatriz.o esmatriznula.o
