#include "utillist.h" 
#include <stdlib.h>

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

int getElemAtIndexRec(const TList l, int idx) {
    assert(!isEmpty(l));
    if (idx == 0) return l->elem;
    return getElemAtIndex(l->tail, idx-1);
}

int getElemAtIndex(const TList l, int idx) {
    assert(idx >= 0);
    return getElemAtIndexRec(l, idx);
}