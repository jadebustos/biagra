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
   	  dbliPrevPoint, 	/* previous point */
          dblX,
          dblY,
          *dblK;		/* vector to store the k_i */       

  /* step-size as a positive number, just in case */
  (ptData->dblStepSize) = fabs((ptData->dblStepSize));
     
  /* memory reservation */        
  dblK = (double *)calloc(ptData->strCoefs.intStages, sizeof(double));

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
    free(ptData->strCoefs.dblC)

  if ( ptData->strCoefs.dblB != NULL )
    free(ptData->strCoefs.dblB)

  if ( ptData->strCoefs.dblMatrix != NULL ) {
	freeMemDblMat(ptData->strCoefs.dblMatrix, ptData->strCoefs.intStages);
  }

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
	return (BIAM_MEM_ALLOC);
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
/* Funcion que inicializa los coeficientes del metodo de HEUN,          */
/* metodo RUNGE-KUTTA de tres etapas, la funcion asigna memoria a los   */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int MetodoHeun(biaDataRK *ptData)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "HEUN" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 3;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);
	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./4.;
ptstrDatos->strCoefi.dblB[1] = .0;
ptstrDatos->strCoefi.dblB[2] = 3./4.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./3.;
ptstrDatos->strCoefi.dblC[2] = 2./3.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./3.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

ptstrDatos->strCoefi.dblMatriz[2][0] = .0;
ptstrDatos->strCoefi.dblMatriz[2][1] = 2./3.;
ptstrDatos->strCoefi.dblMatriz[2][2] = .0;

return (TRUE);
}

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de KUTTA,         */
/* metodo RUNGE-KUTTA de tres etapas, la funcion asigna memoria a los   */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     ->  Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM ->  Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int MetodoKutta(biaDataRK *ptData)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "KUTTA" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 3;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./6.;
ptstrDatos->strCoefi.dblB[1] = 2./3.;
ptstrDatos->strCoefi.dblB[2] = 1./6.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./2.;
ptstrDatos->strCoefi.dblC[2] = 1.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

ptstrDatos->strCoefi.dblMatriz[2][0] = -1.;
ptstrDatos->strCoefi.dblMatriz[2][1] = 2.;
ptstrDatos->strCoefi.dblMatriz[2][2] = .0;

return (TRUE);
}

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de EULER          */
/* MODIFICADO, metodo RUNGE-KUTTA de dos etapas, la funcion asigna      */
/* memoria a los punteros de la estructura DatosRK, por lo que es       */
/* necesario que no esten dimensionados cuando se le pase como          */
/* parametro la variable de estructura a la funcion.                    */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     ->  Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM ->  Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int EulerModificado(biaDataRK *ptData)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "EULER MODIFICADO" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 2;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);

	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = .0;
ptstrDatos->strCoefi.dblB[1] = 1.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1./2.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1./2.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

return (TRUE);
}

/*                                                                      */
/* Funcion que inicializa los coeficientes del metodo de EULER MEJORADO */
/* metodo RUNGE-KUTTA de dos etapas, la funcion asigna memoria a los    */
/* punteros de la estructura DatosRK, por lo que es necesario que no    */
/* esten dimensionados cuando se le pase como parametro la variable de  */
/* estructura a la funcion.                                             */
/*                                                                      */
/* La funcion devuelve los siguientes codigos:				*/
/*									*/
/*	TRUE     -> Se inicializaron con exito los coeficientes.	*/
/*      ERR_AMEM -> Hubo un error en la asignacion de memoria.		*/
/*                                                                      */

int EulerMejorado(biaDataRK *ptData)

{
/* FUNCION QUE INICIALIZA LOS COEFICIENTES PARA UTILIZAR EL METODO
   DE "EULER MEJORADO" PARA LA RESOLUCION NUMERICA DE E.D.O's */

int 	intEtapas = 2;	/* NUMERO DE ETAPAS DEL METODO */

/* RESERVA DE MEMORIA */

ptstrDatos->strCoefi.dblC = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblC == NULL )
	{
	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblB = (double *)dblPtAsigMemVec(intEtapas);

if ( ptstrDatos->strCoefi.dblB == NULL )
	{
	free(ptstrDatos->strCoefi.dblC);

	return (ERR_AMEM);	/* FIN */
	}

ptstrDatos->strCoefi.dblMatriz = (double **)dblPtAsigMemMatTrInf(intEtapas);

if ( ptstrDatos->strCoefi.dblMatriz == NULL )
	{
	free(ptstrDatos->strCoefi.dblB);
	free(ptstrDatos->strCoefi.dblC);
	FreeMemDblMat(ptstrDatos->strCoefi.dblMatriz, intEtapas);

	return(ERR_AMEM);	/* FIN */
	}

/* NUMERO DE ETAPAS DEL METODO */

ptstrDatos->strCoefi.intEtapas = intEtapas;

/* ESTE METODO ES UN METODO EXPLICITO */

ptstrDatos->intImplicito = FALSE;

/* COEFICIENTES b[i] */

ptstrDatos->strCoefi.dblB[0] = 1./2.;
ptstrDatos->strCoefi.dblB[1] = 1./2.;

/* COEFICIENTES c[i] */

ptstrDatos->strCoefi.dblC[0] = .0;
ptstrDatos->strCoefi.dblC[1] = 1.;

/* COEFICIENTES a[i][j] */

ptstrDatos->strCoefi.dblMatriz[0][0] = .0;

ptstrDatos->strCoefi.dblMatriz[1][0] = 1.;
ptstrDatos->strCoefi.dblMatriz[1][1] = .0;

return (TRUE);
}
