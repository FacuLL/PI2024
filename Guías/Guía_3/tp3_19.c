#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero = getint("Ingresar numero: "), contador = 0;
    for (int i = numero; i > 0; i/=10) {
        if (i%10==5) contador++;
    }
    printf("El numero %d tiene %d cincos\n", numero, contador);
    return 0;
}