#include <stdio.h>
#include <stdlib.h>

#include "resmem.h"

/* ASIGNACION DE MEMORIA PARA UNA MATRIZ TRIANGULAR SUPERIOR */

int main(void)

{
int 	intN,
   	i, j;

double 	**dblMatriz;

printf("\nIntroduce las filas de la matriz: ");
scanf("%d", &intN);

dblMatriz = dblPtAsigMemMatTrSup(intN);

if ( dblMatriz == NULL )

	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return(-1);
	}

printf("\nLa direccion de memoria asignada es %p.\n", dblMatriz);

for(i=0;i<intN;i++)
 
   {
   
   for(j=0;i+j<intN;j++)
      
      {
      printf("Introduce a[%d][%d]: ", i, j);
      scanf("%lf", &dblMatriz[i][j]);
      }
   
   printf("\n");
   }
   
printf("\nLos datos introducidos son los siguientes:\n");

for(i=0;i<intN;i++)

   {
   
   for(j=0;i+j<intN;j++)
      {
      printf("%f\t", dblMatriz[i][j]);
      }
      
   printf("\n");
   }   
   
/* LIBERAR MEMORIA ASIGNADA */

FreeMemDblMat(dblMatriz, intN);

return (0);
}
