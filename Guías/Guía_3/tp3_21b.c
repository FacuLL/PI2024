#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\\' || c == '\t' || c == '\b') putchar('\\');
        if (c == '\t') c = 't';
        else if (c == '\b') c = 'b';
        putchar(c);
    }
    return 0;
}