#include <stdio.h>
#include <stdlib.h>

#include "polinomios.h"
#include "resmem.h"

/* EVALUACION DE UN POLINOMIO EN UN PUNTO */

int main(void)

{
int	i,
	intGrado;

double	*dblPoli,
	dblPunto,
	dblValor;

printf("\nIntroduce el grado del polinomio: ");
scanf("%d", &intGrado);

/* RESERVA DE MEMORIA */

dblPoli = (double *)dblPtAsigMemVec(intGrado+1);

for(i=0;i<=intGrado;i++)
	{
	printf("\nIntroduce el coeficiente %d-Esimo: ", i);
	scanf("%lf", &dblPoli[i]);
	}

printf("\nIntroduce el punto: ");
scanf("%lf", &dblPunto);

dblValor = dblEvaluarPolinomio(dblPoli, intGrado, dblPunto);

printf("\n\nEl valor del polinomio en %lf es %lf.\n", dblPunto, dblValor);

return 0;
}
