#include <stdio.h>
#include <getnum.h>

int main(void) {
    float vendido, total = 300, porcentaje = 0;
    do {
        vendido = getint("Ingrese el monto vendido: ");
    } while (vendido < 0);
    if (vendido > 4000) porcentaje = 9;
    else if (vendido > 2000) porcentaje = 7;
    else if (vendido > 1000) porcentaje = 5;
    total+=vendido*porcentaje/100;
    printf("El monto a cobrar es de $%f\n", total);
    return 0;
}