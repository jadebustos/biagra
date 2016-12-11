#include <math.h>

#include <biagra/complex.h>
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
/* Function to add two complex numbers                                  */
/*                                                                      */

void addComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes) {

  ptRes->dblReal = ptCmplx1->dblReal + ptCmplx2->dblReal;
  ptRes->dblImag = ptCmplx1->dblImag + ptCmplx2->dblImag;

  return;
}

/*                                                                      */
/* Function to subtract two complex numbers                             */
/*                                                                      */

void subtractComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes) {

  ptRes->dblReal = ptCmplx1->dblReal - ptCmplx2->dblReal;
  ptRes->dblImag = ptCmplx1->dblImag - ptCmplx2->dblImag;

  return;
}

/*                                                                      */
/* Function to multiply two complex numbers                             */
/*                                                                      */

void multiplyComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes) {

  ptRes->dblReal = ((ptCmplx1->dblReal)*(ptCmplx2->dblReal)) - 
                   ((ptCmplx1->dblImag)*(ptCmplx2->dblImag));
  ptRes->dblImag = ((ptCmplx1->dblImag)*(ptCmplx2->dblReal)) + 
                  ((ptCmplx1->dblReal)*(ptCmplx2->dblImag));

  return;
}

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

int divideComplex(biaComplex *ptCmplx1, biaComplex *ptCmplx2, biaComplex *ptRes) {

  double dblDenominator;

  if ( ptCmplx1->dblReal == 0. && ptCmplx2->dblImag == 0. )
    return BIA_ZERO_DIV;
  else {        
    dblDenominator = ((ptCmplx2->dblReal)*(ptCmplx2->dblReal)) +
                     ((ptCmplx2->dblImag)*(ptCmplx2->dblImag));

   ptRes->dblReal = (((ptCmplx1->dblReal)*(ptCmplx2->dblReal)) +
                    ((ptCmplx1->dblImag)*(ptCmplx2->dblImag)))/dblDenominator;

   ptRes->dblImag = (((ptCmplx1->dblImag)*(ptCmplx2->dblReal)) - 
                    ((ptCmplx1->dblReal)*(ptCmplx2->dblImag)))/dblDenominator;
  }

  return BIA_TRUE;
}

/*                                                                      */
/* Function to get a complex number module                              */
/*                                                                      */

double dblComplexModulus(biaComplex *ptCmplx) {

  double  dbltmp1,
          dbltmp2;
        
  dbltmp1 = (ptCmplx->dblReal)*(ptCmplx->dblReal);
  dbltmp2 = (ptCmplx->dblImag)*(ptCmplx->dblImag);

  return (sqrt(dbltmp1 + dbltmp2));
}

/*                                                                      */
/* Function to get a complex number argument                            */
/*                                                                      */

double dblComplexArg(biaComplex *ptCmplx) {

  double  dblRes;

  if ( ptCmplx->dblReal == 0. ) {
    if ( ptCmplx->dblImag >= 0. )
      dblRes = BIA_PI/2.;
    else
      dblRes = (3./2.)*BIA_PI;
  }

  /* first quadrant */

  else if ( (ptCmplx->dblReal) > 0. && (ptCmplx->dblImag) >= 0. )
    dblRes = atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* second quadrant */

  else if ( (ptCmplx->dblReal) < 0. && (ptCmplx->dblImag) >= 0. )
    dblRes = BIA_PI - atan((-1.)*(ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* third quadrant */

  else if ( (ptCmplx->dblReal) < 0. && (ptCmplx->dblImag) < 0. )
    dblRes = BIA_PI + atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* fourth quadrant */

  else
    dblRes = ((2.)*BIA_PI) - atan((-1.)*(ptCmplx->dblImag)/(ptCmplx->dblReal));

  return (dblRes);
}

/*                                                                      */
/* Function to get the inverse (addition) of a complex number           */
/*                                                                      */

void invSumComplex(biaComplex *ptCmplx, biaComplex *ptRes) {

  ptRes->dblReal = (-1.)*(ptCmplx->dblReal);
  ptRes->dblImag = (-1.)*(ptCmplx->dblImag);

  return;
}

/*                                                                      */
/* Function to get the inverse (multiplication) of a complex number     */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV -> Division by zero                                */
/*      BIA_TRUE     -> Success                                         */
/*                                                                      */

int invMulComplex(biaComplex *ptCmplx, biaComplex *ptRes) {

  double dblDenominator;

  if ( ptCmplx->dblReal == 0. && ptCmplx->dblImag == 0. )
    return BIA_ZERO_DIV;
  else {        
   dblDenominator = ((ptCmplx->dblReal)*(ptCmplx->dblReal)) +
                    ((ptCmplx->dblImag)*(ptCmplx->dblImag));

   ptRes->dblReal = (ptCmplx->dblReal)/dblDenominator;
   ptRes->dblImag = ((-1.)*(ptCmplx->dblImag))/dblDenominator;
   }

  return BIA_TRUE;
}

/*                                                                      */
/* Function to get the complex conjugate of a complex number            */
/*                                                                      */

void conjugateComplex(biaComplex *ptCmplx, biaComplex *ptRes) {

  ptRes->dblReal = ptCmplx->dblReal;
  ptRes->dblImag = (-1.)*(ptCmplx->dblImag);

  return;
}

/*                                                                      */
/* Function to get the polar coordinates of a complex number            */
/*                                                                      */

void complex2Polar(biaComplex *ptCmplx, biaPolar *ptRes) {

  double dbltmp;

  dbltmp = ((ptCmplx->dblReal)*(ptCmplx->dblReal)) +
           ((ptCmplx->dblImag)*(ptCmplx->dblImag));

  ptRes->dblMod = sqrt(dbltmp);

  if ( ptCmplx->dblReal == 0. ) {
    if ( ptCmplx->dblImag >= 0. )
      ptRes->dblArg = BIA_PI/2.;
    else
      ptRes->dblArg = (3./2.)*BIA_PI;
  }

  /* first quadrant */

  else if ( (ptCmplx->dblReal) > 0. && (ptCmplx->dblImag) >= 0. )
    ptRes->dblArg = atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* second quadrant */

  else if ( (ptCmplx->dblReal) < 0. && (ptCmplx->dblImag) >= 0. )
    ptRes->dblArg = BIA_PI + atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* third quadrant */

  else if ( (ptCmplx->dblReal) < 0. && (ptCmplx->dblImag) < 0. )
    ptRes->dblArg = BIA_PI + atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  /* fourth quadrant */

  else
    ptRes->dblArg = ((2.)*BIA_PI) + atan((ptCmplx->dblImag)/(ptCmplx->dblReal));

  return;
}

/*                                                                      */
/* Function to get the cartesian coordinates of a complex number        */
/* in polar coordinates                                                 */
/*                                                                      */

void polar2Complex(biaPolar *ptPolar, biaComplex *ptRes) {

  ptRes->dblReal = (ptPolar->dblMod)*cos((ptPolar->dblArg));
  ptRes->dblImag = (ptPolar->dblMod)*sin((ptPolar->dblArg));

  return;
}
