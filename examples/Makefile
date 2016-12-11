CC=gcc

complex:
	$(CC) complex-addComplex.c -o complex-addComplex -lbiagra -lm
	$(CC) complex-subtractComplex.c -o complex-subtractComplex -lbiagra -lm
	$(CC) complex-multiplyComplex.c -o complex-multiplyComplex -lbiagra -lm
	$(CC) complex-divideComplex.c -o complex-divideComplex -lbiagra -lm
	$(CC) complex-dblComplexModulus.c -o complex-dblComplexModulus -lbiagra -lm
	$(CC) complex-dblComplexArg.c -o complex-dblComplexArg -lbiagra -lm
	$(CC) complex-conjugateComplex.c -o complex-conjugateComplex -lbiagra -lm
	$(CC) complex-complex2Polar.c -o complex-complex2Polar -lbiagra -lm
	$(CC) complex-polar2Complex.c -o complex-polar2Complex -lbiagra -lm

integers:
	$(CC) integers-uintSumFirstNIntegers.c -o integers-uintSumFirstNIntegers -lbiagra -lm
	$(CC) integers-isPrime.c -o integers-isPrime -lbiagra -lm
	$(CC) integers-getFirstNPrimes.c -o integers-getFirstNPrimes -lbiagra -lm

matrix:
	$(CC) matrix-identityMatrix.c -o matrix-identityMatrix -lbiagra
	$(CC) matrix-scalingMatrix.c -o matrix-scalingMatrix -lbiagra
	$(CC) matrix-nullMatrix.c -o matrix-nullMatrix -lbiagra
	$(CC) matrix-transposeMatrix.c -o matrix-transposeMatrix -lbiagra
	$(CC) matrix-isIdentityMatrix.c -o matrix-isIdentityMatrix -lbiagra
	$(CC) matrix-isNullMatrix.c -o matrix-isNullMatrix -lbiagra
	$(CC) matrix-isSymmetricMatrix.c -o matrix-isSymmetricMatrix -lbiagra

polsupport.o:
	$(CC) -c polsupport.c -o polsupport.o

polynomial: polsupport.o
	$(CC) polynomial-biaRealPol.c polsupport.o -o polynomial-biaRealPol -lbiagra
	$(CC) polynomial-dblEvaluatePol.c polsupport.o -o polynomial-dblEvaluatePol -lbiagra
	$(CC) polynomial-derivativePol.c polsupport.o -o polynomial-derivativePol -lbiagra
	$(CC) polynomial-addPol.c polsupport.o -o polynomial-addPol -lbiagra
	$(CC) polynomial-subtractPol.c polsupport.o -o polynomial-subtractPol -lbiagra

resmem:
	$(CC) resmem-dblPtMemAllocVec.c -o resmem-dblPtMemAllocVec -lbiagra
	$(CC) resmem-dblPtMemAllocMat.c -o resmem-dblPtMemAllocMat -lbiagra
	$(CC) resmem-dblPtMemAllocUpperTrMat.c -o resmem-dblPtMemAllocUpperTrMat -lbiagra
	$(CC) resmem-dblPtMemAllocLowerTrMat.c -o resmem-dblPtMemAllocLowerTrMat -lbiagra

roots: polsupport.o
	$(CC) roots-newtonPol.c polsupport.o -o roots-newtonPol -lbiagra -lm
	$(CC) roots-newtonMethod.c -o roots-newtonMethod -lbiagra -lm
all:
	make resmem
	make complex
	make integers
	make matrix
	make polynomial
	make resmem
	make roots

clean:
	rm -f *.o *~
