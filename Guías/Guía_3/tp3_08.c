#include <stdio.h>

/* imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300 */

int main(void)
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* límite inferior de la tabla de temperaturas */
    upper = 300;  /* límite superior */
    step = 20;    /* tamaño del incremento */

    fahr = upper;
    printf("FAHR\tCELSIUS\n");
    while (fahr > lower) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr - step;
    }
    return 0;
}