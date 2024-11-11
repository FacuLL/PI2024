#include <stdlib.h>
#include "matrixADT.h"

typedef struct tRow {
    elementType ** cols;
    size_t dim;
} tRow;

struct matrixCDT {
    tRow * rows;
    size_t dim;
};

matrixADT newMatrix() {
    return calloc(1, sizeof(struct matrixCDT));
}

int setElement(matrixADT m, size_t row, size_t col, elementType elem) {
    if (m->dim <= row) {
        m->rows = realloc(m->rows, sizeof(tRow) * (row+1));
        for (size_t i = m->dim; i < row+1; i++) {
            m->rows[i].dim = 0;
            m->rows[i].cols = NULL;
        }
        m->dim = row + 1;
    }
    if (m->rows[row].dim <= col) {
        m->rows[row].cols = realloc(m->rows[row].cols, sizeof(elementType*) * (col+1));
        for (size_t i = m->rows[row].dim; i < col+1; i++) 
            m->rows[row].cols[i] = NULL;
        m->rows[row].dim = col + 1;
    }
    if (m->rows[row].cols[col] == NULL) m->rows[row].cols[col] = malloc(sizeof(elementType));
    *m->rows[row].cols[col] = elem;
    return 1;
}

int getElement(matrixADT m, size_t row, size_t col, elementType * out) {
    if (row < 0 || row >= m->dim) return 0;
    if (col < 0 || col >= m->rows[row].dim) return 0;
    if (m->rows[row].cols[col] == NULL) return 0;
    *out = *m->rows[row].cols[col];
    return 1;
}

size_t rows(matrixADT m) {
    return m->dim;
}

void freeMatrix(matrixADT m) {
    for (size_t i = 0; i < m->dim; i++) {
        for (size_t j = 0; j < m->rows[i].dim; j++) {
            if (m->rows[i].cols[j] != NULL) free(m->rows[i].cols[j]);
        }
        free (m->rows[i].cols);
    }
    free(m->rows);
    free(m);
}