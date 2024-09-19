#include <stdio.h>
#include <assert.h>

unsigned char esAscendente(const int array[], int dimArray);

int main(void) {
    int a[] = {1,2,3,4,4,4,7,8};
    assert(esAscendente(a, sizeof(a)/sizeof(a[0])) == 1);
    int b[] = {2,1,3,4,4,4,7,8};
    assert(esAscendente(b, sizeof(b)/sizeof(b[0])) == 0);
    int c[] = {1,1,3,4,4,4,7,5};
    assert(esAscendente(c, sizeof(c)/sizeof(c[0])) == 0);
    int d[] = {0};
    assert(esAscendente(d, sizeof(d)/sizeof(d[0])) == 1);
    puts("OK!");
    return 0;
}

unsigned char esAscendente(const int array[], int dimArray) {
    if (dimArray < 2) return 1;
    for (int i = 1; i < dimArray; i++) {
        if (array[i] < array[i-1]) return 0;
    }
    return 1;
}