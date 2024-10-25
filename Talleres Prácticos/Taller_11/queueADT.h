#ifndef queueADT_h
#define queueADT_h

// Editar el tipo segun conveniencia.
typedef int elementType;

typedef struct queueCDT *queueADT;

// Crea y devuelve una nueva cola.
queueADT newQueue(void);
// Libera el espacio de una cola existente.
void freeQueue(queueADT);
// Agrega un nuevo elemento al final de la cola.
void queue(queueADT, elementType);
// Devuelve, elimina y libera el primer elemento de la cola.
void dequeue(queueADT, elementType *out);
// Devuelve 1 si la cola esta vacia y 0 en caso contrario.
int isEmpty(queueADT);

#endif