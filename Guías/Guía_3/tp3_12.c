#include <stdio.h>

int main(void) {
    for (int i = 3; i <= 23; i+=5) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 20; i >= -10; i-=6) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}