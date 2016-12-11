#ifndef _ROOTS_H                                                                                                                                      
  #define _ROOTS_H

#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/*                                                                      */
/* Data structure to store function roots                               */
/*                                                                      */
/* intMNI   -> maximum number of iterations to get the root with        */
/*             dblTol error.                                            */
/* intIte   -> iterations used to get the root.                         */
/* dblx0    -> initial root approximation.                              */
/* dblRoot  -> function root approximation                              */
/* dblTol   -> Maximun error tolerance.                                 */
/* dblError -> error in root. Difference between two last root          */
/*             approximations.                                          */
/*                                                                      */
        
typedef struct {

  int intMNI,
      intIte;

  double dblx0,
         dblRoot,
         dblTol,
         dblError;

} biaRealRoot;

/*                                                                      */
/* Function to get a root approximation using the Newton method.        */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*         BIA_FALSE    -> root could not be computed                   */
/*                  condiciones dadas(NMI y Tolerancia).                */
/*         BIA_ZERO_DIV -> division by zero                             */
/*         BIA_TRUE  ->   root could be computed                        */
/*                                                                      */
/* Two additional functions are needed:                                 */
/*                                                                      */
/*    func, function to get the root                                    */
/*    der, above's function derivative                                  */  
/*                                                                      */
/* C prototype of both functions are the same:                          */
/*                                                                      */
/*    int function_name(double dblx0, double *ptRes)                    */
/*                                                                      */
/* where:                                                               */
/*                                                                      */
/*    dblx0 point in which function is going to be evaluated            */
/*    *ptRes pointer to the variable where the function's value         */
/*           at dblx0 is going to be stored                             */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*         BIA_ZERO_DIV -> Division by zero                             */
/*         BIA_TRUE     -> Success                                      */
/*                                                                      */

int newtonMethod(biaRealRoot *ptRoot, 
	int (*func)(double dblx0, double *ptRes),
	int (*der)(double dblx0, double *ptRes));

#endif
