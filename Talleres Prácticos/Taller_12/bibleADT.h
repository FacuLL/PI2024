#include <stdlib.h>

#ifndef bibleADT_h
#define bibleADT_h
    typedef struct bibleCDT *bibleADT;

    bibleADT newBible();
    int addVerse(bibleADT, size_t, size_t, const char *);
    char * getVerse(bibleADT, size_t, size_t);
    void freeBible(bibleADT);
#endif