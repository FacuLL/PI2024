#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MASK 0x0F

/* Calcula la desviacion estandar */

double desv(const unsigned char arreglo[], int dim ) {
    if (dim <= 0) return 0;
    int suma = 0;
    for (int i = 0; i < dim; i++) {
        suma += ((arreglo[i/2]>>(((i+1)%2)*4))&MASK);
    }
    double promedio = ((double) suma) / dim;
    double sumaCuadrados = 0;
    for (int i = 0; i < dim; i++) {
        sumaCuadrados+=pow(((arreglo[i/2]>>(((i+1)%2)*4))&MASK)-promedio, 2);
    }
    return sqrt(sumaCuadrados/dim);
}

int main(void) {
  unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
  for(int i=0; i <= 10; i++)
    assert(desv(arreglo2, i)==0);
  

  unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
  assert(desv(arreglo, 1)==0);
  assert(desv(arreglo, 2)==2.0);

  assert(desv(arreglo, 3) > 4.98 && desv(arreglo, 3) < 4.99);

  assert(desv(arreglo, 10) > 5.6071 && desv(arreglo, 3) < 5.6072);

  puts("OK!");
}