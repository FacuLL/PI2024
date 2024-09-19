#include <stdio.h>
#include <getnum.h>
#include <ctype.h>

int elegirAccion(void);
int ingresarCaracter(void);

int main(void) {
    int eleccion = elegirAccion();
    int caracter = ingresarCaracter();
    int respuesta;

    switch (eleccion) {
    case 1:
        respuesta = tolower(caracter);
        break;
    case 2:
        respuesta = toupper(caracter);
        break;
    case 3: 
        respuesta = caracter + 1;
        break;
    default:
        respuesta = caracter == 'z' ? 'a' : caracter + 1;
        break;
    }

    printf("Respuesta: %c\n", respuesta);
    return 0;
}

int elegirAccion(void) {
    puts("1. Convertir de mayuscula a minuscula");
    puts("2. Convertir de minuscula a mayuscula");
    puts("3. Imprimir el caracter siguiente");
    puts("4. Imprimir la siguiente letra en forma circular");
    int eleccion;
    do {
        eleccion = getint("Elegí que queres hacer con el caracter: ");
    } while (eleccion < 1 || eleccion > 4);
    return eleccion;
}

int ingresarCaracter(void) {
    printf("Ingresa el caracter: ");
    return getchar();
}