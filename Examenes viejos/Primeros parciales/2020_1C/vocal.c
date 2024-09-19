#include <stdio.h>
#define ES_VOCAL(c) { ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')  }
#define TO_LOWER(c) { (c += (c > 'A' && c < 'Z') ?  'a' - 'A' : 0) }

int main(void) {
    return 0;
}