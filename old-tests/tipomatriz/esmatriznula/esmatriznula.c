#include <stdio.h>
#include <stdlib.h>

#include "tipomatriz.h"
#include "resmem.h"

int main (void)

{
int	i,
	j,
	intRes,
	intFilas,
	intCol;

double	**dblMatriz,
	dblTol;

/* PETICION DE DATOS */

printf("\nIntroduce las filas de la matriz: ");
scanf("%d", &intFilas);

printf("\nIntroduce las columnas de la matriz: ");
scanf("%d", &intCol);

printf("\nIntroduce la tolerancia: ");
scanf("%lf", &dblTol);

/* RESERVA DE MEMORIA */

dblMatriz = (double **)dblPtAsigMemMat(intFilas, intCol);

if ( dblMatriz == NULL )
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return (-1);
	}

/* PETICION DE COEFICIENTES DE LA MATRIZ */

for(i=0;i<intFilas;i++)

	{	/* INICIO PRIMER for */ 

	for(j=0;j<intCol;j++)

		{	/* INICIO SEGUNDO for */

		printf("Introduce a[%d][%d]: ", i+1, j+1);
		scanf("%lf", &dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */
	
	printf("\n");

	}	/* FINAL PRIMER for */

/* CLASIFICACION DE LA MATRIZ */

intRes = EsMatrizNula(dblMatriz, intFilas, intCol, dblTol);

printf("\nLa matriz:\n\n");

for(i=0;i<intFilas;i++)

	{	/* INICIO PRIMER for */
			
	for(j=0;j<intCol;j++)

		{	/* INICIO SEGUNDO for */

		printf("%lf\t", dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

switch ( intRes )

	{	/* INICIO switch */

	case 0:

		{	/* INICIO case 0 */

		printf("\nes nula.\n");
		break;
		}	/* FIN case 0 */

	default:

		{	/* INICIO defualt */

		printf("\nno es nula.\n");
		break;
		}	/* FINAL default */

	}	/* FINAL switch */

/* LIBERAR MEMORIA */

FreeMemDblMat(dblMatriz, intFilas);

return (0);
}
