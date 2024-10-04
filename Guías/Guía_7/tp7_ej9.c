#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getnum.h>
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

int esta(int * v, int dim, int n) {
    for (int i = 0; i < dim; i++) {
        if (v[i] == n) return i;
    }
    return -1;
}

int jugar(TipoBolillero bolillero, int * dim, int n, TipoCarton * jugadores) {
    int * lineas = calloc(n, sizeof(int));
    int ganador;
    while ((ganador = esta(lineas, n, 1)) == -1) {
        int bolilla = sacarBolilla(bolillero, dim);
        for (int i = 0; i < n; i++)
            lineas[i]+=controlarCarton(jugadores[i], bolilla);
    }
    printf("El ganador de la primera linea es %d\n", ganador+1);
    for (int i = 0; i < n; i++) {
        printf("Carton jugador %d: \n", i+1);
        imprimirCarton(jugadores[i]);
    }
    while ((ganador = esta(lineas, n, ALTO)) == -1) {
        int bolilla = sacarBolilla(bolillero, dim);
        for (int i = 0; i < n; i++)
            lineas[i]+=controlarCarton(jugadores[i], bolilla);
    }
    free(lineas);
    return ganador;
}

int main(void) {
    srand(time(NULL));
    int dim;
    TipoBolillero bolillero = generarBolillero(&dim);
    int n;
    do {
        n = getint("Ingrese cant de jugadores: ");
    } while (n < 1);
    TipoCarton * jugadores = malloc(n*sizeof(TipoCarton));
    for (int i = 0; i < n; i++) {
        generarCarton(jugadores[i]);
        printf("Carton jugador %d: \n", i+1);
        imprimirCarton(jugadores[i]);
    }

    int res = jugar(bolillero, &dim, n, jugadores);
    printf("El ganador de es %d\n", res+1);
    for (int i = 0; i < n; i++) {
        printf("Carton jugador %d: \n", i+1);
        imprimirCarton(jugadores[i]);
    }
    free(jugadores);
    free(bolillero);
    return 0;
}

