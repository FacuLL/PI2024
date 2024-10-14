#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01

double raizNR(double, int, double);

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

double raizNR(double last, int iter, double x) {
    if (iter == 0) return last;
    return raizNR((last+x/last)/2, iter-1, x);
}
