#include <stdio.h>
#include <getnum.h>

int main(void) {
    int original = getint("Ingresa un numero entero: ");
    int final = 0;
    for (int i = original; i > 0; i/=10) {
        final+=i%10;
        final*=10;
    }
    printf("El numero %ses capicua\n", (final/10)!=original ? "no ": "");
    return 0;
}