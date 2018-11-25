#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "resmem.h"

/* ALMACENA LA MATRIZ IDENTIDAD */

int main (void)

{
int	i,
	j,
	intRes,
	intOrden;

double	**dblMatriz;

/* PETICION DE DATOS */

printf("\nIntroduce el orden de la matriz: ");
scanf("%d", &intOrden);

/* RESERVA DE MEMORIA */

dblMatriz = (double **)dblPtAsigMemMat(intOrden, intOrden);

if ( dblMatriz == NULL )
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}

MatrizIdentidad(dblMatriz, intOrden);

printf("\nLa matriz identidad de orden %d:\n\n", intOrden);

for(i=0;i<intOrden;i++)

	{	/* INICIO PRIMER for */
			
	for(j=0;j<intOrden;j++)

		{	/* INICIO SEGUNDO for */

		printf("%lf\t", dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

/* LIBERAR MEMORIA */

FreeMemDblMat(dblMatriz, intOrden);

return (0);
}
