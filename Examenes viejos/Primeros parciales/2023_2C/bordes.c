#include <stdio.h>
#include <assert.h>
#define M 5

void bordes(const int m[][M], int sumas[]) {
    for (int i = 0; i < M/2; i++) {
        int suma = 0;
        for (int j = i; j < M-i; j++) {
            suma+=m[i][j];
            if (i!=j) suma+=m[j][i];
        }
        sumas[i] = suma;
    }
}

int main(void) {
    int m[M][M] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int sumas[M/2];
    bordes(m, sumas);
    assert(sumas[0] == 25+24+23+22+21+16+11+6+5+4+3+2+1+10+15+20);
    assert(sumas[1] == 7+8+9+14+19+18+17+12);
    assert(sumas[2] == 13);
    puts("OK!");


    return 0;
}