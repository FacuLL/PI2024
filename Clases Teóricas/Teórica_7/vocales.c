#include <stdio.h>
#include <ctype.h>

int esVocal(char c) {
    char u = toupper(c);
    return (u == 'A' || u == 'E' || u == 'I' || u == 'O' || u == 'U');
}

int vocales(const char *s) {
    if (*s == 0) return 0;
    return esVocal(*s) + vocales(s+1);
}

int main(void) {
    char * s = "hola que tal";
    printf("%d vocales\n", vocales(s));
    return 0;
}