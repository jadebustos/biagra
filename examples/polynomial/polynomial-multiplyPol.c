#include <stdio.h>
#include <unistd.h>

#include <biagra/polynomial.h>
#include <biagra/resmem.h>
#include <biagra/const.h>

#include "../support/polsupport.h"

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of multiplyPol usage */

int main (void) {

  /* polynomial declaration */
  biaRealPol myPol1,
	     myPol2,
	     myRes;

  /* Polynomial order */
  myPol1.intDegree = 2;
  myPol2.intDegree = 3;

  int i;

  /* polynomial generation */
  i = randomPol(&myPol1);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  sleep(1);

  i = randomPol(&myPol2);

  if ( i == BIA_MEM_ALLOC  ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* polynomial multiplication */
  i = multiplyPol(&myPol1, &myPol2, &myRes);

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol1);
  printf("q(x) = ");
  pol2Stdout(&myPol2);
  printf("p(x) * q(x) = ");
  pol2Stdout(&myRes);

  return BIA_TRUE;
}
