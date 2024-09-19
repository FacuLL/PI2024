#include <stdio.h>
#include <math.h>
#define INICIO 0
#define FIN 15
#define PASOS 0.001

double funcion(double);

int main(void) {
    int hayRaiz = 0;
    double anterior = funcion(INICIO);
    for (double i = INICIO+PASOS; i <= FIN; i+=PASOS) {
        double imagen = funcion(i);
        if(imagen == 0 || imagen*anterior < 0) {
            printf("Hay una raiz en x=%1.3f\n", i);
            hayRaiz = 1;
        }
        anterior = imagen;
    }
    if (!hayRaiz) puts("No se encotraron raices");
    return 0;
}

double funcion(double x) {
    return pow(x, 0.5) + exp(x);
}