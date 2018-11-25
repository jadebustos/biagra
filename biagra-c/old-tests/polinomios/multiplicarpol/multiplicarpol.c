#include <stdio.h>

#include "polinomios.h"
#include "resmem.h"

int main (void)

{
int 	i,
    	intGrado1,
	intGrado2;

double 	*dblPolinomio1,
	*dblPolinomio2,
	*dblResultado;

printf("\nIntroduce el grado del primer polinomio: ");
scanf("%d", &intGrado1);

/* RESERVA DE MEMORIA */

dblPolinomio1 = (double *)dblPtAsigMemVec(intGrado1+1);

printf("\nIntroduce el grado del segundo polinomio: ");
scanf("%d", &intGrado2);

/* RESERVA DE MEMORIA */

dblPolinomio2 = (double *)dblPtAsigMemVec(intGrado2+1);

/* RESERVA DE MEMORIA */

dblResultado = (double *)dblPtAsigMemVec(intGrado1+intGrado2+1);

/* PETICION DE LOS COEFICIENTES DEL PRIMER POLINOMIO */

for(i=0;i<=intGrado1;i++)
	{
	printf("\nIntroduce el coeficiente %d-esimo del primer polinomio: ", i);
	scanf("%lf", &dblPolinomio1[i]);
	}

/* PETICION DE LOS COEFICIENTES DEL SEGUNDO POLINOMIO */

for(i=0;i<=intGrado2;i++)
	{
	printf("\nIntroduce el coeficiente %d-esimo del segundo polinomio: ", i);
	scanf("%lf", &dblPolinomio2[i]);
	}

/* MULTIPLICAR AMBOS POLINOMIOS */

MultiplicarPolinomios(dblPolinomio1, intGrado1, dblPolinomio2, intGrado2, 
	dblResultado);


/* IMPRIME LOS RESULTADOS */

for(i=0;i<=intGrado1+intGrado2;i++)
	{
	printf("Coeficiente de grado %d: %lf\n", i, dblResultado[i]);	
	}

return (0);
}
