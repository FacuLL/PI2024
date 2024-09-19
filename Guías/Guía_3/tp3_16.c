#include <stdio.h>
#include <getnum.h>
#include <math.h>

int main(void) {
    int decimal = getint("Ingrese el numero decimal: "), suma = 0, potencia = 0;
    for (int i = decimal; i > 0; i/=2) {
        suma+=(i%2)*pow(10, potencia);
        potencia++;
    }
    printf("El numero binario es: %d\n", suma);
    return 0;
}