CC=gcc

matrix:
	$(CC) matrix-identityMatrix.c -o matrix-identityMatrix -lbiagra
	$(CC) matrix-scalingMatrix.c -o matrix-scalingMatrix -lbiagra
	$(CC) matrix-nullMatrix.c -o matrix-nullMatrix -lbiagra
	$(CC) matrix-transposeMatrix.c -o matrix-transposeMatrix -lbiagra
	$(CC) matrix-isIdentityMatrix.c -o matrix-isIdentityMatrix -lbiagra
	$(CC) matrix-isNullMatrix.c -o matrix-isNullMatrix -lbiagra
	$(CC) matrix-isSymmetricMatrix.c -o matrix-isSymmetricMatrix -lbiagra

clean:
	rm -f *.o *~
