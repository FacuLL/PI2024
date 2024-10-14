#include <stdio.h>

void sumatoria(const int *v, int dim, int *res) {
    if (dim == 0) {
        *res = 0;
        return;
    }
    sumatoria(v+1, dim-1, res);
    *res+=*v;
}

int main(void) {
    int v[] = {1, 2, 3, 4};
    int res;
    sumatoria(v, 4, &res);
    printf("%d\n", res);
    return 0;
}