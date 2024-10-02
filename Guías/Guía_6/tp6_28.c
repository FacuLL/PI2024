#include <stdio.h>
#include <assert.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5


int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  printf("%s\n", s);
  // assert(strcmp(s, "ls bnas deas escasean, si")==0);
  // assert(m[0][0]==-1);
  // assert(m[0][1]==-1);
  // assert(m[0][2]==-1);
  // assert(m[0][3]==-1);
  // assert(m[0][4]==-1);

  // assert(elimVocales(s, m, 5)==ERROR);
  // assert(strcmp(s, "ls bns ds scsan, s")==0);
  // assert(m[0][0] == 1);
  // assert(m[1][0] == 8);
  // assert(m[2][0] == 14);
  // assert(m[3][0] == 20);
  // assert(m[4][0] == -1);
  
  // assert(m[0][1] == 6);
  // assert(m[1][1] == 13);
  // assert(m[2][1] == 17);
  // assert(m[3][1] == 22);
  // assert(m[4][1] == -1);

  // assert(m[0][2] == 11);
  // assert(m[1][2] == 28);
  // assert(m[2][2] == -1);

  // assert(m[0][3] == -1);

  // assert(m[0][4] == 5);
  // assert(m[1][4] == -1);

  // printf("OK!\n");
  return 0;
}

int posicionVocal(char vocal) {
  switch (vocal) {
  case 'a':
    return 0;
    break;
  case 'e':
    return 1;
    break;
  case 'i':
    return 2;
    break;
  case 'o':
    return 3;
    break;
  case 'u':
    return 4;
    break;
  default:
    return -1;
    break;
  }
}

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n) {
  int dim = 0;
  int error = 0;
  int cantidades[CANT_VOCAL] = {0};
  for (int i = 0; s[i] != 0; i++) {
    int posicion = posicionVocal(s[i]);
    if (posicion == -1) s[dim++] = s[i];
    else if (cantidades[posicion] >= n) {
      error = 1;
      s[dim++] = s[i];
    }
    else m[cantidades[posicion]++][posicion] = i;
  }
  for (int i = 0; i < CANT_VOCAL; i++) {
    if (cantidades[i] >= n) {
      error = 1;
      s[dim++] = s[i];
    }
    m[cantidades[i]][i] = -1;
  }
  s[dim] = 0;
  return !error;
}