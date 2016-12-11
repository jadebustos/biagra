#include <stdio.h>

#include <biagra/resmem.h>
#include <biagra/matrix.h>
#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of identityMatrix usage */

int main (void) {

  /* Data */
  int intRows = 5,
      res;

  /* Matrix declaration */
  biaMatrix myMatrix;

  /* initialization */
  myMatrix.intRows = intRows;
  myMatrix.intCols = intRows;

  /* Memory reservation por matrix */
  myMatrix.dblCoefs = dblPtMemAllocMat(myMatrix.intRows, myMatrix.intRows);

  if ( myMatrix.dblCoefs == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* identity matrix */
  identityMatrix(&myMatrix);

  res = (int)isIdentityMatrix(&myMatrix);

  if ( res == BIA_TRUE ) {
    printf("Matrix is an identity matrix.\n");
  }
  else {
    printf("Matrix is not an identity matrix.\n");
  }

  /* Print Matrix to stdout */
  for(int i=0;i<intRows;i++) {
    for(int j=0;j<intRows;j++) {
      printf("%g ", myMatrix.dblCoefs[i][j]);
      }
    printf("\n");
    }

  return BIA_TRUE;
}
