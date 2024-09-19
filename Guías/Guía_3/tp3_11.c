#include <stdio.h>

int main(void) {
    printf("N\t10*N\t100*N\t1000*N\n");
    for (int i = 1; i <= 20; i++) {
        printf("%d\t%d\t%d\t%d\n", i, i*10, i*100, i*1000);
    }
    return 0;
}