#include <stdio.h>

int pertenece(const int arreglo[], unsigned dim, int valor);
int pertenece2(const int * arreglo, unsigned dim, int valor);

int main(void) {
    
    return 0;
}

int pertenece(const int arreglo[], unsigned dim, int valor) {
    for (int i = 0; i < dim; i++) {
        if (arreglo[i] == valor) return 1;
    }
    return 0;
}

int pertenece2(const int * arreglo, unsigned dim, int valor) {
    int * final = arreglo + dim;
    while (arreglo < final) {
        if (*arreglo == valor) return 1;
        arreglo++;
    }
    return 0;
}