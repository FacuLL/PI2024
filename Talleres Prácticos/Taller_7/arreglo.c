#include <stdio.h>
#include <getnum.h>
#include <stdlib.h>
#define BLOQUE 5

int esta(int *v, int dim, int valor);
int *cargarNumeros(int *dim);

int main(void) {
    int dim;
    int *arr;
    arr = cargarNumeros(&dim);

    for (int i = 0; i < dim; i++)
        printf("%d ", arr[i]);
    
    free(arr);
    return 0;
}

int esta(int *v, int dim, int valor) {
    for (int i = 0; i < dim; i++) {
        if (v[i] == valor) return 1;
    }
    return 0;
}

int *cargarNumeros(int *dim) {
    int * arreglo = NULL;
    *dim = 0;
    int numero;
    while(!esta(arreglo, *dim, (numero = getint("Ingrese numero: ")))) {
        if ((*dim)%BLOQUE == 0) {
            arreglo = realloc(arreglo, ((*dim)+BLOQUE)*sizeof(int));
            printf("El vector aumento su tamaño a %d enteros\n", (*dim)+BLOQUE);
        }
        arreglo[(*dim)++] = numero;
    }
    return arreglo;
}