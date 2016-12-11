#include <stdio.h>

#include <biagra/polynomial.h>
#include <biagra/resmem.h>
#include <biagra/const.h>

#include "polsupport.h"

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of derivativePol usage */

int main (void) {

  /* Vector declaration */
  biaRealPol myPol,
	     polDer;

  /* Polynomial order */
  myPol.intDegree = 5;

  int i;

  /* polynomial generation */
  i = randomPol(&myPol);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation (myPol).\n");
    return BIA_MEM_ALLOC;
  }

  /* first order derivative */
  i = derivativePol(&myPol, &polDer, 1);

  if ( i == BIA_MEM_ALLOC  ) {
    printf("Error in memory assignation (polDer).\n");
    return BIA_MEM_ALLOC;
  }

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol);
  printf("p'(x) = ");
  pol2Stdout(&polDer);

  return BIA_TRUE;
}
