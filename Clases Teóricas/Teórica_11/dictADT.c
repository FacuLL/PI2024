#include "dictADT.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LETTERS ('z' - 'a' + 1)
#define WORDS_TO_INDEX(word) (tolower(word) - 'a')
#define BLOCK 10

typedef struct string {
    char * text;
    size_t length;
} string;

typedef struct dictNode {
    string word;
    string def;
    struct dictNode * tail;
} dictNode;

typedef dictNode * dictList;

typedef struct dictElem {
    dictList words;
    size_t wordCount;
} dictElem;

struct dictCDT {
    dictElem letters[LETTERS];
    size_t wordCount;
};

dictADT newDict(void) {
    return calloc(1, sizeof(struct dictCDT));
}

static char * concatenateToLongString(char * dest, char * s, size_t * dim) {
    while (*s != '\0') {
        if (*dim % BLOCK == 0)
            dest = realloc(dest, sizeof(char) * (*dim+BLOCK));
        dest[(*dim)++] = *(s++);
    }
    return dest;
}

static dictList addDefRec(dictList list, const char * word, const char * deff, int * wordAdded) {
    int cmp;
    if (list == NULL || (cmp = strcmp(word, list->word.text)) < 0) {
        dictList new = malloc(sizeof(dictNode));
        size_t len = strlen(word);
        new->word.length = len;
        new->word.text = malloc(len+1);
        strcpy(new->word.text, word);
        *wordAdded = 1;
        new->def.length = 0;
        new->def.text = concatenateToLongString(NULL, deff, &new->def.length);
        new->tail = list;
        return new;
    }
    if (cmp == 0) {
        list->def.text = concatenateToLongString(list->def.text, deff, &list->def.length);
        return list;
    }
    list->tail = addDefRec(list->tail, word, deff, wordAdded);
    return list;
}

void addDefinition(dictADT dict, const char * word, const char * deff) {
    size_t idx = WORDS_TO_INDEX(word[0]);
    int wordAdded = 0;
    dict->letters[idx].words = addDefRec(dict->letters[idx].words, word, deff, &wordAdded);
    dict->wordCount+=wordAdded;
    dict->letters[idx].wordCount+=wordAdded;
}

static dictList searchWord(const dictList list, const char * word) {
    int cmp;
    if (list == NULL || (cmp = strcmp(list->word.text, word) > 0)) return NULL;
    if (cmp == 0) return list;
    return searchWord(list->tail, word);
}

char * getDeff(const dictADT dict, const char * word) {
    size_t idx = WORDS_TO_INDEX(word[0]);
    dictList found = searchWord(dict->letters[idx].words, word);
    if (found == NULL) return NULL;
    char * toReturn = malloc((found->def.length)+1);
    for (size_t i = 0; i < found->def.length; i++) 
        toReturn[i] = found->def.text[i];
    toReturn[found->def.length] = '\0';
    return toReturn;
}

char ** wordsBeginWith(const dictADT dict, char letter, size_t * dim) {
    size_t idx = WORDS_TO_INDEX(letter);
    *dim = dict->letters[idx].wordCount;
    if (*dim == 0) return NULL;
    char ** toReturn = malloc(sizeof(char *) * *dim);
    dictList list = dict->letters[idx].words;
    for (size_t i = 0; list != NULL; i++, list = list->tail) {
        toReturn[i] = malloc(list->word.length+1);
        strcpy(toReturn[i], list->word.text);
    }
    return toReturn;
}

char ** words(const dictADT dict, size_t * dim) {
    *dim = 0;
    if (dict->wordCount == 0) return NULL;
    char ** toReturn = malloc(sizeof(char *) * dict->wordCount);
    for (size_t idx = 0; idx < LETTERS; idx++) {
        dictList list = dict->letters[idx].words;
        for (size_t i = 0; list != NULL; i++, list = list->tail) {
            toReturn[*dim] = malloc(list->word.length+1);
            strcpy(toReturn[(*dim)++], list->word.text);
        }
    }
    return toReturn;
}

static dictADT removeWordRec(dictList l, char * word, int * removed) {
    int cmp;
    if (l == NULL || (cmp = strcmp(l->word.text, word)) > 0) return l;
    if (cmp == 0) {
        dictList aux = l->tail;
        free(l->word.text);
        free(l->def.text);
        free(l);
        removed = 1;
        return aux;
    }
    l->tail = removeWordRec(l->tail, word, removed);
    return l;
}

void removeWord(dictADT dict, const char * word) {
    size_t idx = WORDS_TO_INDEX(word[0]);
    int removed = 0;
    dict->letters[idx].words = removeWordRec(dict->letters[idx].words, word, &removed);
    dict->letters[idx].wordCount-=removed;
    dict->wordCount-=removed;
}

static void freeDictRec(dictList l) {
    if (l == NULL) return;
    freeDictRec(l->tail);
    free(l->word.text);
    free(l->def.text);
    free(l);
}

void freeDict(dictADT dict) {
    for (size_t i = 0; i < LETTERS; i++)
        freeDictRec(dict->letters[i].words);
    free(dict);
}