#include <stdio.h>
#include <getnum.h>
#include <math.h> 
#define DELTA 0.0000001

double exp(double);

int main(void) {
    double x = getdouble("Ingresa el valor de x: ");
    printf("e^%1f = %f\n", x, exp(x));
    return 0;
}

double exp(double x) {
    double resultado = 1;
    double anterior = 0;
    double factorial = 1;
    for (int i = 1; resultado - anterior > DELTA; i++) {
        anterior = resultado;
        factorial*=i;
        resultado+=pow(x, i)/factorial;
    }
    return resultado;
}