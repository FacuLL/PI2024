#include <stdio.h>

size_t potenciaEntera(size_t base, size_t exponente) {
    if (exponente == 0) return 1;
    return base * potenciaEntera(base, exponente-1);
}

int main(void) {
    printf("%d", potenciaEntera(10, 9));
    return 0;
}