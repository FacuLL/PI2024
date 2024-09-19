#include <stdio.h>
#include <string.h>

char* toUpperCase(char* text) {
    int len = sizeof(text);
    int distance = "A" - "a";
    for (int i = 0; i < len; i++) {
        text[i] = text[i] + distance;
    }
    return text;
}

int main() {
    printf("%s\n", toUpperCase("hola"));
    return 0;
}