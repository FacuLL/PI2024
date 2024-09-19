#include <stdio.h>

int main(void) {
    
    return 0;
}

void dondeEsta(int arreglo[], int size, int numero) {
    for (int i = 0; i < size; i++) {
        if (arreglo[i] != numero) arreglo[i] = 0;
    }
}