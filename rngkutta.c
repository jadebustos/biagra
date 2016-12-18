#include <stdlib.h>
#include <math.h>

#include <biagra/rngkutta.h>
#include <biagra/const.h>
#include <biagra/resmem.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                           <jadebustos@gmail.com>                     */
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
/*  Function to solve a I.V.P (Cauchy problem) using explicit           */
/*  Runge-Kutta methods.                                                */
/*                                                                      */
/* Arguments:                                                           */
/*    *ptstrDatos -> Pointer to a DataRK data structure                 */
/*    (*IVP)      -> Pointer to a function implementing de differential */
/*                   equation in (dblX, dblY)                           */
/*                                                                      */
/*  The following values are returned:                                  */
/*                                                                      */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*      BIA_TRUE      -> Success                                        */
/*                                                                      */

int explicitRungeKutta(biaDataRK *ptData, double (*IVP)(double dblX, double dblY) ) {

  int i,
      j,
      k;
        
  double  dblCurrentPoint,	/* point where the approximation is being calculated */
   	  dblPrevPoint, 	/* previous point */
          dblX,
          dblY,
          *dblK;		/* vector to store the k_i */       

  /* step-size as a positive number, just in case */
  (ptData->dblStepSize) = fabs((ptData->dblStepSize));
     
  /* memory reservation */        
  dblK = dblPtMemAllocVec(ptData->strCoefs.intStages);

  if ( dblK == NULL ) {
    return (BIA_MEM_ALLOC);
  }

  /* initializations */
  dblCurrentPoint = (ptData->dblFirst) + (ptData->dblStepSize);
  dblPrevPoint = (ptData->dblFirst);

  for(i=1;i<(ptData->intNumApprox);i++) {
      
   /* k_i */
   for(k = 0;k < (ptData->strCoefs.intStages);k++) {
     dblX = dblPrevPoint + ( (ptData->dblStepSize)*(ptData->strCoefs.dblC[k]) );
     dblY = .0;
   
     for(j = 0;j < k;j++)
       dblY += (dblK[j])*(ptData->strCoefs.dblMatrix[k][j]);   
   
     dblY *= (ptData->dblStepSize);
     dblY += (ptData->dblPoints[i-1]);
   
     dblK[k] = (*IVP)(dblX, dblY);
   }
      
   /* approximation */
       
   (ptData->dblPoints[i]) = .0;

   for(j=0;j<(ptData->strCoefs.intStages);j++)
     (ptData->dblPoints[i]) += dblK[j] * (ptData->strCoefs.dblB[j]);
      
   (ptData->dblPoints[i]) *= (ptData->dblStepSize);
   (ptData->dblPoints[i]) += (ptData->dblPoints[i-1]);
   
   dblPrevPoint = dblCurrentPoint;   
   dblCurrentPoint += (ptData->dblStepSize);
   
   }

  /* Last point */
  ptData->dblLast = dblPrevPoint;

  /* freing memory */
  free (dblK);   

  return (BIA_TRUE);   
}

/*                                                                      */
/* Function to get the number of nodes in a dblLong size interval where */
/* dblStepSize is the distance between two consecutive nodes.           */
/*									*/

int intNodeNumber(double dblLong, double dblStepSize) {
  int  intRes = 1;

  intRes += (int)ceil(fabs(dblLong)/fabs(dblStepSize));

  return (intRes);
}

/*                                                                      */
/* Function to initialize classic Runge-Kutta coefficients.             */
/* Four-stage method.                                                   */
/*                                                                      */
/* Following values are returned:                                       */
/*                                                                      */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*                                                                      */

int classicRungeKuttaCoefs(biaDataRK *ptData) {

  ptData->strCoefs.intStages = 4; /* method stages */

  ptData->intImplicit = BIA_IMPLICIT_RK_FALSE; /* explicit method */

  /* free pointers if necessary */
  if ( ptData->strCoefs.dblC != NULL )
    free(ptData->strCoefs.dblC);

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB);

  if ( ptData->strCoefs.dblMatrix != NULL )
    freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);

  /* memory reservation */

  ptData->strCoefs.dblC = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblC == NULL )
	return (BIA_MEM_ALLOC);

  ptData->strCoefs.dblB = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblB == NULL ) {
	free(ptData->strCoefs.dblC);
	return (BIA_MEM_ALLOC);
	}

  ptData->strCoefs.dblMatrix = (double **)dblPtMemAllocLowerTrMat(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblMatrix == NULL ) {
	free(ptData->strCoefs.dblB);
	free(ptData->strCoefs.dblC);
	freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
	return (BIA_MEM_ALLOC);
	}

  /* b[i] coefs */
  ptData->strCoefs.dblB[0] = ptData->strCoefs.dblB[3] = 1./6.;
  ptData->strCoefs.dblB[1] = ptData->strCoefs.dblB[2] = 1./3.;

  /* c[i] coefs */
  ptData->strCoefs.dblC[0] = .0;
  ptData->strCoefs.dblC[1] = ptData->strCoefs.dblC[2] = 1./2.;
  ptData->strCoefs.dblC[3] = 1.;

  /* a[i][j] coefs */
  ptData->strCoefs.dblMatrix[0][0] = .0;

  ptData->strCoefs.dblMatrix[1][0] = 1./2.;
  ptData->strCoefs.dblMatrix[1][1] = .0;

  ptData->strCoefs.dblMatrix[2][0] = .0;
  ptData->strCoefs.dblMatrix[2][1] = 1./2.;
  ptData->strCoefs.dblMatrix[2][2] = .0;

  ptData->strCoefs.dblMatrix[3][0] = .0;
  ptData->strCoefs.dblMatrix[3][1] = .0;
  ptData->strCoefs.dblMatrix[3][2] = 1.;
  ptData->strCoefs.dblMatrix[3][3] = .0;

  return (BIA_TRUE);
}


/*                                                                      */
/* Function to initialize Heun Runge-Kutta coefficients.                */
/* Three-stage method.                                                  */
/*                                                                      */
/* Following values are returned:                                       */
/*                                                                      */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*                                                                      */

int heunRungeKuttaCoefs(biaDataRK *ptData) {

  ptData->strCoefs.intStages = 3; /* method stages */

  ptData->intImplicit = BIA_IMPLICIT_RK_FALSE; /* explicit method */

  /* free pointers if necessary */
  if ( ptData->strCoefs.dblC != NULL )
    free(ptData->strCoefs.dblC);

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB);

  if ( ptData->strCoefs.dblMatrix != NULL )
    freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);

  /* memory reservation */
  ptData->strCoefs.dblC = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblC == NULL )
    return (BIA_MEM_ALLOC);

  ptData->strCoefs.dblB = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblB == NULL ) {
	free(ptData->strCoefs.dblC);
	return (BIA_MEM_ALLOC);
	}

  ptData->strCoefs.dblMatrix = (double **)dblPtMemAllocLowerTrMat(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblMatrix == NULL ) {
	free(ptData->strCoefs.dblB);
	free(ptData->strCoefs.dblC);
	freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
	return (BIA_MEM_ALLOC);
	}

  /* b[i] coefs */
  ptData->strCoefs.dblB[0] = 1./4.;
  ptData->strCoefs.dblB[1] = .0;
  ptData->strCoefs.dblB[2] = 3./4.;

  /* c[i] coefs */
  ptData->strCoefs.dblC[0] = .0;
  ptData->strCoefs.dblC[1] = 1./3.;
  ptData->strCoefs.dblC[2] = 2./3.;

  /* a[i][j] coefs */
  ptData->strCoefs.dblMatrix[0][0] = .0;

  ptData->strCoefs.dblMatrix[1][0] = 1./3.;
  ptData->strCoefs.dblMatrix[1][1] = .0;

  ptData->strCoefs.dblMatrix[2][0] = .0;
  ptData->strCoefs.dblMatrix[2][1] = 2./3.;
  ptData->strCoefs.dblMatrix[2][2] = .0;

  return (BIA_TRUE);
}

/*                                                                      */
/* Function to initialize Kutta Runge-Kutta coefficients.               */
/* Three-stage method.                                                  */
/*                                                                      */
/* Following values are returned:                                       */
/*                                                                      */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*                                                                      */

int kuttaRungeKuttaCoefs(biaDataRK *ptData) {

  ptData->strCoefs.intStages = 3; /* method stages */

  ptData->intImplicit = BIA_IMPLICIT_RK_FALSE; /* explicit method */

  /* free pointers if necessary */
  if ( ptData->strCoefs.dblC != NULL )
    free(ptData->strCoefs.dblC);

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB);

  if ( ptData->strCoefs.dblMatrix != NULL )
    freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);

  /* memory reservation */
  ptData->strCoefs.dblC = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblC == NULL )
    return (BIA_MEM_ALLOC);

  ptData->strCoefs.dblB = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblB == NULL ) {
        free(ptData->strCoefs.dblC);
        return (BIA_MEM_ALLOC);
        }

  ptData->strCoefs.dblMatrix = (double **)dblPtMemAllocLowerTrMat(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblMatrix == NULL ) {
        free(ptData->strCoefs.dblB);
        free(ptData->strCoefs.dblC);
        freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
        return (BIA_MEM_ALLOC);
        }

  /* b[i] coefs */
  ptData->strCoefs.dblB[0] = 1./6.;
  ptData->strCoefs.dblB[1] = 2./3.;
  ptData->strCoefs.dblB[2] = 1./6.;

  /* c[i] coefs */
  ptData->strCoefs.dblC[0] = .0;
  ptData->strCoefs.dblC[1] = 1./2.;
  ptData->strCoefs.dblC[2] = 1.;

  /* a[i][j] coefs */
  ptData->strCoefs.dblMatrix[0][0] = .0;

  ptData->strCoefs.dblMatrix[1][0] = 1./2.;
  ptData->strCoefs.dblMatrix[1][1] = .0;

  ptData->strCoefs.dblMatrix[2][0] = -1.;
  ptData->strCoefs.dblMatrix[2][1] = 2.;
  ptData->strCoefs.dblMatrix[2][2] = .0;

  return (BIA_TRUE);
}

/*                                                                      */
/* Function to initialize Modified Euler Runge-Kutta coefficients.      */
/* Two-stage method.                                                    */
/*                                                                      */
/* Following values are returned:                                       */
/*                                                                      */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*                                                                      */

int modifiedEulerRungeKuttaCoefs(biaDataRK *ptData) {

  ptData->strCoefs.intStages = 2; /* method stages */

  ptData->intImplicit = BIA_IMPLICIT_RK_FALSE; /* explicit method */

  /* free pointers if necessary */
  if ( ptData->strCoefs.dblC != NULL )
    free(ptData->strCoefs.dblC);

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB);

  if ( ptData->strCoefs.dblMatrix != NULL )
    freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);

  /* memory reservation */
  ptData->strCoefs.dblC = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblC == NULL )
    return (BIA_MEM_ALLOC);

  ptData->strCoefs.dblB = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblB == NULL ) {
        free(ptData->strCoefs.dblC);
        return (BIA_MEM_ALLOC);
        }

  ptData->strCoefs.dblMatrix = (double **)dblPtMemAllocLowerTrMat(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblMatrix == NULL ) {
        free(ptData->strCoefs.dblB);
        free(ptData->strCoefs.dblC);
        freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
        return (BIA_MEM_ALLOC);
        }

  /* b[i] coefs */
  ptData->strCoefs.dblB[0] = .0;
  ptData->strCoefs.dblB[1] = 1.;

  /* c[i] coefs */
  ptData->strCoefs.dblC[0] = .0;
  ptData->strCoefs.dblC[1] = 1./2.;

  /* a[i][j] coefs */
  ptData->strCoefs.dblMatrix[0][0] = .0;

  ptData->strCoefs.dblMatrix[1][0] = 1./2.;
  ptData->strCoefs.dblMatrix[1][1] = .0;

  return (BIA_TRUE);
}

/*                                                                      */
/* Function to initialize Improved Euler Runge-Kutta coefficients.      */
/* Two-stage method.                                                    */
/*                                                                      */
/* Following values are returned:                                       */
/*                                                                      */
/*      BIA_TRUE      -> Success                                        */
/*      BIA_MEM_ALLOC -> Memory allocation error                        */
/*                                                                      */

int improvedEulerRungeKuttaCoefs(biaDataRK *ptData) {

  ptData->strCoefs.intStages = 2; /* method stages */

  ptData->intImplicit = BIA_IMPLICIT_RK_FALSE; /* explicit method */

  /* free pointers if necessary */
  if ( ptData->strCoefs.dblC != NULL )
    free(ptData->strCoefs.dblC);

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB);

  if ( ptData->strCoefs.dblMatrix != NULL )
    freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);

  /* memory reservation */
  ptData->strCoefs.dblC = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblC == NULL )
    return (BIA_MEM_ALLOC);

  ptData->strCoefs.dblB = (double *)dblPtMemAllocVec(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblB == NULL ) {
        free(ptData->strCoefs.dblC);
        return (BIA_MEM_ALLOC);
        }

  ptData->strCoefs.dblMatrix = (double **)dblPtMemAllocLowerTrMat(ptData->strCoefs.intStages);
  if ( ptData->strCoefs.dblMatrix == NULL ) {
        free(ptData->strCoefs.dblB);
        free(ptData->strCoefs.dblC);
        freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
        return (BIA_MEM_ALLOC);
        }

  /* b[i] coefs */
  ptData->strCoefs.dblB[0] = 1./2.;
  ptData->strCoefs.dblB[1] = 1./2.;

  /* c[i] coefs */
  ptData->strCoefs.dblC[0] = .0;
  ptData->strCoefs.dblC[1] = 1.;

  /* a[i][j] coefs */
  ptData->strCoefs.dblMatrix[0][0] = .0;

  ptData->strCoefs.dblMatrix[1][0] = 1.;
  ptData->strCoefs.dblMatrix[1][1] = .0;

  return (BIA_TRUE);
}
