#ifndef _RESMEM_H
  #define _RESMEM_H

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

  int *intPtMemAllocVec(int intElements);

/*                                                                      */
/* Function to memory allocation for an array of double elements.       */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

  double *dblPtMemAllocVec(int intElements);

/*                                                                      */
/* Function to memory allocation for a bidimensional array of           */
/* double elements                                                      */
/*                                                                      */
/* Pointer to the first element is returned.                            */
/*                                                                      */

  double **dblPtMemAllocMat(int intRows, int intCols);

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

  double **dblPtMemAllocUpperTrMat(int intOrder);

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

  double **dblPtMemAllocLowerTrMat(int intOrder);

/*                                                                      */
/* Function to free memory from a double pointer matrix.                */
/*                                                                      */

  void freeMemDblMat(double **dblMatrix, int intRows);
#endif
