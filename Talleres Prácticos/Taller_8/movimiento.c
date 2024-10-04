#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BLOQUE 5
#define MINIMO -1
#define MAXIMO 1

typedef struct {
    int x;
    int y;
} tPunto2D;

int randInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

int main(void) {
    srand(time(NULL));
    long dim = 1;
    tPunto2D inicial = {.x=0,.y=0};
    tPunto2D * puntos = malloc(sizeof(tPunto2D)*BLOQUE);
    puntos[0] = inicial;
    while (dim == 1 || puntos[dim-1].x != 0 || puntos[dim-1].y != 0) {
        int dx = randInt(MINIMO, MAXIMO);
        int dy = randInt(MINIMO, MAXIMO);
        if (dim%BLOQUE == 0) puntos = realloc(puntos, (dim+BLOQUE)*sizeof(tPunto2D));
        tPunto2D nuevo = {.x=puntos[dim-1].x+dx,.y=puntos[dim-1].y+dy};
        puntos[dim++] = nuevo;
    }
    puntos = realloc(puntos, dim*sizeof(tPunto2D));
    printf("Se tardó %d actualizaciones:\n", dim-1);
    // for (int i = 0; i < dim; i++) 
    //     printf("%d/%d ", puntos[i].x, puntos[i].y);
    free(puntos);
    return 0;
}