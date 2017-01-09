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

/* Simple example of invSumComplex usage */

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

  /* get opposite complex */
  invSumComplex(&myCmplx1, &myRes);

  /* print to stdout */
  printf("z = %g + %g * i\n", myCmplx1.dblReal, myCmplx1.dblImag);
  printf("-z = %g + %g * i\n", myRes.dblReal, myRes.dblImag);
  addComplex(&myCmplx1, &myRes, &myCmplx2);
  printf("z + (-z) = %g + %g * i\n", myCmplx2.dblReal, myCmplx2.dblImag);
  
  return BIA_TRUE;
	
}
