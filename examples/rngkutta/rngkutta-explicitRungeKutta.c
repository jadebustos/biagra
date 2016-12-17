#include <stdio.h>
#include <math.h>

#include <biagra/rngkutta.h>
#include <biagra/resmem.h>
#include <biagra/const.h>

/*                                                                      */
/*      B.I.A.G.R.A.    (c) 1998 Jose Angel de Bustos Perez             */
/*                       <jadebustos@gmail.com>                         */
/*                                                                      */
/*      This software is licensed under GPLv2:                          */
/*        http://www.gnu.org/licenses/gpl-2.0.html                      */
/*                                                                      */
/*      BIbliotecA de proGRamacion cientificA.                          */
/*                                                                      */

/* Simple example of explicit Runge Kutta methods */

/* y'= y(x) * (x - y(x))/x^2, y(1) = 2 */
double IVP(double dblX, double dblY) {
  return dblY*((dblX - dblY)/(dblX*dblX));
}

/* y(x) */

double y(double dblX) {
  return dblX/(.5 + log(dblX));
}

int main (void) {

  /* IVP  */
  double IVP(double dblX, double dblY);

  /* y(x) */
  double y(double dblX);

  int i;

  /* Runge Kutta data */
  biaDataRK myData;

  /* Data initialization */
  myData.strCoefs.dblC = NULL;
  myData.strCoefs.dblB = NULL;
  myData.strCoefs.dblMatrix = NULL;

  /* Classic Runge Kutta, Butcher Array */
  if ( classicRungeKuttaCoefs(&myData) ) {
    printf("Memory error initializating the Butcher Array for the Classic Runge Kutta method.\n");
    return BIA_FALSE;
  }

  /* step size */
  myData.dblStepSize = .1;

  /* number of points to get the approx */
  myData.intNumApprox = intNodeNumber(1., myData.dblStepSize);

  myData.dblPoints = dblPtMemAllocVec(myData.intNumApprox);
  if ( myData.dblPoints == NULL ) {
    printf("Memory error initializating dblPoints.\n");
    return BIA_FALSE;
  }

  /* y(1) = 2 */
  myData.dblPoints[0] = 2.;
  myData.dblFirst = 1.;

  /* Classic Runge Kutta approximation */
  i = explicitRungeKutta(&myData, &IVP);

  if ( i != BIA_TRUE ) {
    printf("Memory error solving the IVP.\n");
    return BIA_FALSE;
  }
 
  printf("--------------------------------------------------\n");
  printf("Explicit classic Runge Kutta approximation example\n");
  printf("--------------------------------------------------\n");
  printf("             x - y(x)\n");
  printf("y' = y(x) * ----------\n");
  printf("                x^2\n");
  printf("\ny(1) = 2\n\n");
  printf("xi: %lf\t(Point where the approximation was computed)\n", myData.dblLast);
  printf("yi: %lf\t(Approximation computed by the classic Runge Kutta)\n", myData.dblPoints[myData.intNumApprox - 1]);
  printf("y(%lf): %lf\t(Real value)\n", myData.dblLast, y(myData.dblLast));
  printf("|yi - y(xi)|: %g\t(Error between the real value and the computed approximation)\n", fabs(myData.dblPoints[myData.intNumApprox - 1] - y(myData.dblLast)));

  return BIA_TRUE;
}
