#include <stdio.h>
#include <stdlib.h>

#include "resmem.h"

/* ASIGNACION DE MEMORIA PARA MATRICES */

int main(void)

{
int 	intFilas,
   	intCol,
   	i, j;

double 	**dblMatriz;

double **dblPtAsigMemMat(int intFilas, int intCol);

printf("\nIntroduce las filas de la matriz: ");
scanf("%d", &intFilas);

printf("\nIntroduce las columnas de la matriz: ");
scanf("%d", &intCol);

dblMatriz = dblPtAsigMemMat(intFilas, intCol);

if (dblMatriz == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	}

printf("\nLa direccion de memoria asignada es %p.\n", dblMatriz);

for(i=0;i<intFilas;i++)
 
   {
   
   for(j=0;j<intCol;j++)
      
      {
      printf("Introduce a[%d][%d]: ", i, j);
      scanf("%lf", &dblMatriz[i][j]);
      }
   
   printf("\n");
   }
   
printf("\nLos datos introducidos son los siguientes:\n");

for(i=0;i<intFilas;i++)

   {
   
   for(j=0;j<intCol;j++)
      {
      printf("%f\t", dblMatriz[i][j]);
      }
      
   printf("\n");
   }   

/* LIBERAR MEMORIA */

FreeMemDblMat(dblMatriz, intFilas);

return (0);
}
