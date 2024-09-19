#include <stdio.h>
#include <assert.h>
#include "random.h"
#define DIM 30


int
shuffle(int v[], unsigned int dim);

int main(void) {
  int v[DIM];
  randomize();

  for(int i=0; i<DIM; i++) {
	  v[i] = -10 + i*2;
  }
  shuffle(v,DIM);

  puts("Vamos a imprimir el vector, debería estar desordenado");
  for(int i=0; i<DIM; i++) {
	  printf("%03d\t", v[i]);
  }
  putchar('\n');

  int aux=v[0];
  puts("A continuación desordeamos un vector vacío, no debería fallar");
  shuffle(v,0);
  assert(v[0]==aux);

  puts("OK!");

  return 0;
}


int shuffle(int array[], unsigned int length) {
    int auxiliar;
    for (int i = 0; i < length; i++) {
        int posicionAleatoria = randInt(0, length-1);
        if (posicionAleatoria != i) {
            auxiliar = array[posicionAleatoria];
            array[posicionAleatoria] = array[i];
            array[i] = auxiliar;
        }
    }
    return length;
}