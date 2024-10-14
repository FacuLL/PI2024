#include <stdio.h>

int cociente(int numerador, int denominador, int * resto) {
    if (numerador-denominador < 0) {
        *resto = numerador;
        return 0;
    }
    return 1 + cociente(numerador-denominador, denominador, resto);
}

int main(void) {
    int resto;
    int res = cociente(11, 2, &resto);
    printf("%d %d", res, resto);
    return 0;
}