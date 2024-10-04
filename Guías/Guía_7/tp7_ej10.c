#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_PALABRA 20
#define INTENTOS 5

#define BORRA_BUFFER while (getchar() != '\n')

int getInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

char *elegirPalabra(void) {
    static char * palabras[] = {"manzana", "botella", "computadora", "plato", "correr", "salsa"};
    int random = getInt(0, sizeof(palabras)/sizeof(palabras[0]));
    return palabras[random];
}

int contarLetra(char *palabra, char *resultado, char letra) {
    int count = 0;
    for (int i = 0; palabra[i] != 0; i++) {
        if (palabra[i] == letra) {
            resultado[i] = letra;
            count++;
        };
    }
    return count;
}

void cargarHint(char *hint, char *palabra) {
    for (int i = 0; palabra[i] != 0; i++) {
        hint[i] = '_';
    }
}

int main(void) {
    srand(time(NULL));
    char * palabra = elegirPalabra();
    int intentos = INTENTOS;
    char hint[MAX_PALABRA];
    cargarHint(hint, palabra);
    char respuesta;
    do {
        printf("%s\n", hint);
        printf("Te quedan %d intentos. Ingrese una respuesta: ", intentos);
        respuesta = getchar();
        BORRA_BUFFER;
        if (!contarLetra(palabra, hint, respuesta)) {
            intentos--;
        }
    } while (intentos > 0 && strcmp(hint, palabra) != 0);
    if (intentos == 0) printf("Perdiste, la palabra era %s.\n", palabra);
    else printf("Ganaste, felicitaciones\n");
    return 0;
}