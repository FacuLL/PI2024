#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#define BLOCK 10

struct Node
{
    char elem;
    struct Node *tail;
};

typedef struct Node *tList;

tList strToListUpper(char *s);

char *listToString(tList l) {
    tList aux = l;
    char *s = NULL;
    int i = 0;
    while (aux != NULL)
    {
        if (i % BLOCK == 0)
            s = realloc(s, i + BLOCK);
        s[i] = aux->elem;
        aux = aux->tail;
        i++;
    }
    s = realloc(s, i + 1);
    s[i] = 0;
    return s;
}

void freeList(tList l) {
    if (l == NULL) return;
    freeList(l->tail);
    free(l);
}

int main()
{
    tList aux = strToListUpper("AbCdEfG");
    char *strList = listToString(aux);
    assert(!strcmp(strList, "ACEG"));
    freeList(aux);
    free(strList);

    aux = strToListUpper("");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper("Hoy vinimos a ver a Messi al MonumentaL");
    strList = listToString(aux);
    assert(!strcmp(strList, "HMML"));
    freeList(aux);
    free(strList);

    aux = strToListUpper("no va a quedar ninguna porque son todas minusculas");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper(NULL);
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper("solo van a quedar las siguientes letras ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strList = listToString(aux);
    assert(!strcmp(strList, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    freeList(aux);
    free(strList);

    puts("OK!");
}

tList strToListUpper(char *s) {
    if (s== NULL || *s == 0) return NULL;
    if (!isupper(*s)) return strToListUpper(s+1);
    tList nuevo = malloc(sizeof(struct Node));
    nuevo->elem = *s;
    nuevo->tail = strToListUpper(s+1);
    return nuevo;
}