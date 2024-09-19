#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001
#include <assert.h>

double maximaDiferencia(const double a[]);

double maximaDiferencia(const double arreglo[]) {
    double maximo = 0;
    for (int i = 1; arreglo[i] != 0; i++) {
        double diferencia = fabs(arreglo[i] - arreglo [i-1]);
        if (diferencia > maximo) maximo = diferencia;
    }
    return maximo;
}

int main(void) {

  double v[] = {1.0, 0.0};
  assert(fabs(maximaDiferencia(v))==0.0);

  double v2[] = {1.0, 1.0, 1.0, 0.0};
  assert(fabs(maximaDiferencia(v2))==0.0);

  double v3[] = {1.5, 3.0, -1.0, 0.0};
  assert(fabs(maximaDiferencia(v3) - 4.0) < EPSILON);

  double v4[] = {1.5, 3.0, 4.5, 3.0, 0.0};
  assert(fabs(maximaDiferencia(v4) -1.5) < EPSILON);

  double v5[] = {2.5, 1.0, 1.5, 2.0, 0.0};
  assert(fabs(maximaDiferencia(v5)- 1.5) < EPSILON );

  double v6[] = {1.5,  -1.0, 3.0, 0.0};
  assert(fabs(maximaDiferencia(v6) - 4.0) < EPSILON);

  puts("OK!");
  return 0;
}