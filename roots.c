#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <biagra/roots.h>
#include <biagra/const.h>

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
/*         BIA_ZERO_DIV -> Division by zero                             */
/*         BIA_TRUE     -> Success                                      */
/*                                                                      */

int newtonMethod(biaRealRoot *ptRoot, 
       int (*func)(double dblx0, double *ptRes),
       int (*der)(double dblx0, double *ptRes)) {

  int  intRes = BIA_TRUE,
       intMNIAbs = abs(ptRoot->intMNI);

  double dblApprxNew   = .0,
	 dblApprxOld   = (ptRoot->dblx0),
	 dblFuncVal    = .0,
	 dblDerVal     = .0,
	 dblTolAbs     = fabs(ptRoot->dblTol);

  for(ptRoot->intIte=1;ptRoot->intIte<=intMNIAbs;(ptRoot->intIte)++) {
    intRes = (*func)(dblApprxOld, &dblFuncVal);

    if ( intRes == BIA_ZERO_DIV )
      return BIA_ZERO_DIV;

    intRes = (*der)(dblApprxOld, &dblDerVal);

    if ( intRes == BIA_ZERO_DIV )
      return BIA_ZERO_DIV;

    if ( dblDerVal == .0 )
      return BIA_ZERO_DIV;

    /* new root approximation */
    dblApprxNew = dblApprxOld - (dblFuncVal/dblDerVal);

    /* error */
    ptRoot->dblError = fabs(dblApprxOld-dblApprxNew);

    if ( (ptRoot->dblError) < dblTolAbs ) {
      ptRoot->dblRoot = dblApprxNew;
      return BIA_TRUE;
    }
    dblApprxOld = dblApprxNew;
  }
  return BIA_FALSE;
}
