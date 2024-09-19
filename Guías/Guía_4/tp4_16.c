#include <stdio.h>
#define DIVISOR(a,b) b != 0 ? a % b == 0 : 0

int main(void) {
    printf("%d", DIVISOR(-10, 3));
    return 0;
}