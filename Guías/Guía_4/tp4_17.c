#include <stdio.h>
#include <getnum.h>

#define ELAPSED(h1, m1, h2, m2) { \
    ((h2) * 60 + (m2) - (h1) * 60 - (m1) >= 0 ? \
    (h2) * 60 + (m2) - (h1) * 60 - (m1) : \
    (h1) * 60 + (m1) - (h2) * 60 - (m2) ) \
}

int main(void) {
    
    return 0;
}