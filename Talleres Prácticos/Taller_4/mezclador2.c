#include <stdio.h>
#include "random.h"

void shuffle(int array[]);
void imprimirArreglo(int array[]);

int main(void) {
    int arreglo[] = { 3, 5, 7, 9, 15, -1 };
    shuffle(arreglo);
    // imprimirArreglo(arreglo);
    return 0;
}

void shuffle(int array[]) {
    int auxiliar;
    printf("%d", sizeof(array));
    for (int i = 0; array[i] != -1; i++) {
        int posicionAleatoria = randInt(0, 1);
        if (posicionAleatoria != i) {
            auxiliar = array[posicionAleatoria];
            array[posicionAleatoria] = array[i];
            array[i] = auxiliar;
        }
    }
}

void imprimirArreglo(int array[]) {
    printf("{ ");
    for (int i = 0; array[i] != -1; i++) {   
        printf("%d", array[i]);
        if (array[i+1] == -1) printf(", ");
    }
    printf(" }\n");
}