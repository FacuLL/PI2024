#include "random.h"

#include <stdlib.h>
#include <time.h>

double
randNormalize() {
    return rand() / ( (double) RAND_MAX + 1);
}

int
randInt(int left, int right) {
    return (int) (randNormalize() * (right - left + 1)) + left;
}

double 
randReal(double left, double right) {
    return randNormalize() * (right - left) + left;
}

void
randomize() {
    srand(time(NULL));
    rand();
}