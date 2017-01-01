#include <stdio.h>
#include <stdlib.h>

#include "polinomios.h"
#include "resmem.h"

int main (void)

{
int 	i,
    	intGrado,
	intOrden,
	intRes;

double 	*dblPolinomio,
	*dblDerivada;

printf("\nIntroduce el grado del polinomio: ");
scanf("%d", &intGrado);

/* RESERVA DE MEMORIA */

dblPolinomio = (double *)dblPtAsigMemVec(intGrado+1);

if ( dblPolinomio == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return (-1);
	}

printf("\nIntroduce el orden de la derivada: ");
scanf("%d", &intOrden);

/* RESERVA DE MEMORIA */

dblDerivada = (double *)dblPtAsigMemVec(intGrado - intOrden + 1);

if ( dblDerivada == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return (-1);
	}

/* PETICION DE LOS COEFICIENTES DEL POLINOMIO */

for(i=0;i<=intGrado;i++)
	{
	printf("\nIntroduce el coeficiente %d-esimo: ", i);
	scanf("%lf", &dblPolinomio[i]);
	}

/* CALCULO DE LA DERIVADA */

intRes = DerivadaPolinomio(dblPolinomio, intGrado, dblDerivada, intGrado-intOrden, intOrden);

/* IMPRIME LOS RESULTADOS */

printf("\nEl codigo de error devuelto es %d\n", intRes);
printf("La derivada %d-esima es:\n\n", intOrden);

for(i=0;i<=intGrado-intOrden;i++)
	{
	printf("Coeficiente de grado %d: %lf\n", i, dblDerivada[i]);	
	}

return (0);
}
