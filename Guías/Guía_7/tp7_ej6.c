#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DIGITOS 5
#define INTENTOS 4

void cpyinindex(char *t, const char *s, int index) {
    int dim = 0;
    for (int i = 0; s[i] != 0; i++) {
        t[index+(dim++)] = s[i];
    }
    t[index+dim] = 0;
}

int randInt(int min, int max) {
    return rand()%(max-min+1)+min;
}

void chooseNumber(char *t, char *digitos, int n) {
    for (int i = 0; i < n; i++) {
        int random = randInt(0, strlen(digitos)-1);
        t[i] = digitos[random];
        cpyinindex(digitos, digitos+(random+1), random);
    }
    t[n] = 0;
}

int esta(const char *s, char c) {
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    char digitos[10] = "123456789";
    char number[DIGITOS+1];
    chooseNumber(number, digitos, DIGITOS);
    for (int i = INTENTOS; i > 0; i--) {
        char respuesta[DIGITOS+1];
        printf("Ingrese prediccion: ");
        scanf("%s", respuesta);
        if (atoi(respuesta) == atoi(number)) {
            puts("Ganaste");
            return 0;
        }
        else {
            int correctos = 0;
            int regulares = 0;
            for (int j = 0; j < DIGITOS; j++) {
                if (number[j] == respuesta[j]) correctos++;
                else if (esta(number, respuesta[j])) regulares++;
            }
            printf("Incorrecto. Correctos: %d. Regulares: %d, Intentos restantes: %d\n", correctos, regulares, i);
        }
    }
    printf("Perdiste, el numero era: %s\n", number);
    return 0;
}