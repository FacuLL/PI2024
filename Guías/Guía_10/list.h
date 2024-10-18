#ifndef list_h
#define list_h

struct node {
    int elem;
    struct node * tail;
};

typedef struct node * TList;

// Retorna 1 si la lista no tiene nodos y 0 en caso contrario
int isEmpty(const TList l);

// Retorna la cantidad de nodos de una lista
size_t size(const TList l);

// Retorna 1 si se encuentra el elemento en la lista y 0 en caso contrario (Requiere lista ordenada ascendentemente)
int belongs(const TList l, int elem);

// Agrega un nodo con el elemento donde corresponde con orden ascendente (Requiere lista ordenada ascendentemente)
TList add(TList l, int elem);

// Libera el espacio de todos los nodos de una lista
void freeList(TList l);

// Retorna la cabeza del elemento
int head(TList l);

// Retorna la cola del elemento
TList tail(TList l);

// Elimina un elemento de la lista y libera su espacio (Requiere lista ordenada ascendentemente)
TList delete(TList l, int elem);

// Convierte una lista a arreglo
int * toArray(TList l, size_t * dim);

int getElemAtIndex(const TList l, int inx);

#endif