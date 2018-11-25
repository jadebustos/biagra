#include <stdio.h>
#include <stdlib.h>

#include <biagra/integers.h>
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

/* Simple example of integers-uintSumFirstNIntegers usage */

int main (void) {

  unsigned int sum;
  
  int n;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  n = uintRandom(1000);

  /* addition */
  sum = uintSumFirstNIntegers(n);

  /* print to stdout */
  if ( sum == 0 ){
    printf("Sum of the %d first integers is bigger than unsigned int.\n", n);
  }
  else {
    printf("The sum of the %d first integers is %u.\n", n, sum);
  }
  
  return BIA_TRUE;
	
}
