#ifndef listADT_h
#define listADT_H

typedef char* elemType;

typedef struct listCDT * listADT;

typedef int (*cmp) (elemType, elemType);

// Crea y retorna una nueva lista. Recibe la funcion de comparación entre dos elementos.
listADT newList(cmp);

// Agrega un elemento. Devuelve 1 si se logro y 0 si no.
int add(listADT, elemType);

// Elimina un elemento de la lista.
void deleteElem(listADT, elemType);

// Devuelve un arreglo copia de la lista.
elemType * toArray(const listADT);

elemType * select(const listADT, int (*) (char *), int *);

// Retorna la dimension de la lista.
int elemCount(const listADT);

// Retorna 1 si esta vacia y 0 en caso contrario.
int isEmpty(const listADT);

// Retorna 1 si el elemento se encuentra y 0 si no.
int belongs(const listADT, elemType);

// Obtiene el elemento de cierto indice.
elemType getElemAtIndex(const listADT, int);

// Libera la memoria de una lista.
void freeList(listADT);

// ITERADORES
// Inicializa lo necesario para comenzar a iterar.
void toBegin(listADT l);
// Devuelve 1 si hay elementos por recorrer y 0 en caso contrario
int hasNext(const listADT l);
// Devuelve el siguiente elemento y avanza el iterador.
elemType next(listADT l);

#endif