#include <stdio.h>
#include <string.h>

int capicua(const char *start, const char *end) {
    if (start > end) return 1;
    if (*start != *end) return 0;
    return capicua(start+1, end-1);
}

int esCapicua(const char *s) {
    int dim = strlen(s);
    return capicua(s, s+dim-1);
}

int main(void) {
    char *s = "hola que tal";
    char *s2 = "neuquen";
    printf("%d %d\n", esCapicua(s), esCapicua(s2));
    return 0;
}