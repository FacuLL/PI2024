#include <stdio.h>

int branches(int altura, int minima) {
    if (altura <= minima) return 1;
    return 2 * branches(altura/2, minima)+1;
}

int main(void) {
    printf("%d\n", branches(8, 1));
    return 0;
}