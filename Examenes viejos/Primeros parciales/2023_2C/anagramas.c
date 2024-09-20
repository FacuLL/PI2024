#include <stdio.h>
#include <assert.h>

int anagrama(const char s1[], const char s2[]) {
    int letras[52] = {0};
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != ' ') letras[s1[i]-'a']++;
    }
    for (int i = 0; s2[i]; i++) {
        if (s2[i] != ' ') letras[s2[i]-'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (letras[i] != 0) return 0;
    }
    return 1;
}

int main(void) {
    char * s = "anagrama";

    assert(anagrama(s, "amar gana"));
    assert(anagrama("Enrique", "quierEn"));
    assert(anagrama(s, s));
    assert(anagrama("         ", ""));
    assert(anagrama("amar gana", s));
    assert(anagrama("", ""));
    assert(anagrama("a gentleman", "elegant man"));

    assert(anagrama("a", "") == 0);
    assert(anagrama("mar", "amar") == 0);
    puts("OK!");
    return 0;
}