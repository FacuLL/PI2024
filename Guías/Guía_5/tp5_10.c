#include <stdio.h>
#include <getnum.h>

void simplificarFraccion(void);
void sumarFracciones(void);
int elegirAccion(void);
int maximoComunDivisor(int, int);

int main(void) {
    int eleccion = elegirAccion();
    switch (eleccion) {
    case 1:
        simplificarFraccion();
        break;
    case 2:
        sumarFracciones();
    default:
        break;
    }
    return 0;
}

void simplificarFraccion(void) {
    int numerador = getint("Ingresa el numerador: ");
    int denominador = getint("Ingresa el denominador: ");
    int mcd = maximoComunDivisor(numerador, denominador);
    printf("La fraccion simplificada es: %d/%d\n", numerador/mcd, denominador/mcd);
}

void sumarFracciones(void) {
    int num1 = getint("Ingresa el primer numerador: ");
    int den1 = getint("Ingresa el primer denominador: ");
    int num2 = getint("Ingresa el segundo numerador: ");
    int den2 = getint("Ingresa el segundo denominador: ");

    int denominadorComun = den1 * den2;
    int nuevoNumerador = num1 * den2 + num2 * den1;
    int mcd = maximoComunDivisor(denominadorComun, nuevoNumerador);

    printf("El resultado es: %d/%d\n", nuevoNumerador/mcd, denominadorComun/mcd);
}

int elegirAccion(void) {
    puts("1. Simplificar fraccion");
    puts("2. Sumar fracciones");
    puts("3. Terminar ejecucion");
    int eleccion;
    do {
        eleccion = getint("Elegí que queres hacer con el caracter: ");
    } while (eleccion < 1 || eleccion > 3);
    return eleccion;
}

int maximoComunDivisor(int numero1, int numero2) {
    while (numero1 != 0 && numero2 != 0) {
        if (numero1 > numero2) numero1-=numero2;
        else numero2-=numero1;   
    }
    return numero1+numero2;
}