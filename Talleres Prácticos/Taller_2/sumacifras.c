#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero, suma;
    numero = getint("Ingrese un numero entero: ");
    if (numero < 0) numero = -numero;
    suma = 0;
    while (numero != 0) {
        suma+=numero%10;
        numero/=10;
    }
    printf("La suma de las cifras es %d\n", suma);
    return 0;
}