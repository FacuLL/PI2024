#include <stdio.h>

int main() {
    int num1, num2, num3;
    num1 = 1, num2 = 5, num3 = 3;
    int max = 
        num1>num2 && num1>num3 ? num1 :
        num2>num3 ? num2 :
        num3;
    printf("El numero mayor es: %d\n", max);
    return 0;   
}