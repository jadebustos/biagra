#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

/* Simple example of newton method usage to find roots in f(x) = sin(x) */

/* f(x) = x^2 -2 */
int myfunc(double x0, double *fx0) {
  *fx0 = (double)(x0 * x0 - 2.);
  return BIA_TRUE;
}

/* f'(x) = 2*x */
int myfuncder(double x0, double *fx0) {
  *fx0 = 2.*x0;
  return BIA_TRUE;
}

int main (void) {

  /* function to approximate the root */
  int myfunc(double x0, double *fx0);

  /* function's derivative */
  int myfuncder(double x0, double *fx0);

  /* Root declaration */
  biaRealRoot myRoot;

  int i;

  double fx0;

  /* Root initialization */
  myRoot.intMNI = 256;
  myRoot.dblTol = 0.000001;

  /* random x0 */
  srand(time(NULL));
  myRoot.dblx0 = (double)(rand()/(double)RAND_MAX);
  myRoot.dblx0 += (double) ((rand() % 4) + 1.);

  /* Root approximation */
  i = newtonMethod(&myRoot, &myfunc, &myfuncder);

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

  printf("f(x) = x^2 - 2\n");
  printf("MNI: %d\n", myRoot.intMNI);
  printf("Tolerance: %g\n", myRoot.dblTol);
  printf("x0 = %g\n", myRoot.dblx0);
  printf("Root: %g\n", myRoot.dblRoot);
  i = myfunc(myRoot.dblRoot, &fx0);
  if ( i == BIA_TRUE )
    printf("f(%g) = %g\n", myRoot.dblRoot, fx0);
  else
    printf("Division by zero.\n");
  printf("Error: %g\n", myRoot.dblError);
  printf("Iterations used: %d\n", myRoot.intIte);

  return BIA_TRUE;
}
