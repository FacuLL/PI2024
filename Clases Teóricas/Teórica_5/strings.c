#include <stdio.h>

unsigned int strlen(const char * s);
char * strcpy(char * t, const char * s);
char * strncpy(char * t, const char * s, int n);
char * strcat(char * t, const char * s);
char * strncat(char * t, const char * s, int n);
int strcmp(const char * t, const char * s);
int strncmp(const char * t, const char * s, int n);
char * strchr(const char * s, char c);
char * strrchr(const char * s, char c);
char * strpbrk(const char * s, const char *set);
char * strstr(const char * t, const char * s);

int main(void) {
    

    return 0;
}

unsigned int strlen(const char * s) {
    int i = 0;
    while (s[i] != 0) i++;
    return i;
}

char * strcpy(char * t, const char * s) {
    int i = 0;
    while(s[i] != 0) {
        t[i] = s[i];
        i++;
    };
    t[i] = 0;
    return t;
}

char * strncpy(char * t, const char * s, int n) {
    int i = 0;
    while(s[i] != 0 && i < n) {
        t[i] = s[i];
        i++;
    }
    while(t[i] != 0) t[i++] = 0;
    return t;
}

char * strcat(char * t, const char * s) {
    while (*t != 0) t++;
    for (int i = 0; s[i] != 0; i++) t[i] = s[i];
    
}