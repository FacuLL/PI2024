#include <stdio.h>
#include <getnum.h>

int main(void) {
    int c, start = 0, suma = 0;
    printf("Ingrese un numero decimal: ");
    do {
        c = getchar();
        if (c == '.') start = 1;
        if (start && c >= '0' && c <= '9') suma+=(c-'0');
    } while (c != '\n');
    printf("La suma de las cifras decimales es %d\n", suma);
    return 0;
}