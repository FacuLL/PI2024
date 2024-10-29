#include "tp11_5.h"
#include <stdlib.h>

struct complejoCDT {
    double real;
    double imag;
};

complejoADT nuevoComp(double real, double imag) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = real;
    complejo->imag = imag;
    return complejo;
}

double parteRealComp(complejoADT complejo) {
    return complejo->real;
}

double parteImagComp(complejoADT complejo) {
    return complejo->imag;
}

complejoADT sumaComp(complejoADT complejo1, complejoADT complejo2) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = complejo1->real + complejo2->real;
    complejo->imag = complejo1->imag + complejo2->imag;
    return complejo;
}

complejoADT restaComp(complejoADT complejo1, complejoADT complejo2) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = complejo1->real - complejo2->real;
    complejo->imag = complejo1->imag - complejo2->imag;
    return complejo;
}

complejoADT multiplicaComp(complejoADT complejo1, complejoADT complejo2) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = complejo1->real * complejo2->real + (complejo1->imag * complejo2->imag)*-1;
    complejo->imag = complejo1->imag * complejo2->real + complejo2->imag * complejo1->real;
    return complejo;
}

complejoADT divideComp(complejoADT complejo1, complejoADT complejo2) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = (complejo1->real * complejo2->real + complejo1->imag * complejo2->imag) / (complejo2->real * complejo2->real + complejo2->imag * complejo2->imag);
    complejo->imag = (complejo1->imag * complejo2->real - complejo2->imag * complejo1->real) / (complejo2->real * complejo2->real + complejo2->imag * complejo2->imag);
    return complejo;
}

complejoADT conjugadoComp(complejoADT complejo1) {
    complejoADT complejo = malloc(sizeof(struct complejoCDT));
    complejo->real = complejo1->real;
    complejo->imag = -complejo1->imag;
    return complejo;
}

void liberaComp(complejoADT complejo) {
    free(complejo);
}

