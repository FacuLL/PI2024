#include <stdio.h>
#include <getnum.h>

#define PI 3.1415
#define VOLUMEN_ESFERA(r) ((4/3) * PI * (r) * (r) * (r))

int main(void) {
    float radio = getfloat("Ingrese el radio: ");
    printf("Volumen de la esfera: %fcm3", VOLUMEN_ESFERA(radio));
    return 0;
}