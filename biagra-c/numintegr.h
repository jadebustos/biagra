#ifndef _NUMINTEGR_H
  #define _NUMINTEGR_H

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

  long double threadedMidPointRule(int intThreads, int intN, double a, double b, long double (*func)(double x));

#endif
