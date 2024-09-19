#include <stdio.h>
#include <getnum.h>

int main(void) {
    int num1 = getint("Ingrese un número: ");
    int num2 = getint("Ingrese otro número: ");
    printf("La suma es %d\n", num1 + num2);
    printf("El promedio es %.2f\n", (float)(num1 + num2) / 2);
    printf("El menor es %d\n", num1 < num2 ? num1 : num2);
    printf("El mayor es %d\n", num1 > num2 ? num1 : num2);
    printf("Los números son %s\n", num1 == num2 ? "iguales" : "distintos");
    return 0;
}