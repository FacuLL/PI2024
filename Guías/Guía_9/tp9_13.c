#include <stdio.h>
#include <string.h>
#include <assert.h>

char * strrchrRec(const char *s, char c);

int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
	} 
	
	assert(NULL == strrchrRec(s, 'x'));
	
	// También tiene que dar NULL para el valor 0
	assert(NULL == strrchrRec(s, '\0'));

	puts("OK!");
}

char * strrchrRec(const char *s, char c) {
    if (*s == NULL) return NULL;
    char * aux = strrchrRec(s+1, c);
    if (aux) return aux;
    if (*s == c) return s;
    return NULL;
}