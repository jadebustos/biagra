#ifndef _POLYNOMIAL_H
  #define _POLYNOMIAL_H

#include <biagra/roots.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Data structure to handle polynomials                                 */
/*                                                                      */
/* p(x) = a0 + a1*x^1 + a2*x^2 + .... + an*x^n                          */                                                                            
/*                                                                      */
/* intDegree    -> Polynomial degree                                    */
/* intRealRoots -> Number of real roots                                 */
/* intCompRoots -> Number of complex roots                              */
/* dblCoefs     -> Polynomial coefs                                     */
/*                   dblCoefs[i] = ai                                   */
/*                                                                      */

typedef struct {

  int intDegree,
      intRealRoots,
      intCompRoots;

  double *dblCoefs;        
} biaRealPol;

/*                                                                      */
/* Function to evaluate a polynomial in one value.                      */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrPol -> Polynomial                                           */
/*    dblX      -> Value to evaluate                                    */
/*                                                                      */
/* Returned value:                                                      */
/*                                                                      */
/*    Polynomial value at dblX                                          */

  double dblEvaluatePol(biaRealPol *ptPol, double dblX);

/*                                                                      */
/* Function to get the n-th derivative                                  */
/*                                                                      */ 
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

  int derivativePol(biaRealPol *ptPol, biaRealPol *ptDer, int intN);

/*                                                                      */
/* Function to add polynomials:                                         */
/*     ptRes = ptPlo1 + ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

  int addPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes);

/*                                                                      */
/* Function to subtract polynomials:                                    */
/*     ptRes = ptPol1 - ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

  int subtractPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes);

/*                                                                      */
/* Function to multiply polynomials:                                    */
/*     ptRes = ptPol1 * ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

  int multiplyPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes);

/*                                                                      */
/* Function to find a polynomial root using Newton's method             */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV  -> Division by zero                               */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_FALSE     -> Fail                                           */
/*                                                                      */

  int newtonPol(biaRealPol *ptPol, biaRealRoot *ptRoot);

#endif
