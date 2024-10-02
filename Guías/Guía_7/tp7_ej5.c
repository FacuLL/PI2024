#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 4

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

typedef char * TAlumnos [MAX_ALUMNOS];
typedef char TCurso [MAX_ALUMNOS];

void separaCursos(TAlumnos, TCurso, TAlumnos, TAlumnos);

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

void separaCursos(TAlumnos alumnos, TCurso curso, TAlumnos cursoG, TAlumnos cursoH) {
    int dimH = 0;
    int dimG = 0;
    int i = 0;
    for (; alumnos[i][0] != 0; i++) {
        if (curso[i] == 'H') cursoH[dimH++] = alumnos[i];
        if (curso[i] == 'G') cursoG[dimG++] = alumnos[i];
    }
    cursoH[dimH] = alumnos[i];
    cursoG[dimG] = alumnos[i];
}