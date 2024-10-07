#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6
#define DIM_DIRECCIONES 8
#define BLOQUE 5

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

typedef struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
} TPosicion;

TPosicion * resolverSopa(char *diccionario[], char sopa[][COLS]);

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.


int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL){
     printf("%s %d %d\n", res[count].palabra, (int) res[count].fila, (int) res[count].columna);
     count++;
    }
  assert(count == expected);

  assert(strcmp(res[1].palabra,"ARRE")==0);
  assert(res[1].fila==1);
  assert(res[1].columna==2);
  assert(res[1].direccion==D_AB);

  assert(strcmp(res[5].palabra,"ORCO")==0);
  assert(res[5].fila==3);
  assert(res[5].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[5].direccion==ARR);
  
  assert(strcmp(res[8].palabra,"ORCO")==0);
  assert(res[8].fila==4);
  assert(res[8].columna==3);
  assert(res[8].direccion==D_AR);

  assert(strcmp(res[7].palabra,"RIO")==0);
  assert(res[7].fila==4);
  assert(res[7].columna==1);
  assert(res[7].direccion==DER);
  free(res);
  puts("OK primera parte");
  
  char * diccionario2[] = {""};
  res = resolverSopa(diccionario2, sopa);
  // La cantidad de palabras encontradas debe ser 0
  expected = 0;
  count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);
  free(res); 
  puts("OK sin palabras encontradas");
  return 0;
}

int estaAfuera(int i, int j) {
    return i >= FILS || i < 0 || j >= COLS || j < 0;
}

int buscarPalabra(char sopa[][COLS], int i, int j, int dir, char *palabra) {
    static int incrementos[DIM_DIRECCIONES][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    for (int k = 0; palabra[k] != 0; k++) {
        if (estaAfuera(i, j) || palabra[k] != sopa[i][j]) return 0;
        i+=incrementos[dir][0];
        j+=incrementos[dir][1];
    }
    return 1;
}

TPosicion * agregarPosicion(TPosicion * posiciones, int *dim, TPosicion posicion) {
    TPosicion * aux = posiciones;
    if ((*dim)%BLOQUE == 0) {
        aux = realloc(posiciones, ((*dim)+BLOQUE+1)*sizeof(TPosicion));
        if (aux == NULL) return posiciones;
    }
    aux[(*dim)++] = posicion;
    return aux;
}

TPosicion * resolverSopa(char *diccionario[], char sopa[][COLS]) {
    static Tdireccion direcciones[] = {DER, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB};
    TPosicion * posiciones = NULL;
    int dim = 0;
    for (int i = 0; i < FILS; i++)
        for (int j = 0; j < COLS; j++)
            for (int x = 0; diccionario[x][0] != 0; x++) {
                if (sopa[i][j] == diccionario[x][0]) {
                    for (int k = 0; k < DIM_DIRECCIONES; k++) {
                        if (buscarPalabra(sopa, i, j, direcciones[k], diccionario[x])) {
                            TPosicion nueva = {.fila=i, .columna=j, .direccion=k, .palabra=diccionario[x]};
                            posiciones = agregarPosicion(posiciones, &dim, nueva);
                        }
                    }
                }
            }
    if (dim == 0) posiciones = malloc(sizeof(TPosicion));
    TPosicion final = {.palabra=NULL};  
    posiciones[dim++] = final;
    posiciones = realloc(posiciones, dim*sizeof(TPosicion));
    return posiciones;
}