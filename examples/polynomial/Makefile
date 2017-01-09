CC=gcc

polsupport.o:
	$(CC) -c ../support/polsupport.c -o polsupport.o

polynomial: polsupport.o
	$(CC) polynomial-addPol.c polsupport.o -o polynomial-addPol -lbiagra -lm
	$(CC) polynomial-biaRealPol.c polsupport.o -o polynomial-biaRealPol -lbiagra -lm
	$(CC) polynomial-dblEvaluatePol.c polsupport.o -o polynomial-dblEvaluatePol -lbiagra -lm
	$(CC) polynomial-derivativePol.c polsupport.o -o polynomial-derivativePol -lbiagra -lm
	$(CC) polynomial-multiplyPol.c polsupport.o -o polynomial-multiplyPol -lbiagra -lm
	$(CC) polynomial-polFromRealRoots.c polsupport.o -o polynomial-polFromRealRoots -lbiagra -lm
	$(CC) polynomial-subtractPol.c polsupport.o -o polynomial-subtractPol -lbiagra -lm

clean:
	rm -f *.o *~
