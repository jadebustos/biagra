CC=gcc

rngktexp : resmem.o rngkutta.o rngktexp.o
	 gcc -o rngktexp resmem.o rngkutta.o rngktexp.o

resmem.o : resmem.c 
	 gcc -c resmem.c

rngkutta.o : rngkutta.c 
	 gcc -c rngkutta.c

rngktexp.o : rngktexp.c
	 gcc -c rngktexp.c

limpiar clean:
	rm resmem.o rngkutta.o rngktexp.o
