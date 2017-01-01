CC=gcc

esmatrizidentidad : resmem.o tipomatriz.o esmatrizidentidad.o
	gcc -o esmatrizidentidad resmem.o tipomatriz.o esmatrizidentidad.o

resmem.o : resmem.c
	gcc -c resmem.c

tipomatriz.o : tipomatriz.c
	gcc -c tipomatriz.c

esmatrizidentidad.o : esmatrizidentidad.c
	gcc -c esmatrizidentidad.c

limpiar clean:
	rm resmem.o tipomatriz.o esmatrizidentidad.o
