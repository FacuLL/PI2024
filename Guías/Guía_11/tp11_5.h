#ifndef tp11_5_h
#define tp11_5_h

typedef struct complejoCDT *complejoADT;

complejoADT nuevoComp(double real, double imag);

double parteRealComp(complejoADT complejo);

double parteImagComp(complejoADT complejo);

complejoADT sumaComp(complejoADT complejo1, complejoADT complejo2);

complejoADT restaComp(complejoADT complejo1, complejoADT complejo2);

complejoADT multiplicaComp(complejoADT complejo1, complejoADT complejo2);

complejoADT divideComp(complejoADT complejo1, complejoADT complejo2);

complejoADT conjugadoComp(complejoADT complejo1);

void liberaComp(complejoADT complejo);

#endif