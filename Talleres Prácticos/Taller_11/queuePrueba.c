// queueADT.c
#include <stdio.h>
#include <assert.h>
#include "./queueADT.h"
 
int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    toBegin(q);
    assert(next(q) == 3);
    assert(next(q) == 1);
    assert(!hasNext(q));
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    freeQueue(q);
    printf("OK!\n");
    return 0;
}