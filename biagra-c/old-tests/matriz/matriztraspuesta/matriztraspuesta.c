#include <stdio.h>

#include "resmem.h"
#include "matriz.h"

int main(void)

/* FUNCION QUE ALMACENA LA MATRIZ TRASPUESTA DE UNA DADA */

{
int	i,	/* CONTADOR */
	j,	/* CONTADOR */
	intFilas,
	intCol;

double	**dblMatriz,
	**dblTras;

printf("Introduce las filas de la matriz: ");
scanf("%d", &intFilas);

printf("Introduce las columnas de la matriz: ");
scanf("%d", &intCol);

/* RESERVA DE MEMORIA */

dblMatriz = (double **)dblPtAsigMemMat(intFilas, intCol);

if ( dblMatriz == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}	

dblTras = (double **)dblPtAsigMemMat(intCol, intFilas);

if ( dblTras == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}

/* PETICION DE DATOS DE LA MATRIZ */

for(i=0;i<intFilas;i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<intCol;j++)

		{	/* INICIO SEGUNDO for */

		printf("Introduce a[%d][%d] = ", i+1, j+1);
		scanf("%lf", &dblMatriz[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

/* ALMACENAR LA MATRIZ NULA */

MatrizTraspuesta(dblMatriz, intFilas, intCol, dblTras);

/* MOSTRAR LA MATRIZ HOMOTECIA */

for(i=0;i<intCol;i++)

	{	/* INICIO PRIMER for */

	for(j=0;j<intFilas;j++)

		{	/* INICIO SEGUNDO for */
		
		printf("%lf\t", dblTras[i][j]);

		}	/* FINAL SEGUNDO for */

	printf("\n");

	}	/* FINAL PRIMER for */

/* LIBERAR MEMORIA */

FreeMemDblMat(dblMatriz, intFilas);
FreeMemDblMat(dblTras, intCol);

return (0);
}
