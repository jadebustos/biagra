#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/resmem.h>
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

/* Simple example of dblPtMemAllocVec usage */

int main (void) {

  /* Data */
  int intElements = 5;

  /* Vector declaration */
  double *dblVector;

  /* Memory reservation por vector */
  dblVector = dblPtMemAllocVec(intElements);

  if ( dblVector == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intElements;i++)
      dblVector[i] = (double) (rand() % 100);

  printf("Random vector:\n\n");
  
  /* Print Vector to stdout */
  for(int i=0;i<intElements;i++)
      printf("%g ", dblVector[i]);

  printf("\n");
  
  return BIA_TRUE;
}
