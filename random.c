#include <time.h>
#include <stdlib.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Function to get a unsigned random integer from -(limit -1) to        */
/* limit -1                                                             */
/*                                                                      */

int intRandom(int limit) {

  int tmp;

  tmp = (int)(limit*1.*rand()/(RAND_MAX+1.0));

  if ( (int)(2.*rand()/(RAND_MAX+1.0)) == 1 )
    tmp *= -1;

  return tmp;
}

/*                                                                      */
/* Function to get a random integer from 0 to limit -1                  */
/*                                                                      */

int uintRandom(int limit) {

  int tmp;

  tmp = (int)(limit*1.*rand()/(RAND_MAX+1.0));

  return tmp;
}

/*                                                                      */
/* Function to get an unsigned random double from 0 to                  */
/* limit -1                                                             */
/*                                                                      */

 double udblRandom(int limit) {

  double tmp;

  tmp = (limit*1.*rand()/(RAND_MAX+1.0));

  return tmp;
}

/*                                                                      */
/* Function to get a random double from -(limit - 1) to                 */
/* limit - 1                                                            */
/*                                                                      */

 double dblRandom(int limit) {

  double tmp;

  tmp = (limit*1.*rand()/(RAND_MAX+1.0));

  if ( (int)(2.*rand()/(RAND_MAX+1.0)) == 1 )
    tmp *= -1;

  return tmp;
}
