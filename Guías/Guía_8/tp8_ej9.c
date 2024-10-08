#include <stddef.h>
#include <stdio.h>

#define myoffsetof()

typedef struct {
    int campo1;
    char campo2;
    char campo3;
    int campo4;
    long campo5;
    char campo6[4];
    int campo7;
    int campo8;
} TPrueba;

int main(void) {
    printf("%d\n", offsetof(TPrueba, campo1));
    printf("%d\n", offsetof(TPrueba, campo2));
    printf("%d\n", offsetof(TPrueba, campo3));
    printf("%d\n", offsetof(TPrueba, campo4));
    printf("%d\n", offsetof(TPrueba, campo5));
    printf("%d\n", offsetof(TPrueba, campo6));
    printf("%d\n", offsetof(TPrueba, campo7));
    printf("%d\n", offsetof(TPrueba, campo8));
    return 0;
}