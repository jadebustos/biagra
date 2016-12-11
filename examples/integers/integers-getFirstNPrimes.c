#include <stdio.h>
#include <stdlib.h>

#include <biagra/integers.h>
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

/* Simple example of integers-getFirstNPrimes usage */

int main (void) {

  unsigned int *ptPrimes;
  
  int intNumber,
      Calc,
      i;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  intNumber = uintRandom(100);
  ptPrimes = intPtMemAllocVec(intNumber);

  if ( ptPrimes == NULL ) {
    printf("Error in memory allocation.\n");
    return BIA_MEM_ALLOC;
  }

  /* computing primes */
  getFirstNPrimes(ptPrimes, intNumber, &Calc);

  printf("Computing the first %d prime numbers.\n", intNumber);

  for(i=0;i<Calc;i++)
    printf("i=%d p=%d\n", i, ptPrimes[i]);
  
  return BIA_TRUE;
	
}
