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

/* Simple example of polar2Complex usage */

int main (void) {

  /* complex number */
  biaComplex myCmplx;

  /* polar coordinates */
  biaPolar myPolar;

  /* random initializaiton */
  srand((unsigned)time(NULL));

  /* initialization */
  myPolar.dblMod = dblRandom(10);
  myPolar.dblArg = dblRandom(3);

  /* get polar coordinates */
  polar2Complex(&myPolar, &myCmplx);

  /* print to stdout */
  printf("Mod: %g - Arg: %g\n", myPolar.dblMod, myPolar.dblArg);
  printf("z = %g + %g * i\n", myCmplx.dblReal, myCmplx.dblImag);
  
  return BIA_TRUE;
	
}
