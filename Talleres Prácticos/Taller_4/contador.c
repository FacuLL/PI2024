#include <stdio.h>
#include "random.h"
#include <ctype.h>

int contarLetra(int, int);

int main(void) {
    randomize();
    int letra = randInt('A', 'Z');
    int N = randInt(1, 256);
    printf("En el texto aparece %d veces la letra %c hasta el %d caracter.\n", contarLetra(letra, N), letra, N);
    return 0;
}

int contarLetra(int letra, int tope) {
    int c;
    int contador = 0;
    puts("Ingrese un texto: ");
    for (int i = 0; i < tope && (c = getchar()) != EOF; i++) {
        if (toupper(c) == letra) contador++;
    }
    return contador;
}