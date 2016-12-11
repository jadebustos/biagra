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

/* Simple example of complex2Polar usage */

int main (void) {

  /* complex number */
  biaComplex myCmplx;

  /* polar coordinates */
  biaPolar myPolar;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myCmplx.dblReal = dblRandom(10);
  myCmplx.dblImag = dblRandom(10);

  /* get polar coordinates */
  complex2Polar(&myCmplx, &myPolar);

  /* print to stdout */
  printf("z = %g + %g * i\n", myCmplx.dblReal, myCmplx.dblImag);
  printf("Mod: %g - Arg:  %g\n", myPolar.dblMod, myPolar.dblArg);
  
  return BIA_TRUE;
	
}
