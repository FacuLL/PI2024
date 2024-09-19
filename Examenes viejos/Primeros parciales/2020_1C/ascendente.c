#include <stdio.h>
#define FILS 4
#define COLS 5

int main(void) {
    
    return 0;
}

int esAscendente(const int m[][COLS]) {
    int esAsc = 1;
    int esDesc = 1;
    for (int i = 0; i < FILS && (esAsc+esDesc) != 0; i++) {
        for (int j = 0; j < COLS-1 && (esAsc+esDesc) != 0; j++) {
            if (m[i][j] > m[i][j+1]) esAsc = 0;
            else if (m[i][j] < m[i][j+1]) esDesc = 0;
        }
        if (m[i][COLS-1] > m[i+1][0]) esAsc = 0;
        else if (m[i][COLS-1] < m[i][0]) esDesc = 0;
    }
    return esAsc ? 1 : esDesc ? -1: 0;
}