#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define radios 100

typedef struct {
    int x;
    int y;
} Coord;

int randInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

int randDir() {
    static int dirs[] = {-1, 1};
    int random = randInt(0, 1);
    return dirs[random];
}

int calculo(int radio) {
    int tiempo = 0;
    Coord punto = {.x=0, .y=0};
    do {
        punto.x+=randDir();
        punto.y+=randDir();
        tiempo++;
    } while (punto.x + punto.y < radio);
    return tiempo;
}

int main(void) {
    srand(time(NULL));
    printf("RADIO\tTIEMPO\tRELACION\n");
    int tiempo;
    for (int i = 0; i < radios; i++) {
        tiempo = calculo(i);
        printf("%d\t%d\t%f\n", i, tiempo, (float)i/tiempo);
    }
    return 0;
}