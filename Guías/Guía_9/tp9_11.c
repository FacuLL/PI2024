#include <stdio.h>
#include <assert.h>

#define MAX 10

void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void reemplazoRec(int matriz[][MAX], int dim, int fil, int col, int inc[]);
int estaAdentro(int dim, int fil, int col);

void imprimirMatriz(int matriz[][MAX], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col) {
    static int inc[][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    matriz[fil][col] = !matriz[fil][col];
    for (int i = 0; i < 4; i++)
        reemplazoRec(matriz, dim, fil, col, inc[i]);
}

int estaAdentro(int dim, int fil, int col) {
    return fil >= 0 && fil < dim && col >= 0 && col < dim;
}

void reemplazoRec(int matriz[][MAX], int dim, int fil, int col, int inc[]) {
    if (!estaAdentro(dim, fil, col)) return;
    matriz[fil][col] = !matriz[fil][col];
    reemplazoRec(matriz, dim, fil+inc[0], col+inc[1], inc);
}