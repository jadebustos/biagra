#include <math.h>
#include <stdlib.h>
#include <string.h>

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

/*
   The following are deliberately forbidden:
     - Attempt World domination
     - Using this software as compiling massive weapon
     - Translating into Klingon
     - Ask for /home nationalisms
     - Reverse spelling of this source code
*/

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

/*                                                                      */
/* Function to get the general form of a polynomial from its roots      */
/*                                                                      */
/* Arguments:                                                           */
/*                                                                      */
/*    *dblRoots -> real polynomial roots (intNumber dimension)          */
/*    intNumber -> number of roots                                      */
/*    *ptPol    -> biaRealPol data structure to store the polynomial    */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int polGeneralForm(double *dblRoots, int intNumber, biaRealPol *ptPol) {

  /* auxiliary structures */
  biaRealPol auxPol1, /* to store (x - ai) polynomial, where ai is a root */
	     auxPol2; 

  int i;

  /* memory allocation for ptPol */
  ptPol->dblCoefs = (double *)dblPtMemAllocVec(intNumber + 1);
  if ( ptPol->dblCoefs == NULL ) {
    return BIA_MEM_ALLOC;
  }

  ptPol->dblRoots = (double *)dblPtMemAllocVec(intNumber);
  if ( ptPol->dblCoefs == NULL  ) {
    free(ptPol->dblCoefs);
    return BIA_MEM_ALLOC;
  }

  /* populating data on ptPol */
  memcpy(ptPol->dblRoots, dblRoots, intNumber * sizeof(double));

  /* first initializations */
  ptPol->dblCoefs[0] = -dblRoots[0];
  ptPol->dblCoefs[1] = 1.;
  ptPol->intDegree = 1;

  /* only one root */
  if ( intNumber == 1 ) {
    return BIA_TRUE;
  }

  /* memory allocation for auxiliar structures */
  auxPol1.dblCoefs = (double *)dblPtMemAllocVec(2);
  if ( auxPol1.dblCoefs == NULL ) {
    return BIA_MEM_ALLOC;
  }
  auxPol1.intDegree = 1;
  auxPol1.dblCoefs[1] = 1.;

  auxPol2.dblCoefs = (double *)dblPtMemAllocVec(intNumber + 1);
  if ( auxPol2.dblCoefs == NULL ) {
    free(auxPol1.dblCoefs);
    free(ptPol->dblCoefs);
    free(ptPol->dblRoots);
    return BIA_MEM_ALLOC;
  }

  /* p(x) = (x - a0) * (x - a2) * ... * (x - an) */
  /* p(x) = (x - a0) * q(x) where q(x) = (x - a1) * ... * (x - an) */
  for(i=1;i<intNumber;i++) {
    auxPol1.dblCoefs[0] = -dblRoots[i]; /* (x - ai) */ 
    
    multiplyPol(&auxPol1, ptPol, &auxPol2);
    memcpy(ptPol->dblCoefs, auxPol2.dblCoefs, (auxPol2.intDegree + 1) * sizeof(double));

    ptPol->intDegree = auxPol2.intDegree;
  }

  /* freeing memory from auxiliary structures */
  free(auxPol1.dblCoefs);
  free(auxPol2.dblCoefs);

  return BIA_TRUE;
}
