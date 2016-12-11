#ifndef _RANDOM_H
  #define _RANDOM_H

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
/* Function to get a random unsigned integer from 0 to                  */
/* limit -1                                                             */
/*                                                                      */

int uintRandom(int limit);

/*                                                                      */
/* Function to get a unsigned random integer from -(limit -1) to        */                                                                            
/* limit -1                                                             */
/*                                                                      */

 int intRandom(int limit);

/*                                                                      */
/* Function to get a random double from -(limit - 1) to                 */
/* limit - 1                                                            */
/*                                                                      */

 double dblRandom(int limit);

/*                                                                      */
/* Function to get a random double from 0 to limit - 1                  */
/*                                                                      */

 double udblRandom(int limit);

#endif
