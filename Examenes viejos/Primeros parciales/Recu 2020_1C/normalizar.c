#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

void normalizar(char *string) {
    int dim = 0;
    int decimales = 0;
    int contador = 0;
    for (int i = 0; string[i] != 0; i++) {
        if (string[i] == ',') contador = decimales = 0; 
        else if (string[i] == '.') decimales = 1;
        else if (decimales) contador++;

        if (!isdigit(string[i]) || contador <= 2) string[dim++] = string[i];
    }
    string[dim] = 0;
}

int main()
{
    char s[] = "12.33333,23.44444,1.0054,5.003,7.0";
    normalizar(s);
    assert(!strcmp(s, "12.33,23.44,1.00,5.00,7.0"));

    char t[] = "12.33,3.4,1.00,5.0,7.1";
    normalizar(t);
    assert(!strcmp(t, "12.33,3.4,1.00,5.0,7.1"));

    char y[] = "234.46789,400.3234,1015.2908,1.234,6000.4";
    normalizar(y);
    assert(!strcmp(y, "234.46,400.32,1015.29,1.23,6000.4"));

    puts("OK!");
}