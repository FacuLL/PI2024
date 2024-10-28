#ifndef stackADT_h
#define stackADT_h

typedef struct stackCDT *stackADT;

// Crea y devuelve un nuevo stack
stackADT newStack(void);

// Libera el espacio del stack
void freeStack(stackADT stack);

// Devuelve 1 si el stack esta vacio y 0 si no
int isEmpty(const stackADT stack);

// Agrega un elemento en el tope del stack
void push(stackADT stack, int elem);

// Elimina y devuelve el último elemento agregado al stack
int pop(stackADT stack);

// Devuelve el último elemento agregado al stack, sin modificarlo
int peek(const stackADT stack);

#endif