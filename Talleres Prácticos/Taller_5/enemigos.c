#include <stdio.h>
#include <assert.h>
#include <math.h> 
#include <stdlib.h>
 
#define FILAS 7
#define COLS 6
 
#define ERROR (-1)
 
int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y);
 
int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
 
 
    printf("OK!\n");
    return 0;
}

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y) {
    int direccionMaxima = -1;
    int encontrado = 1;
    static int incrementosX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    static int incrementosY[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int radio = 1; encontrado; radio++) {
        encontrado = 0;
        for (int direccion = 0; direccion < 8; direccion++) {
            int moveX = x+incrementosX[direccion]*radio;
            int moveY = y+incrementosY[direccion]*radio;
            if (moveX >= 0 && moveX < alto && moveY >= 0 && moveY < ancho && mat[moveX][moveY] != '1' && mat[moveX][moveY] != 'X') {
                direccionMaxima = direccion;
                encontrado = 1;
            }
        }
    }
    printf("%d ", direccionMaxima*45);
    return direccionMaxima*45;
}