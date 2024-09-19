#include <stdio.h>

int main(void) {
    printf("Ingrese un caracter: ");
    unsigned char caracter = getchar();
    if (caracter >= 'a' && caracter <= 'z')
        printf("El caracter %c es una letra minúscula\n", caracter);
    else if (caracter >= 'A' && caracter <= 'Z')
        printf("El caracter %c es una letra mayúscula\n", caracter);
    else printf("El caracter %c no es una letra\n", caracter);
    return 0;
}