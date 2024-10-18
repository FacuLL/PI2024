#include "./list.h"
#include <stdlib.h>
#include <assert.h>
#define BLOQUE 5

int isEmpty(const TList l) {
    return l == NULL;
}

size_t size(const TList l) {
    if (l == NULL) return 0;
    return 1 + size(l->tail);
}

int belongs(const TList l, int elem) {
    if (l == NULL || elem < l->elem) return 0;
    if (elem == l->elem) return 1;
    return belongs(l->tail, elem);
}

TList add(TList l, int elem) {
    if (l == NULL || elem < l->elem) {
        TList aux = malloc(sizeof(struct node));
        aux->elem = elem;
        aux->tail = l;
        return aux;
    }
    if (elem == l->elem) return l;
    l->tail = add(l->tail, elem);
    return l;
}

TList delete(TList l, int elem) {
    if (l == NULL || elem < l->elem) return l;
    if (elem == l->elem) {
        TList aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = delete(l->tail, elem);
    return l;
}

void freeList(TList l) {
    if (l == NULL) return;
    freeList(l->tail);
    free(l);
}

int elem(TList l) {
    assert(!isEmpty(l));
    return l->elem;
}

int tail(TList l) {
    assert(!isEmpty(l));
    return l->tail;
}

int * toArray(TList l, size_t * dim) {
    int * arr = NULL;
    *dim = 0;
    while (!isEmpty(l)) {
        if (*dim%BLOQUE == 0) arr = realloc(arr, sizeof(int)*BLOQUE);
        arr[(*dim)++] = l->elem;
        l = l->tail;
    }
    if (*dim == 0) {
        free(arr);
        retrun NULL;
    }
    arr = realloc(arr, sizeof(int)*(*dim));
    return arr;
}

int getElemAtIndexRec(const TList l, int idx) {
    assert(!isEmpty(l));
    if (idx == 0) return l->elem;
    return getElemAtIndex(l->tail, idx-1);
}

int getElemAtIndex(const TList l, int idx) {
    assert(idx >= 0);
    return getElemAtIndexRec(l, idx);
}