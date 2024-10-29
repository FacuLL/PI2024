// vectADT.c
#include "vectADT.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    vectADT v = newVector();
    putElem(v, 328, 12);
    int res;
    getElem(v, 328, &res);
    assert(res == 12);
    putElem(v, 327, 15);
    putElem(v, 328, 13);
    assert(elemCount(v) == 2);
    puts("OK!");
    return 0;
}