#include <stdio.h>
#include <getnum.h>

int main(void) {
    printf("Ingrese dos caracteres: ");
    unsigned char caracter1 = getchar();
    unsigned char caracter2 = getchar();
    printf("El caracter '%c' es %s al caracter '%c'\n", caracter1, caracter1 > caracter2 ? "mayor" : "menor", caracter2);
    return 0;
}