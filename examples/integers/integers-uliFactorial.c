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

/* Simple example of integers-uliFactorial usage */

int main (void) {

  int n;

  unsigned long int myFactorial;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  n = uintRandom(20);

  /* factorial calculus */
  myFactorial = uliFactorial(n);

  /* print to stdout */
  printf("%d factorial: %ld\n", n, myFactorial);
  
  return BIA_TRUE;
	
}
