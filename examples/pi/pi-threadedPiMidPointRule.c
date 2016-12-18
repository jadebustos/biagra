#include <stdio.h>

#include <biagra/const.h>
#include <biagra/pi.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of threadedPiMidPointRule usage */

int main (void) {

  int intThreads = 4,
      intIterations = 2;

  long double pi = .0;

  printf("Using %d threads and %d iterations to compute PI decimals (mid point rule).\n", intThreads, intIterations);

  pi = threadedPiMidPointRule(intThreads, intIterations);

  printf("Pi: %.80Lf\n", pi);

  return BIA_TRUE;
}
