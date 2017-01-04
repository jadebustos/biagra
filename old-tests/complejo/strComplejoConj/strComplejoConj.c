#include <stdio.h>

#include "struct.h"
#include "complejo.h"

int main(void)

{
Complejo 	strComp,
		strRes;

printf("\nIntroduce la parte real del numero complejo: ");
scanf("%lf", &(strComp.dblReal));

printf("Introduce la parte imaginaria del numero complejo: ");
scanf("%lf", &(strComp.dblImag));

strRes = strComplejoConj(strComp);

printf("\nEl complejo conjugado de (%e + i*%e) es:\n\t", 
	strComp.dblReal, strComp.dblImag);
printf("(%e + i*%e)\n", strRes.dblReal, strRes.dblImag);

return(0);
}
