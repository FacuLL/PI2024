#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1

int normalizar(const char *s, char *t);

int main(void) {
  char s[100];

  assert(normalizar("1.1.1", s)==0);
  assert(normalizar("a", s)==0);
  assert(normalizar("1.a11", s)==0);
  assert(normalizar("1-1", s)==0);

  assert(normalizar("1", s));
  assert(strcmp(s, "1E+00")==0);
  assert(normalizar("0012", s));
  assert(strcmp(s, "1.2E+01")==0);

  assert(normalizar("145.720", s));
  assert(strcmp(s, "1.4572E+02")==0);
  assert(normalizar("134597", s));
  
  assert(strcmp(s, "1.34597E+05")==0);

  assert(normalizar("0.34", s));
  printf("%s\n", s);
  // assert(strcmp(s, "3.4E-01")==0);
  // assert(normalizar("0.00200", s));
  // assert(strcmp(s, "2E-03")==0);
  // assert(normalizar("987654321011", s));
  // assert(strcmp(s, "9.87654321011E+11")==0);

  puts("OK");
  return 0;
}

int isAnotherDigitAfter(const char *s, int pos) {
  for (int i = pos+1; s[i] != 0; i++) {
    if (isdigit(s[i]) && s[i] != '0') return 1;
  }
  return 0;
}

int normalizar(const char *s, char *t) {
  int dim = 0;
  int digitDim = 0;
  int start = -1;
  int point = -1;
  for (int i = 0; s[i] != 0; i++) {
    if (isdigit(s[i]) && s[i] != '0') {
      t[dim++] = s[i];
      digitDim++;
      if (start == -1) {
        start = i;
        if (isAnotherDigitAfter(s, i)) t[dim++] = '.';
      }
    }
    else if (s[i] == '0') {
      if (start != -1 && isAnotherDigitAfter(s, i)) {
        t[dim++] = '0';
        digitDim++;
      }
    }
    else if (s[i] == '.') {
      if (point != -1) return ERROR;
      point = i;
    }
    else return ERROR;
  }
  int offset;
  if (start == -1) offset = 0;
  else if (point == -1) {
    offset = digitDim - 1;
    printf("%d\n", digitDim);
  }
  else offset = point-start;
  t[dim++] = 'E';
  if (offset >= 0) t[dim++] = '+';
  else t[dim++] = '-';
  char number[3];
  sprintf(number, "%2.2d", abs(offset));
  t[dim] = 0;
  strcat(t, number);
  t[dim+2] = 0;
  return SUCCESS;
}