#include <stdio.h>
#include <stdlib.h>

#include <biagra/const.h>
#include <biagra/pi.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 2013 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of chudnovskyPi usage */

int main (void) {

  int intThreads = 4,
      intDigits = 1000;

  char *pi = (char *)calloc(intDigits + 3, sizeof(char));

  if ( pi == NULL ) {
    printf("Memory error allocation.\n");
    exit (1);
  }

  printf("Using %d threads to compute PI (%d digits).\n", intThreads, intDigits);

  chudnovskyPi(intThreads, intDigits, pi);

  printf("Pi: %s\n", pi);

  return BIA_TRUE;
}
