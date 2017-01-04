#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Complejo 	strComp,
		strInv,
		strProd;

printf("\nIntroduce la parte real del numero complejo: ");
scanf("%lf", &(strComp.dblReal));

printf("Introduce la parte imaginaria del numero complejo: ");
scanf("%lf", &(strComp.dblImag));

strInv = strInvComplejo(strComp);

printf("\nEl inverso de (%g + %g*i) es:\n\t", 
	strComp.dblReal, strComp.dblImag);
printf("(%g + %g*i)\n", strInv.dblReal, strInv.dblImag);

strProd = strProdComplejos(strComp, strInv);

printf("\nSu producto es: (%g + %g*i)\n", strProd.dblReal, strProd.dblImag);

return(0);
}
