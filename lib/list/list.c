#include "./list.h"
#include <stdlib.h>
#include <assert.h>

int isEmpty(const tList l) {
    return l == NULL;
}

size_t size(const tList l) {
    if (l == NULL) return 0;
    return 1 + size(l->tail);
}

int belongs(const tList l, int elem) {
    if (l == NULL || elem < l->head) return 0;
    if (elem == l->head) return 1;
    return belongs(l->tail, elem);
}

tList add(tList l, int elem) {
    if (l == NULL || elem < l->head) {
        tList aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = l;
        return aux;
    }
    if (elem == l->head) return l;
    l->tail = add(l->tail, elem);
    return l;
}

tList delete(tList l, int elem) {
    if (l == NULL || elem > l->head) return l;
    if (elem == l->head) {
        tList aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = delete(l->tail, elem);
    return l;
}

void freeList(tList l) {
    if (l == NULL) return;
    freeList(l->tail);
    free(l);
}

int head(tList l) {
    assert(!isEmpty(l));
    return l->head;
}