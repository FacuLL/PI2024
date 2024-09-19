#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero = getint("Ingrese numero para calcular factorial: ");
    if (numero < 0) {
        printf("Solo numeros positivos o cero estan permitidos.");
        return 1;
    }
    int resultado = numero;
    for (int i = numero-1; i > 0; i--) {
        resultado*=i;
    }
    printf("%d! = %d\n", numero, resultado);
    return 0;
}