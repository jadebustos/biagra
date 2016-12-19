#include <stdlib.h>
#include <limits.h>
#include <omp.h>

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

/*
   The following are deliberately forbidden:
     - Attempt World domination
     - Using this software as compiling massive weapon
     - Translating into Klingon
     - Ask for /home nationalisms
     - Reverse spelling of this source code
*/

/*                                                                      */
/* This function is used to compute pi used the midpoint rule.          */
/*                                                                      */

long double pifunc(double x) {
  return (1./(1. + (x*x)));
}

/*                                                                      */
/* Function to get a pi approximation using the mid-point rule.         */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads -> Number of threads used                              */
/*    intN       -> Number of used subintervals                         */                                                                          
/*                                                                      */
/* Pi approximation is returned as long double.                         */
/*                                                                      */

long double threadedPiMidPointRule(int intThreads, int intN) {

  long double pifunc(double x);
  
  long double pi;

  pi = threadedMidPointRule(intThreads, intN, .0, 1., &pifunc);

  return pi;
}
