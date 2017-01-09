CC=gcc

resmem:
	$(CC) resmem-dblPtMemAllocLowerTrMat.c -o resmem-dblPtMemAllocLowerTrMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocMat.c -o resmem-dblPtMemAllocMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocUpperTrMat.c -o resmem-dblPtMemAllocUpperTrMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocVec.c -o resmem-dblPtMemAllocVec.bin -lbiagra
	$(CC) resmem-intPtMemAllocVec.c -o resmem-intPtMemAllocVec.bin -lbiagra

clean:
	rm -f *.o *~ *.bin
