#ifndef _PI_H
  #define _PI_H

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

/* decimal digits per iteration that Chudnovsky algorithm generates in each iteration */
#define DIGITS_ITERATION 14.1816474627254776555

/*                                                                      */
/* Function to get a pi approximation using the mid-point rule.         */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads    -> Number of threads to be used                     */
/*    intIterations -> Iterations used to compute pi                    */                                                                          
/*                                                                      */
/* Pi approximation is returned as long double.                         */
/*                                                                      */

  long double threadedPiMidPointRule(int intThreads, int intIterations);

/*                                                                      */
/* Function to get a pi approximation using the Chudnovsky algorithm.   */
/*                                                                      */
/* Arguments:                                                           */
/*    intThreads  -> Number of threads to be used                       */
/*    intPiDigits -> Number of pi digits to be computed                 */
/*    ptPi        -> Char pointer to store pi                           */
/*                                                                      */

  int chudnovskyPi(int intThreads, int intPiDigits, char *ptPi);

#endif
