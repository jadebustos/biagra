#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/polynomial.h>
#include <biagra/resmem.h>
#include <biagra/roots.h>
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

/* Simple example of newtonPol usage */

int main (void) {

  /* Polynomial declaration */
  biaRealPol myPol;

  /* Root declaration */
  biaRealRoot myRoot;

  int i;

  double px0;

  /* Polynomial order */
  myPol.intDegree = 5;

  /* Root initialization */
  myRoot.intMNI = 256;
  myRoot.dblTol = 0.0001;

  /* random x0 */
  srand(time(NULL));
  myRoot.dblx0 = (double)(rand()/(double)RAND_MAX);
  myRoot.dblx0 += (double) ((rand() % 10) + 1.);
  if ( (rand() % 2) == 0 )
    myRoot.dblx0 *= -1.;

  /* polynomial generation */
  i = randomPol(&myPol);

  if ( i == BIA_MEM_ALLOC ) {
    printf("Error in memory assignation.\n");
    return BIA_MEM_ALLOC;
  }

  /* Root approximation */
  i = newtonPol(&myPol, &myRoot);

  switch(i) {
    case BIA_MEM_ALLOC:
      printf("Error in memory assignation (newtonPol).\n");
      exit(i);
    case BIA_ZERO_DIV:
      printf("Division by zero (newtonPol).\n");
      exit(i);
    case BIA_FALSE:
      printf("Root could not be approximated.\n");
      break;
    case BIA_TRUE:
      printf("Root successfully approximated.\n");
      break;
  }

  /* Printing polynomial to stdout */
  printf("p(x) = ");
  pol2Stdout(&myPol);
  printf("MNI: %d\n", myRoot.intMNI);
  printf("Tolerance: %g\n", myRoot.dblTol);
  printf("x0 = %g\n", myRoot.dblx0);
  printf("Root: %g\n", myRoot.dblRoot);
  px0 = dblEvaluatePol(&myPol, myRoot.dblRoot);
  printf("p(%g) = %g\n", myRoot.dblRoot, px0);
  printf("Error: %g\n", myRoot.dblError);
  printf("Iterations used: %d\n", myRoot.intIte);

  return BIA_TRUE;
}
