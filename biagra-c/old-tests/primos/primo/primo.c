#include <stdio.h>

#include "primos.h"

int main (void)

{

int	intNumero,
	intRes;

printf("\nIntroduce un numero: ");
scanf("%d", &intNumero);

intRes = Primo(intNumero);

switch ( intRes )

	{	/* INICIO SWITCH */

	case 0:
		{
		printf("\n%d es un numero primo.\n", intNumero);
		break;
		}

	default:
		{
		printf("\n%d no es un numero primo.\n", intNumero);
		}
	}	/* FINAL SWITCH */

return (0);
}
