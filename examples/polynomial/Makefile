CC=gcc

polsupport.o:
	$(CC) -c ../support/polsupport.c -o polsupport.o

polynomial: polsupport.o
	$(CC) polynomial-biaRealPol.c polsupport.o -o polynomial-biaRealPol -lbiagra
	$(CC) polynomial-dblEvaluatePol.c polsupport.o -o polynomial-dblEvaluatePol -lbiagra
	$(CC) polynomial-derivativePol.c polsupport.o -o polynomial-derivativePol -lbiagra
	$(CC) polynomial-addPol.c polsupport.o -o polynomial-addPol -lbiagra
	$(CC) polynomial-subtractPol.c polsupport.o -o polynomial-subtractPol -lbiagra

clean:
	rm -f *.o *~
