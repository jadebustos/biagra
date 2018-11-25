#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Complejo 	strComp1,
		strComp2,
		strRes;

printf("\nIntroduce la parte real del primer numero complejo: ");
scanf("%lf", &(strComp1.dblReal));

printf("Introduce la parte imaginaria del primer numero complejo: ");
scanf("%lf", &(strComp1.dblImag));

printf("\nIntroduce la parte real del segundo numero complejo: ");
scanf("%lf", &(strComp2.dblReal));

printf("Introduce la parte imaginaria del segundo numero complejo: ");
scanf("%lf", &(strComp2.dblImag));

strRes = strDivComplejos(strComp1, strComp2);

printf("\n(%g + %g*i) / (%g + %g*i) = (%g + %g*i)\n", strComp1.dblReal,
	strComp1.dblImag, strComp2.dblReal, strComp2.dblImag, strRes.dblReal,
	strRes.dblImag);

return(0);
}
