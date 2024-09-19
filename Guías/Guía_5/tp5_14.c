#include <stdio.h>
#include <math.h>
#define MASK 0x000000FF
#define TOTAL_IP_BITS 32

#define IP 0x10FF1112
#define BITSNET 23

unsigned long getHostFromIp(unsigned long a, unsigned char b);
unsigned long getNetFromIp(unsigned long a, unsigned char b);
unsigned long createMask(unsigned char a, int b); 
void printIp(unsigned long a);

int main(void) {
    printIp(IP);
    printIp(getNetFromIp(IP, BITSNET));
    printIp(getHostFromIp(IP, BITSNET));
    return 0;
}

unsigned long getHostFromIp(unsigned long ip, unsigned char bitsNet) {
    return ip&createMask(bitsNet, 0);
}

unsigned long getNetFromIp(unsigned long ip, unsigned char bitsNet) {
    return ip&createMask(bitsNet, 1);
}

void printIp(unsigned long ip) {
    printf("%d.%d.%d.%d\n", 
        (char) (ip>>24)&MASK, 
        (char) (ip>>16)&MASK,
        (char) (ip>>8)&MASK,
        (char) ip&MASK 
    );
}

unsigned long createMask(unsigned char bitsNet, int inverted) {
    int start = inverted ? TOTAL_IP_BITS-bitsNet : 0;
    int end = inverted ? TOTAL_IP_BITS : TOTAL_IP_BITS-bitsNet;
    unsigned long mask = 0;
    for (int i = start; i < end; i++) {
        mask+=pow(2, i);
    }
    return mask;
}