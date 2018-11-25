CC=gcc

resmem:
	$(CC) resmem-dblPtMemAllocLowerTrMat.c -o resmem-dblPtMemAllocLowerTrMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocMat.c -o resmem-dblPtMemAllocMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocUpperTrMat.c -o resmem-dblPtMemAllocUpperTrMat.bin -lbiagra
	$(CC) resmem-dblPtMemAllocVec.c -o resmem-dblPtMemAllocVec.bin -lbiagra
	$(CC) resmem-intPtMemAllocVec.c -o resmem-intPtMemAllocVec.bin -lbiagra
	$(CC) resmem-intPtMemAllocMat.c -o resmem-intPtMemAllocMat.bin -lbiagra
	$(CC) resmem-intPtMemAllocLowerTrMat.c -o resmem-intPtMemAllocLowerTrMat.bin -lbiagra
	$(CC) resmem-intPtMemAllocUpperTrMat.c -o resmem-intPtMemAllocUpperTrMat.bin -lbiagra

clean:
	rm -f *.o *~ *.bin
