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
/* Function to memory allocation for an array of int    elements.       */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

int *intPtMemAllocVec(int intElements) {

  int *intPt;

  /* memory allocation */

  intPt = (int *)calloc(intElements, sizeof(int));

  return intPt;

}

/*                                                                      */
/* Function to memory allocation for an array of double elements.       */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

double *dblPtMemAllocVec(int intElements) {

  double *dblPt;

  /* memory allocation */

  dblPt = (double *)calloc(intElements, sizeof(double));

  return dblPt;
}

/*                                                                      */
/* Function to memory allocation for a bidimensiaonal array of          */
/* double elements                                                      */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

double **dblPtMemAllocMat(int intRows, int intCols) {
  int i;

  double **dblPt;

  /* memory allocation */

  dblPt = (double **)calloc(intRows, sizeof(double *) );

  /* end if error */

  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intRows;i++) {
      dblPt[i] = (double *)calloc(intCols, sizeof(double));
      if ( dblPt[i] == NULL ) {
      /* if error, free memory and exit */
        while ( i-- > 0 )
          free(dblPt[i]);
        free(dblPt);
        dblPt = NULL;
         break;
      }
    }
  }
  return dblPt;
}

/*                                                                      */
/* Function to memory allocation for an upper triangular matrix         */
/* of double elements and intOrder order.                               */
/*                                                                      */
/* First row: intOrder elements                                         */
/* Second row: intOrder - 1 elements                                    */
/* ...                                                                  */
/* intOrder row: one element                                            */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

double **dblPtMemAllocUpperTrMat(int intOrder) {

  int i,
      intAux = intOrder;

  double **dblPt;

  dblPt = (double **)calloc(intOrder, sizeof(double *));

  /* end if error */

  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intOrder;i++) {
      dblPt[i] = (double *)calloc(intAux--, sizeof(double) );
      if ( dblPt[i] == NULL ) {
        /* if error, free memory and exit */
        while ( i-- > 0 )
          free(dblPt[i]);   
        free(dblPt);
        dblPt = NULL;
        break;
        }
      }
   }
  return dblPt;
}


/*                                                                      */
/* Function to memory allocation for a lower triangular matrix          */
/* of double elements and intOrder order.                               */
/*                                                                      */
/* First row: one element                                               */
/* Second row: two elements                                             */
/* ...                                                                  */
/* intOrder row: intOrder elements                                      */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

double **dblPtMemAllocLowerTrMat(int intOrder) {
  int i;

  double **dblPt;

  dblPt = (double **)calloc(intOrder, sizeof(double *) );

  /* end if error */

  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intOrder;i++) {
      dblPt[i] = (double *)calloc(i+1, sizeof(double) );
      if ( dblPt[i] == NULL ) {
        /* if error, free memory and exit */
        while ( i-- > 0 )
          free(dblPt[i]); 
        free(dblPt);
        dblPt = NULL;
        break;
        }
     }
  }
  return dblPt;
}

/*                                                                      */
/* Function to free memory from a double pointer matrix.                */
/*                                                                      */

void freeMemDblMat(double **dblMatrix, int intRows) {
  int  i;

  for(i=0;i<intRows;i++)
    free(dblMatrix[i]);
        
  free(dblMatrix);

  return;        
}

