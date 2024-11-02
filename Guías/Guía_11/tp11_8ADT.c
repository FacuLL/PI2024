#include "tp11_8.h"
#include "listADT.h"
#include <stdlib.h>

typedef struct setCDT {
    listADT list;
    size_t size;
    cmp cmpFun;
} setCDT;

setADT newSet(cmp cmp) {
    setADT set = malloc(sizeof(setCDT));
    set->cmpFun = cmp;
    set->list = newList(cmp);
    set->size = 0;
    return set;
}

int addElement(setADT set, elemType elem) {
    int res = add(set->list, elem);
    set->size+=res;
    return res;
}

int deleteElement(setADT set, elemType elem) {
    int res = delete(set->list, elem);
    set->size-=res;
    return res;
}

int setContains(setADT set, elemType elem) {
    return belongs(set->list, elem);
}

int isEmptySet(setADT set) {
    return isEmpty(set->list);
}

int sizeSet(setADT set) {
    return set->size;
}

setADT unionSet(setADT set1, setADT set2) {
    if (set1->cmpFun != set2->cmpFun) return NULL;
    setADT res = newSet(set1->cmpFun);
    toBegin(set1->list);
    toBegin(set2->list);
    int has1, has2;
    while ((has1 = hasNext(set1->list)) || (has2 = hasNext(set2->list))) {
        if (!has1) addElement(res, next(set2->list));
        else addElement(res, next(set1->list));
    }
    return res;
}

setADT intersectionSet(setADT set1, setADT set2) {
    if (set1->cmpFun != set2->cmpFun) return NULL;
    setADT res = newSet(set1->cmpFun);
    toBegin(set1->list);
    toBegin(set2->list);
    if (!hasNext(set1->list) || !hasNext(set2->list)) return res; 
    elemType last1 = next(set1->list);
    elemType last2 = next(set2->list);
    while (hasNext(set1->list) && hasNext(set2->list)) {
        int cmpRes;
        if ((cmpRes = res->cmpFun(last1, last2)) < 0) last1 = next(set1->list);
        else if (cmpRes > 0) last2 = next(set2->list);
        else {
            addElement(res, last1);
            last1 = next(set1->list);
            last2 = next(set2->list);
        }
    }
    if (res->cmpFun(last1, last2) == 0) addElement(res, last1);
    return res;
}

setADT diffSet(setADT set1, setADT set2) {
    if (set1->cmpFun != set2->cmpFun) return NULL;
    setADT res = newSet(set1->cmpFun);
    toBegin(set1->list);
    toBegin(set2->list);
    if (!hasNext(set1->list)) return res;
    elemType last1 = next(set1->list);
    elemType last2;
    if (hasNext(set2->list)) last2 = next(set2->list);
    while(hasNext(set1->list)) {
        int cmpRes = res->cmpFun(last2, last1);
        if (!hasNext(set2->list) || cmpRes > 0) {
            addElement(res, last1);
            last1 = next(set1->list);
        }
        else if (cmpRes < 0 && hasNext(set2->list)) last2 = next(set2->list);
        else {
            last1 = next(set1->list);
            if (hasNext(set2->list)) last2 = next(set2->list);
        }
    }
    if (!hasNext(set2->list) || res->cmpFun(last2, last1) > 0) addElement(res, last1);
    return res;
}

void freeSet(setADT set) {
    freeList(set->list);
    free(set);
}