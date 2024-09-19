#include <stdio.h>
#include <getnum.h>
#include <math.h>

int main(void) {   
    double a,b,c, raiz1, raiz2;

    do {
        a = getdouble("Ingrese el coeficiente cuadrático: ");
        b = getdouble("Ingrese el coeficiente lineal: ");
        c = getdouble("Ingrese el término independiente: ");
        if (a == 0) printf("No es cuadrática\n");
        if (b*b - 4*a*c < 0) printf("No tiene raices reales\n");
    } while (a == 0 || (b*b - 4*a*c) < 0);
    
    raiz1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    raiz2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);

    printf("Las raices son %f y %f\n", raiz1, raiz2);

    return 0;
}