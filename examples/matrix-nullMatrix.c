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

/* Simple example of nullMatrix usage */

int main (void) {

  /* Data */
  int intRows = 5,
      intCols = 4;

  /* Matrix declaration */
  biaMatrix myMatrix;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myMatrix.intRows = intRows;
  myMatrix.intCols = intCols;

  /* Memory reservation por matrix */
  myMatrix.dblCoefs = dblPtMemAllocMat(myMatrix.intRows, myMatrix.intRows);

  if ( myMatrix.dblCoefs == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* store elements in matrix */
  for(int i=0;i<intRows;i++)
    for(int j=0;j<intCols;j++)
      myMatrix.dblCoefs[i][j] = dblRandom(50);

  /* identiy matrix */
  nullMatrix(&myMatrix);

  printf("Null matrix:\n\n");
  
  /* Print Matrix to stdout */
  for(int i=0;i<intRows;i++) {
    for(int j=0;j<intCols;j++) {
      printf("%g ", myMatrix.dblCoefs[i][j]);
      }
    printf("\n");
    }

  return BIA_TRUE;
}
