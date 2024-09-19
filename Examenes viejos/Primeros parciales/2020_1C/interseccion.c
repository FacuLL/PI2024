#include <stdio.h>
#include <assert.h>

#define FILS 3
#define COLS 6
#define MIN(a,b) ((a)>(b)?(b):(a))

int seEncuentra(const int v[], int valor, int limite) {
    for (int i = 0; i < limite; i++) {
        if (v[i] == valor) return 1;
    }
    return 0;
}

int interseccionVectores(const int v1[], const int v2[], int resultado[]) {
    int dim = 0;
    for (int i = 0; i < COLS; i++)
        if (!seEncuentra(resultado, v1[i], dim) && seEncuentra(v2, v1[i], COLS))
            resultado[dim++] = v1[i];
    return dim;
}

void completarCeros(int v[], int inicio, int final) {
    for (int i = inicio; i < final; i++) {
        v[i] = 0;
    }
}

void interseccion(int m1[][COLS], int m2[][COLS], int resultado[][COLS]) {
    for (int i = 0; i < FILS; i++) {
        int cantidad = interseccionVectores(m1[i], m2[i], resultado[i]);
        completarCeros(resultado[i], cantidad, COLS);
    }
}

void sonIguales(int expected[][COLS], int actual[][COLS])
{
    for (int i = 0; i < FILS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            assert(expected[i][j] == actual[i][j]);
        }
    }
}

int main()
{
    int m1[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                          {2, 1, 2, 1, 3, 1},
                          {10, 9, 4, 3, 10, 5}};
    int m2[FILS][COLS] = {{6, 2, 1, 4, 5, 3},
                          {1, 1, 2, 3, 3, 1},
                          {1, 19, 7, 8, 1, 15}};
    int m3[FILS][COLS];
    interseccion(m1, m2, m3);
    int expected[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                                {2, 1, 3, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0}};
    sonIguales(expected, m3);

    int m4[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                          {2, 1, 2, 1, 3, 1},
                          {10, 9, 4, 3, 10, 5}};
    int m5[FILS][COLS] = {{6, 2, 1, 4, 28, 29},
                          {1, 1, 331, 3, 3, 1},
                          {1, 19, 7, 4, 1, 15}};
    int m6[FILS][COLS];
    interseccion(m4, m5, m6);
    int expected2[FILS][COLS] = {{1, 2, 4, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0},
                                {4, 0, 0, 0, 0, 0}};
    sonIguales(expected2, m6);

    int m7[FILS][COLS] = {{1, 1, 1, 1, 1, 1},
                          {3, 2, 25, 4, 9, 10},
                          {10, 9, 4, 3, 10, 5}};
    int m8[FILS][COLS] = {{1, 1, 1, 1, 1, 1},
                          {10, 25, 3, 100, 200, 300},
                          {5, 4, 9, 10, 3, 112}};
    int m9[FILS][COLS];
    interseccion(m7, m8, m9);
    int expected3[FILS][COLS] = {{1, 0, 0, 0, 0, 0},
                                {3, 25, 10, 0, 0, 0},
                                {10, 9, 4, 3, 5, 0}};
    sonIguales(expected3, m9);

    puts("OK!");
}