#include <stdio.h>
#include <getnum.h>
#include <math.h>

double redondeo(double, int);

int main(void) {
    double numero = getdouble("Ingrese el numero a redondear: ");
    int cifras = getint("Ingrese la cantidad de decimales: ");
    printf("El resultado es: %f\n", redondeo(numero, cifras));
    return 0;
}

double redondeo(double numero, int cifras) {
    int multiplicador = pow(10, cifras);
    return (double) ((int) (numero*multiplicador+0.5)) / multiplicador; 
}