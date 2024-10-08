#include <stdio.h>

int mcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return mcd(a%b, b);
    else return mcd(a, b%a);
}

int main(void) {
    printf("%d\n", mcd(13, 30));
    return 0;
}