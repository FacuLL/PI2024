#include <stdio.h>

void regla(int mayor) {
    if (mayor == 0) return;
    regla(mayor/2);
    printf("%d", mayor);
    regla(mayor/2);
}

int main(void) {
    regla(8);
    return 0;
}