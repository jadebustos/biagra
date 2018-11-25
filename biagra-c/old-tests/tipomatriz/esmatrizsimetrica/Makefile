CC=gcc

esmatrizsimetrica : resmem.o tipomatriz.o esmatrizsimetrica.o
	gcc -o esmatrizsimetrica resmem.o tipomatriz.o esmatrizsimetrica.o

resmem.o : resmem.c
	gcc -c resmem.c

tipomatriz.o : tipomatriz.c
	gcc -c tipomatriz.c

esmatrizsimetrica.o : esmatrizsimetrica.c
	gcc -c esmatrizsimetrica.c

limpiar clean:
	rm resmem.o tipomatriz.o esmatrizsimetrica.o
