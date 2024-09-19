#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

void elimina1(char *string) {
    int dim = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isspace(string[i]) || (string[i+1] != '\0' && isalpha(string[i+1])) || (i != 0 && isalpha(string[i-1])))
            string[dim++] = string[i];
    }
    string[dim] = '\0';
}

int main()
{
    char s[] = "Ahora escribimos un texto";
    elimina1(s); // el string no cambia;
    assert(!strcmp(s, "Ahora escribimos un texto"));

    char t[] = "a B C  d"; // 2 espacios entre 'C' y 'd'
    elimina1(t);           // t queda "    " (4 espacios)
    assert(!strcmp(t, "    "));

    char u[] = "ahora y siempre";
    elimina1(u); // u queda "ahora  siempre"
                 // (dos espacios entre ahora y siempre)
    assert(!strcmp(u, "ahora  siempre"));

    char w[] = "";
    elimina1(w); // w no cambia
    assert(!strcmp(w, ""));

    char z[] = "                    ";
    elimina1(z); // z no cambia
    assert(!strcmp(z, "                    "));

    char y[] = "Quiero que esta funcion funcione o funcione   a   e   i   o   u";
    elimina1(y);
    assert(!strcmp(y, "Quiero que esta funcion funcione  funcione               "));

    puts("OK!");
}