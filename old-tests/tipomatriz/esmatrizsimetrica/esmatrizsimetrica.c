#include <stdio.h>
#include <stdlib.h>

#include "tipomatriz.h"
#include "resmem.h"

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
	return (-1);
	}

/* PETICION DE COEFICIENTES DE LA MATRIZ */

for(i=0;i<intOrden;i++)

	{	/* INICIO PRIMER for */ 

	for(j=0;j<intOrden;j++)

		{	/* INICIO SEGUNDO for */

		printf("Introduce a[%d][%d]: ", i+1, j+1);
		scanf("%lf", &dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */
	
	printf("\n");

	}	/* FINAL PRIMER for */

/* CLASIFICACION DE LA MATRIZ */

intRes = EsMatrizSimetrica(dblMatriz, intOrden);

printf("\nLa matriz:\n\n");

for(i=0;i<intOrden;i++)

	{	/* INICIO PRIMER for */
			
	for(j=0;j<intOrden;j++)

		{	/* INICIO SEGUNDO for */

		printf("%lf\t", dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

switch ( intRes )

	{	/* INICIO switch */

	case 0:

		{	/* INICIO case 0 */

		printf("\nes simetrica.\n");

		break;
		}	/* FIN case 0 */

	default:

		{	/* INICIO defualt */

		printf("\nno es simetrica.\n");

		break;
		}	/* FINAL default */

	}	/* FINAL switch */

/* LIBERAR MEMORIA */

FreeMemDblMat(dblMatriz, intOrden);

return (0);
}
