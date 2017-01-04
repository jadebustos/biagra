#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <biagra/polynomial.h>
#include <biagra/resmem.h>
#include <biagra/random.h>
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

/* Simple example of addPol usage */

int main (void) {

  /* polynomial declaration */
  biaRealPol myPol;

  int i,
      intRootNumber = 6;

  double *dblRoots,
	 dblValue;

  dblRoots = (double *)dblPtMemAllocVec(intRootNumber);

  if ( dblRoots == NULL ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* root random generation */
  srand(time(NULL));
  for(i=0;i<intRootNumber;i++) {
    dblRoots[i] = dblRandom(10);
  }

  /* get general form */
  i = polFromRealRoots(dblRoots, intRootNumber, &myPol);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol);

  /* roots */
  for(i=0;i<intRootNumber;i++) {
    dblValue = dblEvaluatePol(&myPol, dblRoots[i]);
    printf("p(%g) = %g\n", myPol.dblRoots[i], dblValue);
  }

  return BIA_TRUE;
}
