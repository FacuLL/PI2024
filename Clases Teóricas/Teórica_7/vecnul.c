#include <stdio.h>
#include <assert.h>

int vecnull(const int *vec, size_t dim) {
    if (dim == 0) return 1;
    if (*vec != 0) return 0;
    return vecnull(vec+1, dim-1);
}

int main(void) {
    int vec1[] = {0, 0, 0, 0};
    int vec2[] = {};
    int vec3[] = {0, 0, 1, 0};
    printf("%d %d %d %d\n", vecnull(vec1, 4), vecnull(vec2, 0), vecnull(vec3, 4), vecnull(vec3, 1));

    int v[] = {9, 3, 2, 3};
    assert(!vecnull(v, 4) && !vecnull(v, 1));
    assert(vecnull(v, 0));
    int v2[100] = {0};
    assert(vecnull(v2, 100));
    return 0;
}