#include <stdio.h>
#include <getnum.h>

int main(void) {
    float numero = getfloat("Ingresa un numero con coma: ");
    int entero = 0, decimal = 0;
    for (int i = numero; i > 0; i/=10) {
        if (i%10==5) entero++;
    }
    for (float i = numero; i > 0; i*=10) {
        i = i - (int) i;
        if ((int) (i*10) == 5) decimal++;
    }
    
    printf("El numero %.5f tiene %d cincos en la parte entera y %d en la decimal\n", numero, entero, decimal);
    
    return 0;
}