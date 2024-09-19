#include <stdio.h>

int main(void) {
    printf("Ingrese dos caracteres: ");
    unsigned char caracter1 = getchar();
    unsigned char caracter2 = getchar();
    if (caracter1 > caracter2)
        printf("El caracter %c es mayor a %c\n", caracter1, caracter2);
    else if (caracter1 < caracter2)
        printf("El caracter %c es menor a %c\n", caracter1, caracter2);
    else printf("El caracter %c es igual a %c\n", caracter1, caracter2);
    return 0;
}