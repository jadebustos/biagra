#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Polar 	strComp1,
	strComp2;

Complejo	strRes;

printf("\nIntroduce el modulo del numero complejo: ");
scanf("%lf", &(strComp1.dblMod));

printf("Introduce el argumento del numero complejo: ");
scanf("%lf", &(strComp1.dblArg));

strRes = strPolarCarte(strComp1);

printf("\nModulo = %lf\tArgumento = %lf\n", 
	strComp1.dblMod, strComp1.dblArg);

printf("En cartesianas es: (%lf + %lf*i)\n", 
	strRes.dblReal, strRes.dblImag);

strComp2 = strCartePolar(strRes);

printf("\n\nModulo = %lf\tArgumento = %lf\n", 
	strComp2.dblMod, strComp2.dblArg);

return(0);
}
