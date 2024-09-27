#include <stdio.h>
#include <stdlib.h>
#define BLOQUE 1000

int main(void) {
    unsigned char *v = NULL;
    int dim = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (dim%BLOQUE == 0) v = realloc(v, dim+BLOQUE);
        v[dim++] = c;
    }
    v = realloc(v, dim);
    return 0;
}