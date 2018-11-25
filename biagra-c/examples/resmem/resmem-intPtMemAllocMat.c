#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/resmem.h>
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

/* Simple example of intPtMemAllocMat usage */

int main (void) {

  /* Data */
  int intRows = 5,
      intCols = 6;

  /* Matrix declaration */
  int **intMatrix;

  /* Memory reservation por vector */
  intMatrix = intPtMemAllocMat(intRows, intCols);

  if ( intMatrix == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intRows;i++)
    for(int j=0;j<intCols;j++) {
      intMatrix[i][j] = uintRandom(101);
    }

  printf("Random matrix:\n\n");
  
  /* Print Matrix to stdout */
  for(int i=0;i<intRows;i++) {
    for(int j=0;j<intCols;j++) {
      printf("%d ", intMatrix[i][j]);
      }
    printf("\n");
    }

  /* freeing memory */
  freeMemIntMat(intMatrix, intRows);

  return BIA_TRUE;
}
