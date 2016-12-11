#include <math.h>
#include <stdlib.h>

#include <biagra/polynomial.h>
#include <biagra/roots.h>
#include <biagra/const.h>
#include <biagra/resmem.h>

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
/* Function to evaluate a polynomial in one value.                      */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrPol -> Polynomial                                           */
/*    dblX      -> Value to evaluate                                    */                                                                            
/*                                                                      */
/* Returned value:                                                      */
/*                                                                      */
/*    Polynomial value at dblX                                          */

double dblEvaluatePol(biaRealPol *ptPol, double dblX) {

  double dblRes = .0;

  int  i = 0,
       intDegreeAbs = abs(ptPol->intDegree);

  if ( dblX == .0 )
    return (ptPol->dblCoefs[0]);

  switch (intDegreeAbs) {
    case 0: {
      break;
    }
    default: {
      dblRes = dblX*(ptPol->dblCoefs[intDegreeAbs]);
      for(i=intDegreeAbs-1;i>=1;i--) {
        dblRes += (ptPol->dblCoefs[i]);
        dblRes *= dblX;
      }
      break;
    }
  }

  dblRes += ptPol->dblCoefs[0];

  return (dblRes);
}

/*                                                                      */
/* Function to get the n-th derivative                                  */
/*                                                                      */ 
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int derivativePol(biaRealPol *ptPol, biaRealPol *ptDer, int intN) {

  int intAbsN = abs(intN),
      i,
      j;

  if ( intAbsN >= (ptPol->intDegree) )
    (ptDer->intDegree) = 0;
  else
    (ptDer->intDegree) = ((ptPol->intDegree)-intAbsN);

  if ( (ptDer->dblCoefs) != NULL )
    free(ptDer->dblCoefs);

  (ptDer->dblCoefs) = (double *)dblPtMemAllocVec((ptDer->intDegree)+1);

  if ( (ptDer->dblCoefs) == NULL )
    return BIA_MEM_ALLOC;

  for(i=0;i<=(ptDer->intDegree);i++) {
    (ptDer->dblCoefs[i]) = (ptPol->dblCoefs[i+intAbsN]);
    for(j=i+intAbsN;j>i;j--)
      (ptDer->dblCoefs[i]) *= j;
  }

return (BIA_TRUE);
}

/*                                                                      */
/* Function to add polynomials:                                         */
/*     ptRes = ptPlo1 + ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int addPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes) {

  int i;

  /* degree of the polynomial addition */
  (ptRes->intDegree) = ((ptPol1->intDegree) >= (ptPol2->intDegree)) ? 
			(ptPol1->intDegree) : (ptPol2->intDegree);

  if ( (ptRes->dblCoefs) != NULL )
    free (ptRes->dblCoefs);

  (ptRes->dblCoefs) = (double *)dblPtMemAllocVec((ptRes->intDegree)+1);

  if ( (ptRes->dblCoefs) == NULL )
    return BIA_MEM_ALLOC;

  for(i=0;i<=(ptPol1->intDegree);i++)
    (ptRes->dblCoefs[i]) += (ptPol1->dblCoefs[i]);

  for(i=0;i<=(ptPol2->intDegree);i++)
    (ptRes->dblCoefs[i]) += (ptPol2->dblCoefs[i]);

  return BIA_TRUE; 
}

/*                                                                      */
/* Function to subtract polynomials:                                    */
/*     ptRes = ptPol1 - ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int subtractPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes) {
	
  int i;

  /* degree of the polynomial addition */
  (ptRes->intDegree) = ((ptPol1->intDegree) >= (ptPol2->intDegree)) ? 
			(ptPol1->intDegree) : (ptPol2->intDegree);

  if ( (ptRes->dblCoefs) != NULL )
    free (ptRes->dblCoefs);

  (ptRes->dblCoefs) = (double *)dblPtMemAllocVec((ptRes->intDegree)+1);

  if ( (ptRes->dblCoefs) == NULL )
    return BIA_MEM_ALLOC; 

  for(i=0;i<=(ptPol1->intDegree);i++)
    (ptRes->dblCoefs[i]) += (ptPol1->dblCoefs[i]);

  for(i=0;i<=(ptPol2->intDegree);i++)
    (ptRes->dblCoefs[i]) -= (ptPol2->dblCoefs[i]);

  return BIA_TRUE;
}          

/*                                                                      */
/* Function to multiply polynomials:                                    */
/*     ptRes = ptPol1 * ptPol2                                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int multiplyPol(biaRealPol *ptPol1, biaRealPol *ptPol2, biaRealPol *ptRes) {

  int i,
      j;

  /* degree of the polynomial addition */
  (ptRes->intDegree) = (ptPol1->intDegree) + (ptPol2->intDegree);

  if ( (ptRes->dblCoefs) != NULL )
    free((ptRes->dblCoefs));

  (ptRes->dblCoefs) = (double *)dblPtMemAllocVec((ptRes->intDegree)+1);

  if ( (ptRes->dblCoefs) == NULL )
    return BIA_MEM_ALLOC;

  for(i=0;i<=(ptPol1->intDegree);i++) {
    for(j=0;j<=(ptPol2->intDegree);j++) {
      (ptRes->dblCoefs[i+j]) += (ptPol1->dblCoefs[i]) * 
        (ptPol2->dblCoefs[j]);
      }
    }
  return BIA_TRUE;
}

/*                                                                      */
/* Function to find a polynomial root using Newton's method             */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_ZERO_DIV  -> Division by zero                               */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_FALSE     -> Fail                                           */
/*                                                                      */

int newtonPol(biaRealPol *ptPol, biaRealRoot *ptRoot) {

  int i,
      intDegreeAbs = abs(ptPol->intDegree),
      intMNIAbs    = abs(ptRoot->intMNI);

  double dblApprxNew = .0,
	 dblApprxOld = (ptRoot->dblx0),
	 dblPolValue = .0,
	 dblDerValue = .0,
	 dblTolAbs   = fabs(ptRoot->dblTol);

  biaRealPol biaPolDer;

  biaPolDer.intDegree = intDegreeAbs;
  biaPolDer.dblCoefs = NULL;

  /* get derivative */
  i = derivativePol(ptPol, &biaPolDer, 1);

  if ( i != BIA_TRUE ) {
    return BIA_MEM_ALLOC;
    }

  for(i=1;i<=intMNIAbs;i++) {
    dblPolValue = dblEvaluatePol(ptPol, dblApprxOld);
    dblDerValue = dblEvaluatePol(&biaPolDer, dblApprxOld);

    if ( dblDerValue == .0 ) {
      free(biaPolDer.dblCoefs);
      ptRoot->intIte = i;
      return BIA_ZERO_DIV;
      }

    /* new approximation */
    dblApprxNew = dblApprxOld - (dblPolValue/dblDerValue);

    /* error */
    ptRoot->dblError = fabs(dblApprxOld-dblApprxNew);
    if ( (ptRoot->dblError) < dblTolAbs ) {
      free(biaPolDer.dblCoefs);
      ptRoot->dblRoot = dblApprxNew;
      ptRoot->intIte = i;
      return BIA_TRUE;
      }
    dblApprxOld = dblApprxNew;
    }
  ptRoot->intIte = i;
  return BIA_FALSE;
}
