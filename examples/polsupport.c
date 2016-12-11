#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <biagra/polynomial.h>
#include <biagra/resmem.h>
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

/* generate random polynomial */

int randomPol(biaRealPol *ptPol) {

  /* Memory reservation */
  ptPol->dblCoefs = (double *)dblPtMemAllocVec((ptPol->intDegree)+ 1);

  if ( ptPol->dblCoefs == NULL ) {
    return BIA_MEM_ALLOC;
  }

  /* Random coefs between 0 and 10 (not cryptographically secure) */
  srand(time(NULL));
  for(int i=0;i<=ptPol->intDegree;i++) {
      ptPol->dblCoefs[i] = (double) (rand() % 10);
      if ( (rand() % 2 ) == 0 )
        ptPol->dblCoefs[i] *= -1; 
  }

  return BIA_TRUE;
}

/* print polynomial to stdout */
void pol2Stdout(biaRealPol *ptPol) {
  
  int i;

  /* Printing polynomial to stdout */
  printf("%g", ptPol->dblCoefs[0]);

  for(i=1;i<=ptPol->intDegree;i++)
    printf(" + (%g) * x ^%d", ptPol->dblCoefs[i], i);

  printf("\n");

  return;
}
