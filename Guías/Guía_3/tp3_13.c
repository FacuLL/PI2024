#include <stdio.h>

int main(void) {
    int largo = 5;
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 1; i < largo*largo+1; i++)
    {
        printf("*");
        if (i%largo == 0) printf("\n");
    }
    
    
    return 0;
}