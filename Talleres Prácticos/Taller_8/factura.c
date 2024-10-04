#include <stdio.h>
#include <stdlib.h>
#include <getnum.h>
  
#define TOTAL_ITEMS 2
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];
 
void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
tItem leerItem(void);
 
int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}

float importe(tFactura fact, int cant) {
    float total = 0;
    for (int i = 0; i < cant; i++) total+=fact[i].precio;
    return total;
}

void cargar(tFactura fact, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Carga item %d/%d\n", i+1, cant);
        fact[i] = leerItem();
    }
}

tItem leerItem(void) {
    tItem item;
    item.codigo = getint("Ingrese el código: ");
    printf("Ingrese la descripción: ");
    fgets(item.desc, MAX_LONG, stdin);
    item.precio = getfloat("Ingrese el precio: ");
    return item;
}