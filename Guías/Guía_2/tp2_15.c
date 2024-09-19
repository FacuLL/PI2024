#include <stdio.h>
#include <getnum.h>
#define diferencia ('a' - 'A')

int main(void) {
    printf("Ingrese un caracter: ");
    unsigned char caracter = getchar();
    printf("El caracter ingresado en mayúscula es %c\n", caracter >= 'a' && caracter <= 'z' ? (caracter - diferencia) : caracter);
    return 0;
}