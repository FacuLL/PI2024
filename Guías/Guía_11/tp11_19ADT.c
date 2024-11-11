#include "skipListADT.h"
#include <stdlib.h>
#include <assert.h>

typedef struct tNode {
	elemType elem;
	struct tNode ** tails;
	size_t tails_dim;
} tNode;

typedef tNode * tList;

struct skipListCDT {
	tList * levels;
	tList current;
	size_t max_level;
	compare cmp;
};

skipListADT createSkipList(unsigned char max_level, compare cmp) {
	skipListADT new = malloc(sizeof(skipListCDT));
	new->max_level = max_level;
	new->levels = calloc(sizeof(tNode)*(max_level+1));
	new->cmp = cmp;
	return new;
}

static int coin() {
	return rand() % 2;
}

tList insertRec(tList l, size_t level, elemType key, compare cmp) {
	int cmpRes;
	if (l->tails[level] == NULL || (cmpRes = cmp(key, l->tails[level]->elem)) < 0) {
		if (level > 0) {
			tList added = insertRec(l, key, level-1, cmp);
			if (added == NULL) return NULL;
			if (added->tails_dim == level && coin()) {
				added->tails = malloc(sizeof(tList) * (level + 1));
				added->tails[level] = l->tails[level];
				added->tails_dim++;
			}
			return added;
		}
		tList new = malloc(sizeof(tNode));
		new->elem = key;
		new->tails_dim = 1;
		new->tails = malloc(sizeof(tList));
		new->tails[0] = l->tails[0];
		l->tails[0] = new;
		return new;
	}
	if (cmpRes == 0) return NULL;
	return insertRec(l->tails[level], level, key, cmp);
}

void insert(skipListADT list, elemType key) {
	size_t level = list->max_level;
	insertRec(list->levels[level], level, key, list->cmp);
}

int searchRec(tList l, size_t level, elemType key, compare cmp) {
	int cmpRes;
	if (l->tails[level] == NULL || (cmpRes = cmp(key, l->tails[level]->elem)) < 0) {
		if (level > 0) return searchRec(l, level-1, key, cmp);
		return 0;
	}
	if (cmpRes == 0) return 1;
	return searchRec(l->tails[level], level, key, cmp);
}

int search(skipListADT list, elemType key) {
	size_t level = list->max_level;
	return searchRec(list->levels[level], level, key, list->cmp);
}

void toBegin(skipListADT list) {
	list->current = list->levels[0];
}

int hasNext(const skipListADT list) {
	return list->current != NULL;
}

elemType next(skipListADT list) {
	assert(hasNext(list);
	elemType aux = list->current->elem;
	list->current = list->current->tails[0];
	return aux;
}

void freeRec(tList l) {
	if (list == NULL) return;
	freeList(list->tails[0]);
	free(list->tails);
	free(list);
}

void freeList(skipListADT list) {
	freeRec(list->levels[0]);
	free(list);
}

void display(skipListADT list);