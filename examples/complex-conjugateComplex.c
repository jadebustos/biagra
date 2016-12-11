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

/* Simple example of conjugateComplex usage */

int main (void) {

  /* complex numbers */
  biaComplex myCmplx,
             myRes;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myCmplx.dblReal = dblRandom(10);
  myCmplx.dblImag = dblRandom(10);

  /* conjugate */
  conjugateComplex(&myCmplx, &myRes);

  /* print to stdout */
  printf("z = %g + %g * i\n", myCmplx.dblReal, myCmplx.dblImag);
  printf("Conjugate(z) = %g + %g * i\n", myRes.dblReal, myRes.dblImag);
  
  return BIA_TRUE;
	
}
