#include <stdio.h>

int main(void) {
    int c, deleteNext = 0;
    while((c=getchar()) != EOF) {
        if (c!=' ' || !deleteNext) putchar(c);
        if (c==' ') deleteNext = 1;
        else deleteNext = 0;
    }   
    return 0;
}