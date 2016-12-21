CC=gcc

pi:
	$(CC) pi-threadedPiMidPointRule.c -o pi-threadedPiMidPointRule -lbiagra -fopenmp -lgmp
	$(CC) pi-chudnovskyPi.c -o pi-chudnovskyPi -lbiagra -fopenmp -lgmp

clean:
	rm -f *.o *~
