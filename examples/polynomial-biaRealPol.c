#include <stdio.h>
#include <stdlib.h>

#include <biagra/polynomial.h>
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

/* Simple example of biaRealPol usage */

int main (void) {

  /* Polynomial degree */
  int polDegree = 3,
      i;

  /* Polynomial declaration */
  biaRealPol myPol;

  /* Polynomial degree */
  myPol.intDegree = polDegree;

  /* polynomial initialization */
  i = randomPol(&myPol);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol);

  return BIA_TRUE;
}
