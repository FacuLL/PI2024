#ifndef list_h
#define list_h

struct node {
    int head;
    struct node * tail;
};

typedef struct node * tList;

// Retorna 1 si la lista no tiene nodos y 0 en caso contrario
int isEmpty(const tList l);

// Retorna la cantidad de nodos de una lista
size_t size(const tList l);

// Retorna 1 si se encuentra el elemento en la lista y 0 en caso contrario (Requiere lista ordenada ascendentemente)
int belongs(const tList l, int elem);

// Agrega un nodo con el elemento donde corresponde con orden ascendente (Requiere lista ordenada ascendentemente)
tList add(tList l, int elem);

// Libera el espacio de todos los nodos de una lista
void freeList(tList l);

// Retorna la cabeza del elemento
int head(tList l);

// Retorna la cola del elemento
tList tail(tList l);

// Elimina un elemento de la lista y libera su espacio (Requiere lista ordenada ascendentemente)
tList delete(tList l, int elem);

// Convierte una lista a arreglo
int * toArray(tList l, size_t * dim);

int getElemAtIndex(const tList l, int inx);

#endif