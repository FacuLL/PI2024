#include <stdio.h>

int main(void) {
    unsigned char var, var1, var2, var3, var4;
    var = 0xD8;
    var1 = (var>>6)&3;
    var2 = (var>>4)&3;
    var3 = (var>>2)&3;
    var4 = var&3;
    printf("La variable var1 tiene el valor: %d\n", var1);
    printf("La variable var2 tiene el valor: %d\n", var2);
    printf("La variable var3 tiene el valor: %d\n", var3);
    printf("La variable var4 tiene el valor: %d\n", var4);
    return 0;
}