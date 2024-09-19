#include <stdio.h>
#include <getnum.h>

int main(void) {
    int segundos = getint("Ingrese los segundos: ");
    printf("%d segundos\n", segundos);
    printf("%d minutos\n", segundos/60);
    printf("%d horas\n", segundos/60/60);
    return 0;
}