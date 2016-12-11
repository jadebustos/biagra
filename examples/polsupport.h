#ifndef _POLSUPPORT_H
  #define _POLSUPPORT_H

#include <biagra/polynomial.h>

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
  int randomPol(biaRealPol *ptPol);

  /* print polynomial to stdout */
  void pol2Stdout(biaRealPol *ptPol);
#endif
