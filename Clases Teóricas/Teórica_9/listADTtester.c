// listADT.c
#include <stdio.h>
#include "listADT.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int cmpFun(char * s1, char * s2) {
    return strcmp(s1, s2);
}

int hasFourLettersOrMore(char *s) {
    for (int i = 0; i<4; i++) {
        if (s[i] == 0) return 0;
    }
    return 1;
}

int compareArray(char ** a1, int dim1, char ** a2, int dim2) {
    if (dim1 != dim2) return 0;
    for (int i = 0; i < dim1; i++) {
        if (cmpFun(a1[i], a2[i]) != 0) return 0;
    }
    return 1;
}

int main(void) {
    listADT l = newList(cmpFun);
    assert(isEmpty(l) == 1);
    assert(belongs(l, "hola") == 0);
    add(l, "hola");
    assert(elemCount(l) == 1);
    add(l, "chau");
    add(l, "tobias");
    assert(elemCount(l) == 3);
    deleteElem(l, "tobias");
    assert(elemCount(l) == 2);
    assert(belongs(l, "hola") == 1);
    assert(belongs(l, "hasta luego") == 0);
    assert(isEmpty(l) == 0);

    char * expected[2] = {"chau", "hola"};

    // Opcion 1: Recorrer con arreglo (Ineficiente, duplica elementos).
    char ** result = toArray(l);
    assert(compareArray(expected, sizeof(expected) / sizeof(expected[0]), result, elemCount(l)) == 1);
    free(result);

    // Opcion 2: Recorrer con getElemAtIndex (Ineficiente, recorre de mas).
    for (int i = 0; i < elemCount(l); i++)
        assert(cmpFun(getElemAtIndex(l, i), expected[i]) == 0);

    // Opcion 3: Recorrer con iteradores (Eficiente).
    toBegin(l);
    for (int i = 0; hasNext(l); i++)
        assert(cmpFun(next(l), expected[i]) == 0);

    add(l, "asd");
    add(l, "hasta pronto");
    add(l, "tobias");
    add(l, "estoy programando en c aaa");

    char * expected2[] = {"chau", "estoy programando en c aaa", "hasta pronto", "hola", "tobias"};
    int dim = 0;
    result = select(l, hasFourLettersOrMore, &dim);
    assert(dim == 5);
    assert(compareArray(expected2, sizeof(expected2) / sizeof(expected2[0]), result, dim) == 1);
    free(result);

    freeList(l);
    puts("OK!");
    return 0;
}