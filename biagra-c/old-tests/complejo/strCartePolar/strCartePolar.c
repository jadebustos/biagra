#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Complejo 	strComp1,
		strComp2;

Polar	strPolar;

printf("\nIntroduce la parte real del numero complejo: ");
scanf("%lf", &(strComp1.dblReal));

printf("Introduce la parte imaginaria del numero complejo: ");
scanf("%lf", &(strComp1.dblImag));

strPolar = strCartePolar(strComp1);

printf("\nEl complejo (%lf + %lf*i) en polares:\n\t", 
	strComp1.dblReal, strComp1.dblImag);
printf("Modulo = %lf\tArgumento = %lf\n", 
	strPolar.dblMod, strPolar.dblArg);

strComp2 = strPolarCarte(strPolar);

printf("\n\nDe nuevo en cartesianas:\n\t (%lf + %lf*i)\n", 
	strComp2.dblReal, strComp2.dblImag);

return(0);
}
