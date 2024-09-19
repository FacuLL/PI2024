#include <assert.h>
#include <stdio.h>


void unirArreglos ( const int ar1[], const int ar2[], int resultado[]);
void imprimir (const int arreglo[]);


void check(const int v1[], const int v2[]) {
	printf("Se espera: ");
  imprimir(v1);
  printf("Se dio: ");
  imprimir(v2);
  int i;
  for(i=0; v1[i] != -1; i++)
    assert(v1[i]==v2[i]);
  assert(v1[i]==-1);
  assert(v2[i]==-1);
}

int main(void) {
  int v1[] = { 1, 5, 15, 30, 35, 45, 55, -1};
  int v2[] = {-1};
  int v3[] = { 1, -1};
  int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
  int res[30];

  unirArreglos(v1, v2, res);
  check(v1, res);

  unirArreglos(v2, v2, res);
  check(v2, res);

  unirArreglos(v1, v1, res);
  check(v1, res);

  unirArreglos(v1, v3, res);
  check(v1, res);

  int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
  unirArreglos(v1, v4, res);
  check(expected, res);

  printf("OK!\n");
  return 0;
}

void unirArreglos ( const int ar1[], const int ar2[], int resultado[]) {
  int i = 0;
  int j = 0;
  int dimRes = 0;
  while (ar1[i] != -1 || ar2[j] != -1) {
      if (ar1[i] != -1) resultado[dimRes++] = ar1[i];
      while(ar2[j] != -1 && (ar2[j]<ar1[i] || ar1[i] == -1)) {
          resultado[dimRes++] = ar2[j++];
      }
			if (ar2[j] != -1) j++;
      if (ar1[i] != -1) i++;
  }
  resultado[dimRes] = -1;
}

void interseccion( const int ar1[], const int ar2[], int resultado[]) {
    int i1 = 0;
    int i2 = 0;
    int dimRes = 0;
    while (ar1[i1] != -1 && ar2[i2] != -1) {
        if (ar1[i1] > ar2[i2]) i2++;
        else if (ar1[i1] < ar2[i2]) i1++;
        else {
            resultado[dimRes] = ar1[i1];
            dimRes++;
            i1++;
        }
    }
}

void imprimir(const int arreglo[]) {
    printf("{ ");
    for (int i = 0; arreglo[i] != -1; i++) {
        printf("%d, ", arreglo[i]);
    }
    printf(" }\n");
}