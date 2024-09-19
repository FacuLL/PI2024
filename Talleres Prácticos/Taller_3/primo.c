#include <stdio.h>
#include <getnum.h>
#include <math.h>

int esPrimo(int);
void imprimirNPrimos(int);

int main(void) {
    int numero = getint("Ingrese un numero: ");
    imprimirNPrimos(numero);
    return 0;
}

int esPrimo(int num) {
    if (num == 1) return 0;
    if (num < 0) num = -num;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num%i == 0) return 0;
    }
    return 1;
}

void imprimirNPrimos(int n) {
    if (n <= 0) return;
    int cantidadImpresa = 0;
    int siguientePrimo = 2;
    while (cantidadImpresa < n) {
        if (esPrimo(siguientePrimo)) {
            printf("%d ", siguientePrimo);
            cantidadImpresa++;
        } 
        siguientePrimo++;
    }
}
 
