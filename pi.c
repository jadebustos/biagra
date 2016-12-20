#include <stdlib.h>
#include <limits.h>
#include <omp.h>
#include <gmp.h>
#include <string.h>

#include <biagra/numintegr.h>

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
/* This function is used to compute pi used the midpoint rule.          */
/*                                                                      */

long double pifunc(double x) {
  return (1./(1. + (x*x)));
}

/*                                                                      */
/* Function to get a pi approximation using the mid-point rule.         */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads -> Number of threads to be used                        */
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

/*                                                                      */
/* Function to get a pi approximation using the Chudnovsky algorithm.   */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads  -> Number of threads to be used                       */
/*    intPiDigits -> Number of pi digits to be computed                 */
/*                                                                      */

void chudnovskyPi(int intThreads, int intPiDigits) {

  /* bits per decimal digit, log2(10) */
  double bits_digit = 3.3219280948873626; 
	    
  unsigned long int i              = 0,
                    iters          = 0,
                    triplei        = 0,
                    decimals       = 1000, 
                    precision_bits = (intPiDigits * bits_digit) + 1;

  char *pistr,        /* to store pi as a string */
       *end_decimals;

  FILE *data;

  mpf_t pi,  /* pi aproximation */
  num; /* numerator */

  mpf_set_default_prec(precision_bits); /* default precision in bits */

  /* allocation and initialitation, mpf_inits does not work on RHEL 6.x due to gmp version */
  mpf_init(pi);
  mpf_init(num);

  /* pi */
  mpf_set_ui(pi, 0);

  /* numerator */
  mpf_sqrt_ui(num, 10005);
  mpf_mul_ui(num, num, 426880);

  iters = (decimals/DIGITS_ITERATION) + 1;

}

