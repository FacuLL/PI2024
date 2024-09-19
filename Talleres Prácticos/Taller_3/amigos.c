#include <stdio.h>
#include <getnum.h>
#include <math.h>

int numerosAmigos(int, int);
int sumaDivisores(int);

int main(void) {
    int numero1 = getint("Ingrese el numero 1: ");
    int numero2 = getint("Ingrese el numero 2: ");
    printf("Los numeros %d y %d %s números amigos\n", numero1, numero2, numerosAmigos(numero1, numero2) ? "son" : "no son");
    return 0;
}

int numerosAmigos(int num1, int num2) {
    return sumaDivisores(num1) == num2 && sumaDivisores(num2) == num1;
}

int sumaDivisores(int num) {
    int suma = 1;
    double limite = sqrt(num);
    for (int i = 2; i <= limite; i++) {
        if (num % i == 0) suma += i + num/i;
    }
    return suma;
}