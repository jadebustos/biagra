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

/* Simple example of intPtMemAllocVec usage */

int main (void) {

  /* Data */
  int intElements = 5;

  /* Vector declaration */
  int *intVector;

  /* Memory reservation por vector */
  intVector = intPtMemAllocVec(intElements);

  if ( intVector == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 100 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<intElements;i++)
      intVector[i] = uintRandom(101);

  printf("Random vector:\n\n");
  
  /* Print Vector to stdout */
  for(int i=0;i<intElements;i++)
      printf("%d ", intVector[i]);

  printf("\n");
  
  return BIA_TRUE;
}
