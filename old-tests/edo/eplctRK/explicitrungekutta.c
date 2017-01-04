#include <stdio.h>
#include <math.h>

#include <struct.h>
#include <resmem.h>
#include <edo.h>
#include <rngkutta.h>

/* PROGRAMA PARA APROXIMAR UNA ECUACION DIFERENCIAL */

int main(void)

{
/* VARIABLE DE ESTRUCTURA QUE CONTENDRA LOS DATOS DEL RUNGE - KUTTA */

DatosRK strDatosRunge;

double	dblLong = .0, /* LONGITUD DEL INTERVALO EN EL QUE ESTAMOS TRABAJANDO */
	dblPunto = .0,
	dblRes = .0;

int	intRes = 0;

/* FUNCION QUE REPRESENTA EL P.V.I. */

double PVI(double dblX, double dblY);

/* FUNCION QUE REPRESENTA LA SOLUCION DEL P.V.I */

double solucion(double dblX);

/* INICIALIZACION DE LOS COEFICIENTES */

intRes = RungeKuttaClasico(&strDatosRunge);

if ( intRes != 0 )
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}

/* PETICION DEL PASO */

printf("Introduce el paso del metodo: ");
scanf("%lf", &(strDatosRunge.dblPaso));

/* PUNTO INICIAL DE CALCULO */

printf("Introduce el punto donde comenzaran los calculos: ");
scanf("%lf", &(strDatosRunge.dblInicio));

/* PUNTO FINAL DE CALCULO */

printf("Introduce el punto final de calculo: ");
scanf("%lf", &(strDatosRunge.dblFinal));

/* CALCULO DEL NUMERO DE APROXIMACIONES */

dblLong = (strDatosRunge.dblFinal) - (strDatosRunge.dblInicio);

strDatosRunge.intNumAprox = intNumNodos(dblLong, strDatosRunge.dblPaso);

/* RESERVA DE MEMORIA PARA ALMACENAR LAS APROXIMACIONES */

strDatosRunge.dblPuntos = dblPtAsigMemVec(strDatosRunge.intNumAprox);

if ( (strDatosRunge.dblPuntos) == NULL  )
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
   	return (-1);	/* FIN */
	}

/* PETICION DE LA INICIALIZACION */

printf("Introduce el valor de la E.D.O en el punto inicial: ");
scanf("%lf", &(strDatosRunge.dblPuntos[0]));

/* RESOLUCION NUMERICA DEL PROBLEMA */

intRes = ExplicitRungeKutta(&strDatosRunge, &PVI);

printf("El valor devuelto es %d\n", intRes);

dblPunto = (strDatosRunge.dblInicio)+
((strDatosRunge.dblPaso)*((strDatosRunge.intNumAprox)-1));

printf("El resultado en %lf es %.16lf\n", dblPunto,
   strDatosRunge.dblPuntos[(strDatosRunge.intNumAprox) - 1]);

dblRes = fabs(solucion(dblPunto)-
	(strDatosRunge.dblPuntos[(strDatosRunge.intNumAprox)-1]));

printf("\nEl error cometido es: %e\n", dblRes);

return (0);	
}

double PVI(double dblX, double dblY)

{
double	dblRes = .0;

dblRes = (dblX-dblY)*(dblY/(dblX*dblX));

return (dblRes);
}

double solucion(double dblX)

{
double dblRes = .0;

dblRes = dblX/((.5)+log(dblX));

return(dblRes);
}
