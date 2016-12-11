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

/* Simple example of dblPtMemAllocVec usage */

int main (void) {

  /* Polynomial declaration */
  biaRealPol myPol;

  /* Polynomial order */
  myPol.intDegree = 5;

  int i;

  double x0 = BIA_PI,
	 px0 = .0;

  /* polynomial generation */
  i = randomPol(&myPol);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* evaluate polynomial */
  px0 = dblEvaluatePol(&myPol, x0);

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol);
  printf("x0 = %g\n", x0);
  printf("p(x0) = %g\n", px0);

  return BIA_TRUE;
}
