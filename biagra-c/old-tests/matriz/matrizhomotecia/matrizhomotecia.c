#include <stdio.h>

#include "resmem.h"
#include "matriz.h"

int main(void)

/* FUNCION QUE ALMACENA LA HOMOTECIA DE RAZON LANDA */

{
int	i,	/* CONTADOR */
	j,	/* CONTADOR */
	intOrden;

double	**dblMatriz,
	dblRazon;

printf("Introduce el orden de la matriz: ");
scanf("%d", &intOrden);

printf("Introduce la razon de la homotecia: ");
scanf("%lf", &dblRazon);

/* RESERVA DE MEMORIA */

dblMatriz = (double **)dblPtAsigMemMat(intOrden, intOrden);

if ( dblMatriz == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}	

/* PETICION DE DATOS PARA "ENSUCIAR" LA MATRIZ */

for(i=0;i<intOrden;i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<intOrden;j++)

		{	/* INICIO SEGUNDO for */

		printf("Introduce a[%d][%d] = ", i+1, j+1);
		scanf("%lf", &dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

/* ALMACENAR LA HOMOTECIA */

MatrizHomotecia(dblMatriz, dblRazon, intOrden);

/* MOSTRAR LA MATRIZ HOMOTECIA */

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
