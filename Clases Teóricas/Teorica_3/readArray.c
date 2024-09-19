#include <stdio.h>
#include "getnum.h"
#define DIM 50

int loadArray(float array[], int dimArray);
void readArray(const float array[], int dimArray);

int main(void) {
    float v[DIM];
    int dimRes = loadArray(v, DIM);
    readArray(v, dimRes);
    return 0;
}

int loadArray(float array[], int dimArray) {
    int stop = 0;
    int dimRes = 0;
    for (int i = 0; i < dimArray && !stop; i++){
        array[i] = getfloat("Ingrese un numero: ");
        if (array[i] != -1) dimRes++;
        else stop = 1;
    }
    return dimRes;
}

void readArray(const float array[], int dimArray) {
    printf("{ ");
    for (int i = 1; i <= dimArray; i++) {
        printf("%f", array[i-1]);
        if (i != dimArray) printf(", ");
    }
    printf(" }\n");
}