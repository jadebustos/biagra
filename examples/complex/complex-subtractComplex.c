#include <stdio.h>
#include <stdlib.h>

#include <biagra/complex.h>
#include <biagra/random.h>
#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of subtractComplex usage */

int main (void) {

  /* complex numbers */
  biaComplex myCmplx1,
             myCmplx2,
             myRes;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myCmplx1.dblReal = dblRandom(10);
  myCmplx1.dblImag = dblRandom(10);
  myCmplx2.dblReal = dblRandom(10);
  myCmplx2.dblImag = dblRandom(10);

  /* subtraction */
  subtractComplex(&myCmplx1, &myCmplx2, &myRes);

  /* print to stdout */
  printf("z1 = %g + %g * i\n", myCmplx1.dblReal, myCmplx1.dblImag);
  printf("z2 = %g + %g * i\n", myCmplx2.dblReal, myCmplx2.dblImag);
  printf("z1 - z2 = %g + %g * i\n", myRes.dblReal, myRes.dblImag);
  
  return BIA_TRUE;
	
}
