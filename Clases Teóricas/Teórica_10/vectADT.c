#include "vectADT.h"
#include <stdlib.h>

typedef struct tElem {
    elemType elem;
    char isOccupied;
} tElem;

struct vectCDT {
    tElem * elems;
    size_t dim;
    size_t elemCount;
};

vectADT newVector(void) {
    return calloc(1, sizeof(struct vectCDT));
}

int elemCount(vectADT v) {
    return v->elemCount;
}

int getElem(vectADT v, size_t idx, elemType *res) {
    if (idx > v->dim || !v->elems[idx].isOccupied) return 0;
    *res = v->elems[idx].elem;
    return 1;
}

int removeElem(vectADT v, size_t idx) {
    if (idx >= v->dim || !v->elems[idx].isOccupied) return 0;
    v->elems->isOccupied = 0;
    v->elemCount--;
}

int putElem(vectADT v, size_t idx, elemType elem) {
    if (idx >= v->dim) {
        v->elems = realloc(v->elems, sizeof(tElem) * (idx+1));
        for (size_t i = v->dim; i < idx+1; i++) {
            v->elems[i].isOccupied = 0;
        }
        v->dim = idx+1;
    }
    v->elems[idx].elem = elem;
    v->elemCount+=!v->elems[idx].isOccupied;
    v->elems[idx].isOccupied = 1;
}

void freeVec(vectADT v) {
    free(v->elems);
    free(v);
}