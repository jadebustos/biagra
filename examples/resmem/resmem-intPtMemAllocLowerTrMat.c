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

/* Simple example of intPtMemAllocLowerTrMat usage */

int main (void) {

  /* Data */
  int intOrder = 5;

  /* Matrix declaration */
  int **intMatrix;

  /* Memory reservation por vector */
  intMatrix = intPtMemAllocLowerTrMat(intOrder);

  if ( intMatrix == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intOrder;i++) {
    for(int j=0;j<=i;j++) {
      intMatrix[i][j] = uintRandom(101);
      }
    }

  printf("Lower triangular matrix:\n\n");
  
  /* Print Matrix to stdout */
  for(int i=0;i<intOrder;i++) {
    for(int j=0;j<intOrder;j++) {
	if ( i < j)
	    printf("0 ");
	else
	    printf("%d ",intMatrix[i][j]);
      }
    printf("\n");
    }

  /* freeing memory */
  freeMemIntMat(intMatrix, intOrder);

  return BIA_TRUE;
}
