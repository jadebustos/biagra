#include <stdlib.h>
#include <limits.h>
#include <omp.h>

#include <stdio.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*
   The following are deliberately forbidden:
     - Attempt World domination
     - Using this software as compiling massive weapon
     - Translating into Klingon
     - Ask for /home nationalisms
     - Reverse spelling of this source code
*/

/*                                                                      */
/* Function to get a numerical approximation for a functions' integral  */
/* between a and b.                                                     */ 
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads -> Number of threads used                              */
/*    intN       -> Number of used rectangles                           */                                                                          
/*    (a, b)     -> Interval to compute the integral                    */
/*    (*func)    -> Pointer to a integral's function                    */
/*                                                                      */
/* A approximation is returned as long double.                          */
/*                                                                      */

long double threadedMidPointRule(int intThreads, int intN, double a, double b, long double (*func)(double x)) {

  int i = 0;

  long double xi = .0,
              dx = (long double)((b - a)/intN),
              approx = .0;

    #pragma omp parallel num_threads(intThreads) private(xi)
    { 
      #pragma omp for reduction(+: approx) schedule(dynamic, intThreads)
      for(i=0;i<intN;i++) {
	xi = .5*((a + i*dx) + (a + (i+1)*dx));
        approx = approx + func(xi);     
      } 
      #pragma omp barrier
      #pragma omp sections
      { 
        approx *= dx;
      } 
    } 

  return approx;
}

