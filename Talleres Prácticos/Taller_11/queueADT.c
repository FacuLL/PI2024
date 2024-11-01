#include "./queueADT.h"
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    elementType value;
    struct node *next;
} tNode;

struct queueCDT {
    tNode *first;
    tNode *last;
    tNode *current;
};

queueADT newQueue(void) {
    return calloc(1, sizeof(struct queueCDT));
}

void freeQueue(queueADT queue) {
    if (queue->first == NULL) return free(queue);
    free(queue->first);
    queue->first = queue->first->next;
    freeQueue(queue);
}

void queue(queueADT queue, elementType elem) {
    tNode *nodo = malloc(sizeof(tNode));
    nodo->value = elem;
    nodo->next = NULL;
    if (queue->last != NULL) queue->last->next = nodo;
    else queue->first = nodo;
    queue->last = nodo;
}

void dequeue(queueADT queue, elementType *out) {
    assert(!isEmpty(queue));
    tNode *aux = queue->first->next;
    elementType toReturn = queue->first->value;
    free(queue->first);
    queue->first = aux;
    if (aux == NULL) queue->last = NULL;
    *out = toReturn;
}

int isEmpty(queueADT queue) {
    return queue->first == NULL;
}

void toBegin(queueADT queue) {
    queue->current = queue->first;
}

int hasNext(queueADT queue) {
    return queue->current != NULL;
}

elementType next(queueADT queue) {
    assert(hasNext(queue));
    elementType aux = queue->current->value;
    queue->current = queue->current->next;
    return aux;
}