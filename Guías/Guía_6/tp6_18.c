#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 );

int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, 
                    {4,4,5,6}, 
                    {7,8,8,9}};

  int m2[][COLS] = {{0,1,2,3}, 
                    {-3,7,8,9}, 
                    {-1,3,4,7}, 
                    {4,5,6,8}};

  int m3[][COLS] = {{2,3,3,7}};

  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}

int filaAmigaAFila(const int (m1[])[COLS], unsigned int fila1, const int (m2[])[COLS], unsigned int fila2) {
    int j = 0;
    for (int i = 0; i < COLS; i++) {
        while (j < COLS && m2[fila2][j] < m1[fila1][i]) j++;
        if (m2[fila2][j] != m1[fila1][i]) return 0;
    }
    return 1;
}

int filaAmigaAMatriz(const int (m1[])[COLS], unsigned int fila, const int (m2[])[COLS], unsigned int fils2) {
    for (int i = 0; i < fils2; i++) {
        if (filaAmigaAFila(m1, fila, m2, i)) return 1;
    }
    return 0;
}

int matrizAmigaAMatriz(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2) {
    for (int i = 0; i < fils1; i++) {
        if (!filaAmigaAMatriz(m1, i, m2, fils2)) return 0;
    }
    return 1;
}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ) {
    if (matrizAmigaAMatriz(m1, fils1, m2, fils2)) return 1;
    else if (matrizAmigaAMatriz(m2, fils2, m1, fils1)) return 2;
    else return 0;
}