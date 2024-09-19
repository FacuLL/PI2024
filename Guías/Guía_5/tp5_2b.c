#include <stdio.h>
#include <math.h>

int main(void) {
    for ( double x = 4; x < 4.2; x += 0.5)
{
	printf("%f  %f   %f   %f\n", x, fabs(x), ceil(x), floor(x));
	printf("%f  %f\n", pow(x,2), pow(x,.5));
}

    return 0;
}