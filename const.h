#ifndef _CONST_H
  #define _CONST_H

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

  #ifdef BIA_E
    #undef  BIA_E
    #define BIA_E 2.71828182845904523536029
  #else
    #define BIA_E 2.71828182845904523536029
  #endif

  #ifdef BIA_PI
    #undef  BIA_PI
    #define BIA_PI 3.14159265358979323846264
  #else
    #define BIA_PI 3.14159265358979323846264
  #endif

/*                                                                      */
/*                  DIVISION BY ZERO                                    */
/*                                                                      */

  #ifdef BIA_ZERO_DIV
    #undef  BIA_ZERO_DIV
    #define BIA_ZERO_DIV 2
  #else
    #define BIA_ZERO_DIV 2
  #endif

/*                                                                      */
/*             MEMORY ALLOCATION ERROR                                  */
/*                                                                      */

  #ifdef BIA_MEM_ALLOC
    #undef  BIA_MEM_ALLOC
    #define BIA_MEM_ALLOC 1
  #else
    #define BIA_MEM_ALLOC 1
  #endif

/*                                                                      */
/*                      FALSE                                           */
/*                                                                      */

  #ifdef BIA_FALSE
    #undef  BIA_FALSE
    #define BIA_FALSE -1
  #else
    #define BIA_FALSE -1
  #endif

/*                                                                      */
/*                  TRUE                                                */
/*                                                                      */

  #ifdef BIA_TRUE
    #undef  BIA_TRUE
    #define BIA_TRUE 0
  #else
    #define BIA_TRUE 0
  #endif

#endif
