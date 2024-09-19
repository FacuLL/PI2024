#include <stdio.h>
#include "random.h"

void shuffle(int array[], int);
void imprimirArreglo(int array[], int);

int main(void) {
    int arreglo[] = { 3, 5, 7, 9, 15 };
    int length = sizeof(arreglo)/sizeof(arreglo[0]);
    imprimirArreglo(arreglo, length);
    shuffle(arreglo, length);
    imprimirArreglo(arreglo, length);
    return 0;
}

void shuffle(int array[], int length) {
    int auxiliar;
    for (int i = 0; i < length; i++) {
        int posicionAleatoria = randInt(0, length-1);
        if (posicionAleatoria != i) {
            auxiliar = array[posicionAleatoria];
            array[posicionAleatoria] = array[i];
            array[i] = auxiliar;
        }
    }
}

void imprimirArreglo(int array[], int length) {
    printf("{ ");
    for (int i = 0; i < length; i++) {   
        printf("%d", array[i]);
        if (i != length-1) printf(", ");
    }
    printf(" }\n");
}