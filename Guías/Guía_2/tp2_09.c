#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero = getint("Ingresa numero entero: ");
    printf("El numero dividido por 2 es %d \n", numero>>1);
    return 0;
}