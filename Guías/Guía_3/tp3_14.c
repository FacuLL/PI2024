#include <stdio.h>

int main(void) {
    int c, menor = 255, mayus = 0, minus = 0;
    while ((c=getchar()) != EOF && (c == ' ' || (c >= 'A' && c <= 'z'))) {
        if (c < menor && c != ' ') menor = c;
        if (c >= 'A' && c <= 'Z') mayus++;
        else if (c != ' ') minus++;
    }
    printf("Menor: %c Mayus: %d Minus: %d \n", menor, mayus, minus);
    return 0;
}