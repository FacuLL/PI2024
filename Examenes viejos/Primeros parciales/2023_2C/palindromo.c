#include <stdio.h>
#include <assert.h>
#define COLS 5

int esVectorPalindromo(const int v[], int dim) {
    for (int i = 0; i < dim/2; i++) {
        if (v[i] != v[dim-i-1]) return 0;
    }
    return 1;
}

void copiarFila(int dim, const int src[], int trg[][dim], int fila) {
    for (int i = 0; i < dim; i++) {
        trg[fila][i] = src[i];
    }
}

int eliminar(int m[][COLS]) {
    int dim = 0;
    for (int i = 0; i < COLS; i++) {
        if (!esVectorPalindromo(m[i], COLS)) copiarFila(COLS, m[i], m, dim++);
    }
    return dim;
}

int main(void) {
    // Genera un caso de prueba para este programa, con asserts (sin printear)
    int m[COLS][COLS] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5}
    };
    int dim = eliminar(m);
    assert(dim == 4);
    puts("OK!");
    return 0;
}