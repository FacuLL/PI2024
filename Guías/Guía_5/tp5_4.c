#include <stdio.h>

double potencia(double, int);

int main(void) {
    printf("%f\n", potencia(5, -2));
    return 0;
}

double potencia(double base, int exponente) {
    if (base == 0 && exponente == 0) return -1;
    int moduloExponente = exponente >= 0 ? exponente : -exponente;
    double resultado = 1;
    for (int i = 1; i <= moduloExponente; i++) {
        resultado*=base;
    }
    if (exponente < 0) resultado = 1/resultado;
    return resultado;
}