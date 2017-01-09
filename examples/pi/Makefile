CC=gcc

pi:
	$(CC) pi-chudnovskyPi.c -o pi-chudnovskyPi.bin -lbiagra -fopenmp -lgmp
	$(CC) pi-threadedPiMidPointRule.c -o pi-threadedPiMidPointRule.bin -lbiagra -fopenmp -lgmp

clean:
	rm -f *.o *~ *.bin
