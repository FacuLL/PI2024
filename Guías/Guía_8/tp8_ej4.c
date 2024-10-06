#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM_NAIPE 52
#define DIM_MANO 5

typedef struct {
    char valor;
    char palo;
} Carta;

typedef Carta Naipe[DIM_NAIPE];

void llenarNaipe(Naipe naipe);
void mezclarNaipe(Naipe naipe);
void swapCartas(Naipe naipe, int i, int j);
int randInt(int min, int max);
int checkWins(Naipe naipe);
void printWins(int wins);

void llenarNaipe(Naipe naipe) {
    static char valores[] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K'};
    static char palos[] = {'P', 'C', 'T', 'R'};
    int dim = 0;
    for (int i = 0; i < (sizeof(valores)/sizeof(valores[0])); i++) {
        for (int j = 0; j < (sizeof(palos)/sizeof(palos[0])); j++) {
            Carta carta = {.valor=valores[i],.palo=palos[j]};
            naipe[dim++] = carta;
        }
    }
}

void mezclarNaipe(Naipe naipe) {
    for (int i = 0; i < DIM_NAIPE; i++) {
        int random = randInt(0, DIM_NAIPE-1);
        swapCartas(naipe, i, random);
    }
}

void swapCartas(Naipe naipe, int i, int j) {
    Carta aux = naipe[j];
    naipe[j] = naipe[i];
    naipe[i] = aux;
}

int randInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

int checkWins(Naipe naipe) {
    int apariciones[255] = {0};
    for (int i = 0; i < DIM_MANO; i++) 
        apariciones[naipe[i].valor]++;
    for (int i = 0; i < DIM_MANO; i++) {
        if (apariciones[naipe[i].valor] > 1) return apariciones[naipe[i].valor];
    }
    return 0;
}

void printWins(int wins) {
    switch (wins) {
    case 2:
        puts("Se obtuvo PAR.");
        break;
    case 3:
        puts("Se obtuvo PIERNA.");
        break;
    case 4:
        puts("Se obtuvo POKER");
        break;
    default:
        puts("No se obtuvo nada.");
        break;
    }
}

void printNaipe(Naipe naipe) {
    for (int i = 0; i < DIM_NAIPE; i++) {
        printf("%c-%c ", naipe[i].palo, naipe[i].valor);
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    Naipe naipe;
    llenarNaipe(naipe);

    int res[5] = {0};
    for (int i = 0; i < 1000; i++) {
        mezclarNaipe(naipe);
        res[checkWins(naipe)]++;
    }
    int total = res[2]+res[3]+res[4];
    puts("RESULTADOS");
    printf("PAR %d - %f%%\n", res[2], (float) res[2]/total*100);
    printf("PIERNA %d - %f%%\n", res[3], (float) res[3]/total*100);
    printf("POKER %d - %f%%\n", res[4], (float) res[4]/total*100);
    return 0;
}