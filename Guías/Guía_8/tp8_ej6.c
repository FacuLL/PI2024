#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIVISION 100000
#define BLOQUE 5
#define EPSILON 0.0001
#define FUNCION(x) (x)*(x)-1

typedef struct {
    double inicio;
    double fin;
} Intervalo;

typedef struct {
    int cantidad;
    Intervalo *intervalos;
} Raices;

Raices agregarRaiz(Raices raices, Intervalo intervalo) {
    if (raices.cantidad%BLOQUE == 0) 
        raices.intervalos = realloc(raices.intervalos, (raices.cantidad+BLOQUE)*sizeof(Intervalo));
    raices.intervalos[raices.cantidad++] = intervalo;
    return raices;
}

Raices calcularRaices(Intervalo intervalo) {
    Raices raices = {.cantidad = 0, .intervalos = NULL};
    double paso = (intervalo.fin - intervalo.inicio) / DIVISION;
    int recorriendoRaiz = 0;
    Intervalo raizRecorrida;
    for (double i = intervalo.inicio; i < intervalo.fin-paso; i+=paso) {
        double valor = FUNCION(i);
        double valorSiguiente = FUNCION(i+paso);
        if (!recorriendoRaiz) {
            if (fabs(valor) <= EPSILON) {
                raizRecorrida.inicio = i;
                recorriendoRaiz = 1;
            }
            else if(valor*valorSiguiente < 0 && fabs(valorSiguiente) >= EPSILON) {
                Intervalo raiz = {.inicio=i, .fin=i+paso};
                raices = agregarRaiz(raices, raiz);
            }
        }
        else {
            if (fabs(valor) > EPSILON) {
                raizRecorrida.fin = i-paso;
                raices = agregarRaiz(raices, raizRecorrida);
                recorriendoRaiz = 0;
            }
        }
    }
    raices.intervalos = realloc(raices.intervalos, raices.cantidad*sizeof(Intervalo));
    return raices;
}

int main(void) {
    Intervalo intervalo = {.inicio=-5, .fin = 5};
    Raices raices = calcularRaices(intervalo);
    printf("Cantidad de raices: %d\n", raices.cantidad);
    for (int i = 0; i < raices.cantidad; i++) {
        printf("Raiz %d: entre %f y %f\n", i+1, raices.intervalos[i].inicio, raices.intervalos[i].fin);
    }
    
    return 0;
}