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
/*                                                                      */

  void chudnovskyPi(int intThreads, int intPiDigits);

#endif
