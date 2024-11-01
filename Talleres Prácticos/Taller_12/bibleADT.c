#include "bibleADT.h"
#include <string.h>
#define LIBROS 76
#define BLOCK 10

typedef struct TBook {
    char ** versicles;
    size_t size;
} TBook;

struct bibleCDT {
    TBook *books[LIBROS];
};

bibleADT newBible() {
    return calloc(1, sizeof(struct bibleCDT));
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse) {
    if (bible->books[bookNbr] == NULL) 
        bible->books[bookNbr] = calloc(1, sizeof(TBook));
    TBook *book = bible->books[bookNbr];
    if (book->size < verseNbr) {
        book->versicles = realloc(book->versicles, sizeof(char *) * (verseNbr+1));
        while(book->size < verseNbr+1) book->versicles[book->size++] = 0;
    }
    if (book->versicles[verseNbr] != NULL) return 0;
    int verseSize = strlen(verse);
    book->versicles[verseNbr] = realloc(book->versicles[verseNbr], sizeof(char) * (verseSize+1));
    strcpy(book->versicles[verseNbr], verse);
    return 1;
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr) {
    if (bible->books[bookNbr] == NULL || 
        bible->books[bookNbr]->size < verseNbr ||
        bible->books[bookNbr]->versicles[verseNbr] == NULL) return NULL;
    char * verse = bible->books[bookNbr]->versicles[verseNbr];
    char * copy = NULL;
    int dim = 0;
    while (*verse != '\0') {
        if (dim % BLOCK == 0)
            copy = realloc(copy, (dim+BLOCK));
        copy[dim++] = *(verse++);
    }
    copy = realloc(copy, (dim+1));
    copy[dim++] = '\0';
    return copy;
}

void freeBible(bibleADT bible) {
    for (size_t i = 0; i < LIBROS-1; i++) {
        if (bible->books[i] != NULL) {
            for (int j = 0; j < bible->books[i]->size; j++) {
                if (bible->books[i]->versicles[j] != NULL) free(bible->books[i]->versicles[j]);
            }
            free(bible->books[i]->versicles);
            free(bible->books[i]);
        }
    }
    free(bible);
}