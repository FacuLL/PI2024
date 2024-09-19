#include <stdio.h>
#include <getnum.h>

int main(void) {
    unsigned char caracter = getchar();
    printf("El caracter %ses una letra \n", caracter >= 'A' && caracter <= 'z' ? "" : "no ");
    return 0;
}