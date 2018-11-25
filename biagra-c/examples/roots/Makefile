CC=gcc

polsupport.o:
	$(CC) -c ../support/polsupport.c -o polsupport.o   

roots: polsupport.o
	$(CC) roots-newtonPol.c polsupport.o -o roots-newtonPol -lbiagra -lm
	$(CC) roots-newtonMethod.c -o roots-newtonMethod -lbiagra -lm

clean:                                                                                                                                                
	rm -f *.o *~
