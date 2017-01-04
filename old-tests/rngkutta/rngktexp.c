#include <stdio.h>

#include "rngkutta.h"

int main(void)

{
DatosRK varDatos;
int	i,
	j,
	intResultados = 0;

/* INICIALIZAR VARIABLE */

intResultados = EulerMejorado(&varDatos); 

if ( intResultados != 0 )
	{
	printf("\nEl valor devuelto es: %d\n", intResultados);
	}

else
	{	/* INICIO else */

	printf("\nCOEFICIENTES b[i]\n");

	for(i=0;i<varDatos.strCoefi.intEtapas;i++)
		
		printf("\nb[%d] = %f", i+1, varDatos.strCoefi.dblB[i]);

	printf("\n\nCOEFICIENTES C[i]\n");

	for(i=0;i<varDatos.strCoefi.intEtapas;i++)

		printf("\nc[%d] = %f", i+1, varDatos.strCoefi.dblC[i]);

	printf("\n\nCOEFICIENTES a[i][j]\n");

	for(i=0;i<varDatos.strCoefi.intEtapas;i++)

		{	/* INICIO PRIMER for */

		for(j=0;j<=i;j++)

			{	/* INICIO SEGUNDO for */
			
			printf("%f\t", varDatos.strCoefi.dblMatriz[i][j]);

			}	/* FINAL SEGUNDO for */

		printf("\n");

		}	/* FINAL PRIMER for */

	}	/* FIN else */

return (0);
}
