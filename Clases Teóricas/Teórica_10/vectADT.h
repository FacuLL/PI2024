#include <stdlib.h>

#ifndef vectADT_h
#define vectADT_h

typedef int elemType;

typedef struct vectCDT *vectADT;
typedef int (*cmp) (elemType, elemType);

// Crea y devuelve un nuevo vector
vectADT newVector(void);
// Devuelve la cantidad de elementos de un vector
int elemCount(vectADT);
// Devuelve 1 si pudo obtenerlo y 0 si no. Deja en parametro el resultado.
int getElem(vectADT, size_t, elemType*);

int removeElem(vectADT, size_t);

int putElem(vectADT, size_t, elemType);

void freeVect(vectADT);


#endif