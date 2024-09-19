#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero1 = getint("Ingrese el primer numero: ");
    int numero2 = getint("Ingrese el segundo numero: ");
    printf("El primer numero %ses multiplo del segundo \n", numero1%numero2 == 0 ? "" : "no ");
    return 0;
}