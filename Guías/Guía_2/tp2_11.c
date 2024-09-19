#include <stdio.h>
#include <getnum.h>

int main(void) {
    unsigned char caracter1 = getchar();
    unsigned char caracter2 = getchar();
    printf("El caracter con mayor valor ascii es: %c \n", caracter1 > caracter2 ? caracter1 : caracter2);
    return 0;
}