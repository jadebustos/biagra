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

/* Simple example of dblPtMemAllocMat usage */

int main (void) {

  /* Data */
  int intRows = 5,
      intCols = 6;

  /* Matrix declaration */
  double **dblMatrix;

  /* Memory reservation por vector */
  dblMatrix = dblPtMemAllocMat(intRows, intCols);

  if ( dblMatrix == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intRows;i++)
    for(int j=0;j<intCols;j++) {
      dblMatrix[i][j] = udblRandom(101);
    }

  printf("Random matrix:\n\n");
  
  /* Print Matrix to stdout */
  for(int i=0;i<intRows;i++) {
    for(int j=0;j<intCols;j++) {
      printf("%g ", dblMatrix[i][j]);
      }
    printf("\n");
    }

  /* freeing memory */
  freeMemDblMat(dblMatrix, intRows);
        
  return BIA_TRUE;
}
