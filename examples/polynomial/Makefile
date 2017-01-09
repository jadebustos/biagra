CC=gcc

polsupport.o:
	$(CC) -c ../support/polsupport.c -o polsupport.o

polynomial: polsupport.o
	$(CC) polynomial-addPol.c polsupport.o -o polynomial-addPol.bin -lbiagra -lm
	$(CC) polynomial-biaRealPol.c polsupport.o -o polynomial-biaRealPol.bin -lbiagra -lm
	$(CC) polynomial-dblEvaluatePol.c polsupport.o -o polynomial-dblEvaluatePol.bin -lbiagra -lm
	$(CC) polynomial-derivativePol.c polsupport.o -o polynomial-derivativePol.bin -lbiagra -lm
	$(CC) polynomial-multiplyPol.c polsupport.o -o polynomial-multiplyPol.bin -lbiagra -lm
	$(CC) polynomial-polFromRealRoots.c polsupport.o -o polynomial-polFromRealRoots.bin -lbiagra -lm
	$(CC) polynomial-subtractPol.c polsupport.o -o polynomial-subtractPol.bin -lbiagra -lm

clean:
	rm -f *.o *~ *.bin
