#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "resmem.h"
#include "polinomios.h"

int main(void)

{
int	i;		/* CONTADOR */

double	dblSol;

/* DECLARACION DE VARIABLE DE ESTRUCTURA */

DatosAprxPol strDatos;

printf("\nIntroduce el grado del polinomio: ");
scanf("%d", &(strDatos.intGrado));

/* RESERVA DE MEMORIA */

strDatos.dblPolinomio = 
	(double *)dblPtAsigMemVec((strDatos.intGrado)+1);

if ( strDatos.dblPolinomio == NULL )
	
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}

for(i=0;i<=(strDatos.intGrado);i++)
	{	/* INICIO FOR */

	printf("\nIntroduce coeficiente %d-Esimo: ", i);
	scanf("%lf", &(strDatos.dblPolinomio[i]));

	}	/* FINAL FOR */

printf("\nIntroduce el numero maximo de iteraciones: ");
scanf("%d", &(strDatos.intNMI));

printf("\nIntroduce la tolerancia: ");
scanf("%lf", &(strDatos.dblTol));

printf("\nIntroduce la aproximacion inicial: ");
scanf("%lf", &(strDatos.dblx0));

/* CALCULO DE LA SOLUCION */

i = NewtonPoli(&strDatos);

printf("\nEl codigo devuelto es %d.\n", i);
printf("\nLa raiz es %lf.\n", strDatos.dblSolucion);
printf("\nEl error cometido es %g.\n", strDatos.dblError);

dblSol = dblEvaluarPolinomio(strDatos.dblPolinomio, strDatos.intGrado, 
		strDatos.dblSolucion);

printf("\nEl valor del polinomio en la raiz es de %.16e\n.", dblSol);

return 0;
}

