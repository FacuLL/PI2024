#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./utillist.h"
 
TList deleteAll(TList l1, const TList l2);
 
int main()
{
    int v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TList l1 = fromArray(v1, 9);
    int v2[] = {2, 4, 6, 8};
    TList l2 = fromArray(v2, 4);
    int v1sinv2[] = {1, 3, 5, 7, 9};
    TList l1sinv2 = deleteAll(l1, l2);
    assert(checkElems(l1sinv2, v1sinv2, 5));
    freeList(l1sinv2);
 
    int v3[] = {1, 2, 3, 4, 5, 6, 7};
    TList l3 = fromArray(v3, 7);
    int v4[] = {0, 1, 3, 5, 10, 11, 14};
    TList l4 = fromArray(v4, 7);
    int v3sinv4[] = {2, 4, 6, 7};
    TList l3sinv4 = deleteAll(l3, l4);
    assert(checkElems(l3sinv4, v3sinv4, 4));
    freeList(l3sinv4);
 
    int v5[] = {1, 2, 3, 4, 5, 6, 7};
    TList l5 = fromArray(v5, 7);
    int v6[] = {1, 2, 3, 4, 5, 6, 7};
    TList l6 = fromArray(v6, 7);
    TList l5sinv6 = deleteAll(l5, l6);
    assert(l5sinv6 == NULL);
 
    TList l7 = NULL;
    TList l8 = fromArray(v1, 9);
    TList l7sinv8 = deleteAll(l7, l8);
    assert(l7sinv8 == NULL);
 
    TList l9 = fromArray(v1, 9);
    TList l10 = NULL;
    TList l9sinv10 = deleteAll(l9, l10);
    assert(checkElems(l9sinv10, v1, 9));
    freeList(l9sinv10);
 
    puts("OK!");
    return 0;
}

TList deleteAll(TList l1, const TList l2) {
    if (l1 == NULL || l2 == NULL) return l1;
    if (l1->elem < l2->elem) {
        l1->tail = deleteAll(l1->tail, l2);
        return l1;
    }
    if (l1->elem > l2->elem) return deleteAll(l1, l2->tail);
    TList aux = l1->tail;
    free(l1);
    return deleteAll(aux, l2->tail);
}