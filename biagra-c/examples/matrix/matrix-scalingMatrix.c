#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/resmem.h>
#include <biagra/matrix.h>
#include <biagra/random.h>
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

/* Simple example of scalingMatrix usage */

int main (void) {

  /* Data */
  int intRows = 5;
  double dblFactor;

  /* Matrix declaration */
  biaMatrix myMatrix;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myMatrix.intRows = intRows;
  myMatrix.intCols = intRows;
  dblFactor = (double)uintRandom(50);

  /* Memory reservation por matrix */
  myMatrix.dblCoefs = dblPtMemAllocMat(myMatrix.intRows, myMatrix.intRows);

  if ( myMatrix.dblCoefs == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* identiy matrix */
  scalingMatrix(&myMatrix, dblFactor);

  printf("Scaling matrix of order %d:\n\n", myMatrix.intRows);
  
  /* Print Matrix to stdout */
  for(int i=0;i<intRows;i++) {
    for(int j=0;j<intRows;j++) {
      printf("%g ", myMatrix.dblCoefs[i][j]);
      }
    printf("\n");
    }

  return BIA_TRUE;
}
