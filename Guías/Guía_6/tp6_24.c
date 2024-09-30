#include <stdio.h>
#include <assert.h>
#include <string.h>

void
eliminaBlancos (char cadena[]);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}

void eliminaBlancos(char *string) {
    int dim = 0;
    for (int i = 0; string[i] != 0; i++) {
        if (string[i] != ' ' || string[i+1] != ' ') string[dim++] = string[i];
    }
    string[dim] = 0;
}