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

strRes = strOpuComplejo(strComp);

printf("\nEl opuesto de (%e + i*%e) es (%e + i*%e)\n", strComp.dblReal,
	strComp.dblImag, strRes.dblReal, strRes.dblImag);

return(0);
}
