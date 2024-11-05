#include "boolMatADT.h"

typedef struct tCol {
    size_t nCol;
    char value;
    struct tCol * nextCol;
} tCol;

typedef tCol * ColList;

typedef struct tRow {
    size_t nRow;
    ColList cols;
    struct tRow * nextRow;
} tRow;

typedef tRow * RowList; 

typedef RowList boolMat;

struct boolMatCDT {
    boolMat matriz;
};

boolMatADT
newBoolMat(void) {
    return calloc(1, sizeof(struct boolMatCDT));
}

static tRow * searchRow(boolMat l,  size_t row) {
    if (l == NULL) return NULL;
    if (l->nRow == row) return l;
    return searchRow(l->nextRow, row);
}

static tCol * searchCol(ColList l, size_t col) {
    if (l == NULL) return NULL;
    if (l->nCol == col) return l;
    return searchCol(l->nextCol, col);
}

static ColList setColRec(ColList l, size_t col, boolean value) {
    if (l == NULL || col < l->nCol) {
        tCol * newCol = malloc(sizeof(tCol));
        newCol->nCol = col;
        newCol->value = value;
        newCol->nextCol = l;
        return newCol;
    }
    if (col == l->nCol) {
        l->value = value;
        return l;
    }
    l->nextCol = setColRec(l->nextCol, col, value);
    return l;
}

static RowList setRowRec(RowList l, size_t row, size_t col, boolean value) {
    if (l == NULL || row < l->nRow) {
        tRow * newRow = malloc(sizeof(tRow));
        newRow->nRow = row;
        newRow->nextRow = l;
        newRow->cols = setColRec(NULL, col, value);
        return newRow;
    } 
    if (row == l->nRow) {
        l->cols = setColRec(l->cols, col, value);
        return l;
    }
    l->nextRow = setRowRec(l->nextRow, row, col, value);
    return l;
}

void
setTrue(boolMatADT m, size_t row, size_t col) {
    m->matriz = setRowRec(m->matriz, row, col, true);
}

void
setFalse(boolMatADT m, size_t row, size_t col) {
    m->matriz = setRowRec(m->matriz, row, col, false);
}

boolean
getValue(const boolMatADT m, size_t row, size_t col) {
    tRow * foundRow = searchRow(m->matriz, row);
    if (foundRow == NULL) return false;
    tCol * foundCol = searchCol(foundRow->cols, col);
    if (foundCol == NULL) return false;
    return foundCol->value;
}

static void freeBoolMatColRec(ColList l) {
    if (l == NULL) return;
    freeBoolMatColRec(l->nextCol);
    free(l);
}

static void freeBoolMatRowRec(RowList l) {
    if (l == NULL) return;
    freeBoolMatRowRec(l->nextRow);
    freeBoolMatColRec(l->cols);
    free(l);
}

void
freeBoolMat(boolMatADT m) {
    freeBoolMatRowRec(m->matriz);
    free(m);
}

