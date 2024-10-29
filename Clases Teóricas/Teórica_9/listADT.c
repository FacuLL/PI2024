#include "listADT.h"
#include <stdlib.h>
#include <assert.h>
#define BLOQUE 3

struct node {
    elemType head;
    struct node *tail;
};

typedef struct node *tList;

struct listCDT {
    tList list;
    tList current;
    int elemCount;
    cmp cmpFun;  
};

listADT newList(cmp cmpFun) {
    listADT list = malloc(sizeof(struct listCDT));
    list->elemCount = 0;
    list->list = NULL;
    list->cmpFun = cmpFun;
    return list;
}

static tList addRec(tList list, elemType elem, cmp cmpFun, int *added) {
    int result;
    if (list == NULL || (result = cmpFun(list->head, elem)) > 0) {
        tList new = malloc(sizeof(struct node));
        new->head = elem;
        new->tail = list;
        *added = 1;
        return new;
    }
    if (result == 0) return list;
    list->tail = addRec(list->tail, elem, cmpFun, added);
    return list;
}

int add(listADT list, elemType elem) {
    int added = 0;
    list->list = addRec(list->list, elem, list->cmpFun, &added);
    list->elemCount+=added;
    return added;
}

int elemCount(const listADT l) {
    return l->elemCount;
}

int isEmpty(const listADT l) {
    return l->list == NULL;
}

static int belongsRec(tList list, elemType elem, cmp cmpFun) {
    int result;
    if (list == NULL || (result = cmpFun(list->head, elem)) > 0) return 0;
    if (result == 0) return 1;
    return belongsRec(list->tail, elem, cmpFun);
}

int belongs(const listADT list, elemType elem) {
    return belongsRec(list->list, elem, list->cmpFun);
}

static void freeRec(tList list) {
    if (list == NULL) return;
    freeRec(list->tail);
    free(list);
}

void freeList(listADT l) {
    freeRec(l->list);
    free(l);
}

elemType * toArray(const listADT l) {
    elemType *array = malloc(sizeof(elemType) * l->elemCount);
    tList list = l->list;
    for(int i = 0; i < l->elemCount; i++, list=list->tail)
        array[i] = list->head;
    return array;
}

elemType * select(const listADT l, int (*criteria) (char *), int *dimRes) {
    elemType *array = NULL;
    *dimRes = 0;
    tList list = l->list;
    for(int i = 0; i < l->elemCount; i++, list=list->tail)
        if (criteria(list->head)) {
            if (*dimRes % BLOQUE == 0)
                array = realloc(array, sizeof(elemType) * (*dimRes+BLOQUE));
            array[(*dimRes)++] = list->head;
        }
    if (*dimRes != 0)
        array = realloc(array, sizeof(elemType) * (*dimRes));
    return array;
}

static tList deleteElemRec(tList list, elemType elem, cmp cmpFun) {
    int result = cmpFun(list->head, elem);
    if (list == NULL || result > 0) return list;
    if (result == 0) {
        tList aux = list->tail;
        free(list);
        return aux;
    }
    list->tail = deleteElemRec(list->tail, elem, cmpFun);
    return list;
}

void deleteElem(listADT list, elemType elem) {
    deleteElemRec(list->list, elem, list->cmpFun);
    list->elemCount--;
}

static tList getElemAtIndexRec(tList list, int idx) {
    if (idx == 0) return list;
    return getElemAtIndexRec(list->tail, idx-1);
}

elemType getElemAtIndex(const listADT l, int idx) {
    assert(idx >= 0 && l->elemCount > idx);
    return getElemAtIndexRec(l->list, idx)->head;
}

void toBegin(listADT l) {
    l->current = l->list;
}

int hasNext(listADT l) {
    return l->current != NULL;
}

elemType next(listADT l) {
    elemType aux = l->current->head;
    l->current = l->current->tail;
    return aux;
}