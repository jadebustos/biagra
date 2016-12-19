#include <stdio.h>
#include <math.h>

#include <biagra/const.h>
#include <biagra/numintegr.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of threadedMidPointRule usage */

/* 1/x^2 function */

long double myfunc(double x) {
 return (1./(x*x));
}

int main (void) {

  int intThreads = 4,
      intN = 5;

  long double approx = .0;

  double a = 1.,
	 b = 2.;

  long double myfunc(double x);

  printf("Using %d threads and %d subintervals to compute 1/x^2 integral in [%g,%g] (midpoint rule).\n", intThreads, intN, a, b);

  approx = threadedMidPointRule(intThreads, intN, a, b, &myfunc);

  printf("Computed value: %.20Lf\n", approx);
  printf("Real Value: %.20Lf\n", (long double)1./2.);
  printf("Error: %.20Lf\n", fabsl(approx - (long double)(1./2.)));

  return BIA_TRUE;
}
