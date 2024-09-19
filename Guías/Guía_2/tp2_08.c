#include <stdio.h>
#include <getnum.h>

int main(void) {
    float ms = getfloat("Ingresa la velocidad en m/s: ");
    printf("La velocidad en equivalente a %f km/h\n", ms*3600/1000);
    return 0;
}