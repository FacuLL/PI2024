#include <stdio.h>

void palotes(int cant) {
    if (cant == 0) return;
    printf("|");
    palotes(cant-1);
}

int strlen(char *s) {
    if (*s == 0) return 0;
    return 1 + strlen(s+1);
}

char * strchr(char *s, char c) {
    if (*s == c) return s;
    return strchr(s+1, c);
}

int main(void) {
    // Pruebas
    return 0;
}