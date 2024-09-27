#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main(void) {
    
    return 0;
}

void mostrarArreglo(int *v, int dim);

void caso1() {
    int * arr;
    int i;
    arr = malloc(TAM*sizeof(int));
    i = 0;
    while(i < TAM) arr[i++] = 0;
    mostrarArreglo(arr, TAM);
    free(arr);
}

void caso2() {
    int *arr;
    arr = NULL;
    arr = realloc(arr, TAM*sizeof(int));
    for (int i = 0; i < TAM; i++) arr[i] = 0;
    mostrarArreglo(arr, TAM);
    free(arr);
}

void caso3() {
    int *arr;
    arr = calloc(arr, TAM, sizeof(int));
    mostrarArreglo(arr, TAM);
    free(arr);
}