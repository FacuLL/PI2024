#include <stdio.h>
#include <getnum.h>

float
f1 ( float x);

int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un n�mero real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble de %g es %g\n",x, y);
	printf("El triple de %g es %g\n",x , z);
	return 0;
}

float
f1 ( float x)
{
	return 2 * x;
}

