#include "stackADT.h"
#include <stdlib.h>
#define BLOQUE 5

typedef struct stackCDT {
    int * elems;
    int dim;
} stackCDT;

stackADT newStack() {
    stackADT stack = calloc(1, sizeof(stackCDT));
    return stack;
}

void freeStack(stackADT stack) {
    free(stack->elems);
    free(stack);
}

int isEmpty(const stackADT stack) {
    return stack->dim == 0;
}

void push(stackADT stack, int elem) {
    if (stack->dim % BLOQUE == 0) 
        stack->elems = realloc(stack->elems, sizeof(int) * (stack->dim + BLOQUE));
    stack->elems[stack->dim++] = elem;
}

int pop(stackADT stack) {
    int elem = stack->elems[stack->dim-1];
    stack->dim--;
    if (stack->dim % BLOQUE == 0) 
        stack->elems = realloc(stack->elems, sizeof(int) * (stack->dim + BLOQUE));
    return elem;
}

int peek(const stackADT stack) {
    return stack->elems[stack->dim-1];
}