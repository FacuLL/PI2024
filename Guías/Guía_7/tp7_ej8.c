#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMEROS 90
#define ANCHO 5
#define ALTO 3

typedef int TipoLinea[ANCHO];
typedef TipoLinea TipoCarton[ALTO]; 
typedef int * TipoBolillero;

int * generarBolillero(int *dimension) {
    int * bolillero = malloc(NUMEROS * sizeof(int));
    for (int i = 1; i <= NUMEROS; i++) {
        bolillero[i-1] = i;
    }
    *dimension = NUMEROS;
    return bolillero;
}

int randInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

int sacarBolilla(TipoBolillero bolillero, int * dim) {
    int random = randInt(0, (*dim)-1);
    int bolilla = bolillero[random];
    for (int i = random; i < (*dim)-1; i++) {
        bolillero[i] = bolillero[i+1];
    }
    (*dim)--;
    return bolilla;
}

void generarCarton(TipoCarton carton) {
    int dim;
    TipoBolillero posibilidades = generarBolillero(&dim);
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++){
            carton[i][j] = sacarBolilla(posibilidades, &dim);
            // posibilidades = realloc(posibilidades, dim);
        }
    }
    free(posibilidades);
}

int controlarLinea(TipoCarton carton, int linea) {
    for (int i = 0; i < ANCHO; i++){
        if (carton[linea][i] != 0) return 0;
    }
    return 1;
}

int controlarCarton(TipoCarton carton, int bolilla) {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            if (carton[i][j] == bolilla) {
                carton[i][j] = 0;
                if (controlarLinea(carton, i)) return 1;
                return 0;
            }
        }
    }
    return 0;
}

void imprimirCarton(TipoCarton carton) {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            printf("%2d ", carton[i][j]);
        }
        printf("\n");
    }
}

int jugar(TipoBolillero bolillero, int * dim, TipoCarton jugador1, TipoCarton jugador2) {
    int lineas1 = 0;
    int lineas2 = 0;
    while (lineas1 != 1 && lineas2 != 1) {
        int bolilla = sacarBolilla(bolillero, dim);
        lineas1+=controlarCarton(jugador1, bolilla);
        lineas2+=controlarCarton(jugador2, bolilla);
    }
    printf("El ganador de la primera linea es %d\n", (lineas2 == 1)+1);
    puts("Carton jugador 1:");
    imprimirCarton(jugador1);
    puts("Carton jugador 2:");
    imprimirCarton(jugador2);
    while (lineas1 < ALTO && lineas2 < ALTO) {
        int bolilla = sacarBolilla(bolillero, dim);
        lineas1+=controlarCarton(jugador1, bolilla);
        lineas2+=controlarCarton(jugador2, bolilla);
    }
    return (lineas1 == ALTO) + (lineas2 == ALTO) * 2;
}

int main(void) {
    srand(time(NULL));
    int dim;
    TipoBolillero bolillero = generarBolillero(&dim);
    TipoCarton jugador1, jugador2;
    generarCarton(jugador1);
    generarCarton(jugador2);
    puts("Carton jugador 1:");
    imprimirCarton(jugador1);
    puts("Carton jugador 2:");
    imprimirCarton(jugador2);
    int res = jugar(bolillero, &dim, jugador1, jugador2);
    printf("El ganador de es %d\n", res);
    puts("Carton jugador 1:");
    imprimirCarton(jugador1);
    puts("Carton jugador 2:");
    imprimirCarton(jugador2);
    free(bolillero);
    return 0;
}

