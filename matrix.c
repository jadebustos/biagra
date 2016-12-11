#include <math.h>

#include <biagra/matrix.h>
#include <biagra/const.h>

/*                                                                      */
/* Function to store identity matrix.                                   */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

void identityMatrix(biaMatrix *ptMatrix) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i == j ) {
        (ptMatrix->dblCoefs[i][i]) = 1.;
      }
      else {
        (ptMatrix->dblCoefs[i][j]) = .0;
      }
    }
  }
  return;
}

/*                                                                      */
/* Function to store scaling matrix with factor dblFactor.              */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

void scalingMatrix(biaMatrix *ptMatrix, double dblFactor) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i == j )
        (ptMatrix->dblCoefs[i][i]) = dblFactor;
      else
        (ptMatrix->dblCoefs[i][j]) = .0;
    }
  }

  return;
}

/*                                                                      */                                                                            
/* Function to store the null matrix.                                   */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

void nullMatrix(biaMatrix *ptMatrix) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intCols);j++) {
      (ptMatrix->dblCoefs[i][j]) = .0;
    }
  }
  return;
}

/*                                                                      */
/* Function to get the transpose matrix of the given matrix.            */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

void transposeMatrix(biaMatrix *ptMatrix, biaMatrix  *ptRes) {

  int i,
      j;

  for(i=0;i<(ptMatrix->intCols);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      (ptRes->dblCoefs[i][j]) = (ptMatrix->dblCoefs[j][i]);
    }
  }

return;
}

/*                                                                      */
/* Function to check if a given matrix is the identity matrix           */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not identity matrix                                */
/*      BIA_TRUE  -> Identity matrix                                    */                                                                           
/*                                                                      */

int isIdentityMatrix(biaMatrix *ptMatrix) {

  int i,
      j,
      intRes = BIA_TRUE;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i != j ) {
        if ( (ptMatrix->dblCoefs[i][j]) != .0 ) {
          intRes = BIA_FALSE;
          break;
        }
      }
      else {
        if ( (ptMatrix->dblCoefs[i][i]) != 1. ) {
          intRes = BIA_FALSE;
          break;
        }
      }
    }
    if ( intRes == BIA_FALSE )
      break;
  }
  return intRes; 
}

/*                                                                      */
/* Function to check if a matrix is a null matrix.                      */
/* dblTol is the tolerance used to check if an elemement is null.       */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not null matrix                                    */
/*      BIA_TRUE  -> Null matrix                                        */
/*                                                                      */

int isNullMatrix(biaMatrix *ptMatrix, double dblTol) {

  int i,
      j,
      intRes = BIA_TRUE;

  double dblTolPos = fabs(dblTol);

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intCols);j++) {
      if ( fabs((ptMatrix->dblCoefs[i][j])) > dblTolPos ) {
        intRes = BIA_FALSE;
        return intRes;
      }
    }
  }
  return intRes;
}

/*                                                                      */
/* Function to check if a matrix is symmetric.                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not symmetric                                      */
/*      BIA_TRUE  -> Symmetric                                          */
/*                                                                      */

int isSymmetricMatrix(biaMatrix *ptMatrix) {

  int i,
      j,
      intRes = BIA_TRUE;

  for(i=0;i<(ptMatrix->intRows);i++) {
    for(j=0;j<(ptMatrix->intRows);j++) {
      if ( i != j  ) {
        if ( (ptMatrix->dblCoefs[i][j]) != .0 ) {
          intRes = BIA_FALSE;
          break; 
        }
      }
      else {
        if ( (ptMatrix->dblCoefs[i][i]) != 1. ) {
          intRes = BIA_FALSE;
          break; 
        }
      }
    }
    if ( intRes == BIA_FALSE  )
      break; 
  }
  return intRes; 
}  
