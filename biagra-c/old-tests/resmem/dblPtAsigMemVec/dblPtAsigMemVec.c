#include <stdio.h>
#include <stdlib.h>

#include "resmem.h"

/* ASIGNACION DE MEMORIA A PUNTEROS UNIDIMENSIONALES DE TIPO DOUBLE */

int main(void)

{
int 	intN,
   	i;

double 	*dblMatriz;

double *dblPtAsigMemVec(int intN);

printf("\nIntroduce el tamanyo del puntero: ");
scanf("%d", &intN);

dblMatriz = (double *)dblPtAsigMemVec(intN);

if ( dblMatriz == NULL )
	
	{
	printf("\nHubo un error en la asignacion de memoria.\n");
	return (-1);
	}

printf("\nLa direccion de memoria asignada es %p.\n", dblMatriz);

for(i=0;i<intN;i++)

   {
   printf("Introduce el dato %d: ", i);
   scanf("%lf", &dblMatriz[i]);
   }
   
printf("\nLos datos introducidos son los siguientes:\n");

for(i=0;i<intN;i++)

   {
   printf("\nMatriz[%d] = %f", i, dblMatriz[i]);
   }   
   
printf("\n"); 

/* LIBERAR MEMORIA ASIGNADA */

free(dblMatriz);

return (0);
}
