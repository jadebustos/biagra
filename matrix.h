#ifndef _MATRIX_H
  #define _MATRIX_H

/*                                                                      */
/* Data structure to store matrices                                     */
/*                                                                      */
/*      intRows  -> Number of rows                                      */
/*      intCols  -> Number of columns                                   */
/*      dblCoefs -> Matrix coeficients                                  */
/*                                                                      */

typedef struct {
  int intRows,
       intCols;

  double **dblCoefs;
} biaMatrix;        

/*                                                                      */
/* Function to store identity matrix.                                   */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

  void identityMatrix(biaMatrix *ptMatrix);

/*                                                                      */
/* Function to store scaling matrix with factor dblFactor.              */
/*                                                                      */
/* Matrix order it taken from intRows member of biaMatrix var           */
/*                                                                      */

  void scalingMatrix(biaMatrix *ptMatrix, double dblFactor);

/*                                                                      */
/* Function to store the null matrix.                                   */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

  void nullMatrix(biaMatrix *ptMatrix);

/*                                                                      */
/* Function to get the transpose matrix of the given matrix.            */
/*                                                                      */
/* Rows and columns are takem from intRows and intCols members of       */
/* biaMatrix var.                                                       */
/*                                                                      */

  void transposeMatrix(biaMatrix *ptMatrix, biaMatrix  *ptRes);

 /*                                                                      */
 /* Function to check if a given matrix is the identity matrix           */
 /*                                                                      */
 /* The following values are returned:                                   */
 /*                                                                      */
 /*      BIA_FALSE -> Not identity matrix                                */
 /*      BIA_TRUE  -> Identity matrix                                    */
 /*                                                                      */

  int isIdentityMatrix(biaMatrix *ptMatrix);

/*                                                                      */
/* Function to check if a matrix is a null matrix.                      */
/* dblTol is the tolerance used to check if an elemement is null.       */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not null matrix                                    */
/*      BIA_TRUE  -> Null matrix                                        */
/*                                                                      */

  int isNullMatrix(biaMatrix *ptMatrix, double dblTol);

/*                                                                      */
/* Function to check if a matrix is symmetric.                          */
/*                                                                      */
/* The following values are returned:                                   */
/*                                                                      */
/*      BIA_FALSE -> Not symmetric                                      */
/*      BIA_TRUE  -> Symmetric                                          */
/*                                                                      */

  int isSymmetricMatrix(biaMatrix *ptMatrix); 
#endif
