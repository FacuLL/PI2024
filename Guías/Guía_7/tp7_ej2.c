#include <stdio.h>
#include <math.h>

int convertir(const char *parametros, int numero);

int main(void) {
    printf("%d\n", convertir("<5>2", 42));
    printf("%d\n", convertir("<5>9", 42));
    return 0;
}

int convertir(const char *parametros, int numero) {
    int baseIn, baseOut;
    sscanf(parametros, "<%d>%d", &baseIn, &baseOut);
    int decimal = 0;
    for (int i = 0; numero != 0; i++) {
        decimal+=(numero%10)*pow(baseIn, i);
        numero/=10;
    }
    int res = 0;
    for (int i = 0; decimal > 0; i++) {
        res+=(decimal%baseOut)*pow(10, i);
        decimal/=baseOut;
    }
    return res;
}