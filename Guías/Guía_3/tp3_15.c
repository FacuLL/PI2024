#include <stdio.h>
#include <getnum.h>
#include <math.h>

int main(void) {
    int binario, suma = 0, potencia = 0;
    binario = getint("Ingresa un numero en binario: ");
    for (int i = binario; i > 0; i/=10) {
        if (i%10>1) {
            printf("No se ha ingresado un binario\n");
            return 1;
        }
        suma+=(i%10)*pow(2, potencia);
        potencia++;
    }
    printf("El numero es %d\n", suma);
    return 0;
}