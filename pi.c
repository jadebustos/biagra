#include <stdlib.h>
#include <limits.h>
#include <omp.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

long double threadedPiMidPointRule(int intThreads, int intIterations) {

  unsigned int i = 0;

  int  threads = intThreads,
       j = 0,
       iterations = intIterations;

  long double x = .0,
              dx = 1./UINT_MAX,
              pi = .0;

  for(j=0;j<iterations;j++) { 
    #pragma omp parallel num_threads(threads) private(x)
    { 
      #pragma omp for reduction(+: pi) schedule(dynamic, threads)
      for(i=1;i<UINT_MAX;i++) { 
        x = (i - .5) * dx;
        pi = pi + 1./(1+x*x);     
      } 
      #pragma omp barrier
      #pragma omp sections
      { 
        pi *= 4.*dx;
      } 
    } 
 
  } 

  return pi;
}

