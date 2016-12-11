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

/* Simple example of integers-isPrime usage */

int main (void) {

  int n,
      i;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  /*n = uintRandom(100000);*/
  n = uintRandom(100);

  /* addition */
  i = isPrime(n);
printf("i: %d\n", i);
  /* print to stdout */
  if ( i == BIA_TRUE ){
    printf("%d is a prime number.\n", n);
  }
  else {
    printf("%d not is a prime number.\n", n);
  }
  
  return BIA_TRUE;
	
}
