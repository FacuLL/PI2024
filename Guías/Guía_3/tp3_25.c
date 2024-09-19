#include <stdio.h>
#include <getnum.h>

int main(void) {
    int numero, contador = 0;
    do {
        numero = getint("Ingresa un numero entero positivo: ");
        if (numero<0) printf("Numero incorrecto. \n");
    } while (numero<0);
    int anterior = numero;
    for (int i = numero; i > 0; i>>=1) {
        anterior = i;
        i>>=1;
        i<<=1;
        contador+=i^anterior;
    }
    printf("La cantidad de 1 es: %d\n", contador);
    return 0;
}