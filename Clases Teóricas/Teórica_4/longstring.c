#include <stdio.h>

int longString(const char *string);

int main(void) {
    printf("%d", longString("Holaaodfkqw"));
    return 0;
}

int longString(const char *string) {
    int contador = 0;
    while (*string != '\0') {
        string++;
        contador++;
    }
    return contador;
}