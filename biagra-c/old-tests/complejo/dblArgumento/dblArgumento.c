#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Complejo 	strComp;

double	dblRes;

printf("\nIntroduce la parte real del numero complejo: ");
scanf("%lf", &(strComp.dblReal));

printf("Introduce la parte imaginaria del numero complejo: ");
scanf("%lf", &(strComp.dblImag));

dblRes = dblArgumento(strComp);

printf("\nEl Argumento de (%lf + %lf*i) es:\n\t", 
	strComp.dblReal, strComp.dblImag);
printf("%lf\n", dblRes);

return(0);
}
