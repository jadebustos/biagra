#ifndef _COMPLEX_H
  #define _COMPLEX_H

#include <biagra/const.h>                                                                                                                             

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
/* Data structure to store complex numbers                              */
/*                                                                      */
/* a + b * i                                                            */
/*                                                                      */
/* dblReal -> Real part                                                 */
/* dblImag -> Imaginary part                                            */ 
/*                                                                      */

  typedef struct {

    double dblReal,
           dblImag;

  } biaComplex;

/*                                                                      */
/* Data structure to store complex numbers as polar coordinates         */
/*                                                                      */
/* a + b * i = (r, theta)                                               */
/*                                                                      */
/* dblMod -> Modulus                                                    */
/* dblArg -> Argument                                                   */
/*                                                                      */

  typedef struct {
  
    double dblMod,
           dblArg;
        
  } biaPolar;

/*                                                                      */
/* Function to add two complex numbers                                  */
/*                                                                      */

  void addComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);

/*                                                                      */
/* Function to subtract two complex numbers                             */
/*                                                                      */

  void subtractComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);


/*                                                                      */
/* Function to multiply two complex numbers                             */
/*                                                                      */

  void multiplyComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);

/*                                                                      */
/* Function to complex division                                         */
/*                                                                      */
/*        ptCmplx1 * (ptCmplx2)^(-1)                                    */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV -> Division by zero                                */
/*      BIA_TRUE     -> Success                                         */
/*                                                                      */

  int divideComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes);


/*                                                                      */
/* Function to get a complex number module                              */
/*                                                                      */

  double dblComplexModulus(biaComplex *ptCmplx);

/*                                                                      */
/* Function to get a complex number argument                            */
/*                                                                      */

  double dblComplexArg(biaComplex *ptCmplx);

/*                                                                      */
/* Function to get the inverse (addition) of a complex number           */
/*                                                                      */

  void invSumComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the inverse (multiplication) of a complex number     */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV -> Division by zero                                */
/*      BIA_TRUE     -> Success                                         */
/*                                                                      */

  int invMulComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the complex conjugate of a complex number            */
/*                                                                      */

  void conjugateComplex(biaComplex *ptCmplx, biaComplex *ptRes);

/*                                                                      */
/* Function to get the polar coordinates of a complex number            */
/*                                                                      */

  void complex2Polar(biaComplex *ptCmplx, biaPolar *ptRes);

/*                                                                      */
/* Function to get the cartesian coordinates of a complex number        */
/* in polar coordinates                                                 */
/*                                                                      */

  void polar2Complex(biaPolar *ptPolar, biaComplex *ptRes);

#endif
