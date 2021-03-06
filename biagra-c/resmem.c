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

/*
   The following are deliberately forbidden:
     - Attempt World domination
     - Using this software as compiling massive weapon
     - Translating into Klingon
     - Ask for /home nationalisms
     - Reverse spelling of this source code
*/

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
/* Function to memory allocation for a bidimensional array of           */
/* integer elements                                                     */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

int **intPtMemAllocMat(int intRows, int intCols) {
  int i;

  int **intPt;

  /* memory allocation */
  intPt = (int **)calloc(intRows, sizeof(int *) );

  /* end when error */
  if ( intPt == NULL  )
    return intPt;
  else {
    for(i=0;i<intRows;i++) {
      intPt[i] = (int *)calloc(intCols, sizeof(int));
      if ( intPt[i] == NULL  ) {
        /* when error, free memory and exit */
        while ( i-- > 0  )
          free(intPt[i]);
        free(intPt);
        intPt = NULL;
        break;
      }
    }
  }
  return intPt;
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

  /* end when error */

  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intRows;i++) {
      dblPt[i] = (double *)calloc(intCols, sizeof(double));
      if ( dblPt[i] == NULL ) {
      /* when error, free memory and exit */
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
/* of integer elements and intOrder order.                              */
/*                                                                      */
/* First row: intOrder elements                                         */
/* Second row: intOrder - 1 elements                                    */
/* ...                                                                  */
/* intOrder row: one element                                            */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

int **intPtMemAllocUpperTrMat(int intOrder) {
  int i,
      intAux = intOrder;

  int **intPt;

  intPt = (int **)calloc(intOrder, sizeof(int *));

  /* end when error */

  if ( intPt == NULL  )
    return intPt;
  else {
    for(i=0;i<intOrder;i++) {
      intPt[i] = (int *)calloc(intAux--, sizeof(int) );
      if ( intPt[i] == NULL  ) {
        /* when error, free memory and exit */                                                                                                        
        while ( i-- > 0  )
          free(intPt[i]);   
        free(intPt);
        intPt = NULL;
        break;
      }
    }
  }
  return intPt;
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

  /* end when error */

  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intOrder;i++) {
      dblPt[i] = (double *)calloc(intAux--, sizeof(double) );
      if ( dblPt[i] == NULL ) {
        /* when error, free memory and exit */
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
/* of integer elements and intOrder order.                              */
/*                                                                      */
/* First row: one element                                               */
/* Second row: two elements                                             */
/* ...                                                                  */
/* intOrder row: intOrder elements                                      */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

int **intPtMemAllocLowerTrMat(int intOrder) {
  int i;

  int **intPt;

  intPt = (int **)calloc(intOrder, sizeof(int *) );

  /* end when error */
  if ( intPt == NULL  )
    return intPt;
  else {
    for(i=0;i<intOrder;i++) {
      intPt[i] = (int *)calloc(i+1, sizeof(int) );
      if ( intPt[i] == NULL  ) {
        /* when error, free memory and exit */
        while ( i-- > 0  )
          free(intPt[i]); 
	free(intPt);
	intPt = NULL;
	break;
      }
    }
  }
  return intPt;
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

  /* end when error */
  if ( dblPt == NULL )
    return dblPt;
  else {
    for(i=0;i<intOrder;i++) {
      dblPt[i] = (double *)calloc(i+1, sizeof(double) );
      if ( dblPt[i] == NULL ) {
        /* when error, free memory and exit */
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


/*                                                                      */
/* Function to free memory from a int pointer matrix.                   */
/*                                                                      */

void freeMemIntMat(int **intMatrix, int intRows) {
  int  i;

  for(i=0;i<intRows;i++)
    free(intMatrix[i]);
        
  free(intMatrix);

  return;        

}
