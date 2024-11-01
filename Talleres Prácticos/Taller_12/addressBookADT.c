#include "addressBookADT.h"
#include <stdlib.h> 
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define BLOCK 5

typedef struct tContactNode {
    tContact contact;
    struct tContactNode * next;
} tContactNode;

typedef struct tGroup {
    char * name;
    tContact * contacts;
    size_t size;
    struct tGroup * next;
} tGroup;

struct addressBookCDT {
    tGroup * groups;
    size_t size;
    tGroup * currentGroup;
    tContactNode * currentContact;
};

static int nonSensitiveStrcmp(char * s1, char *s2) {
    while (*s1 != '\0' || *s2 != '\0') {
        int cmp = tolower(*(s1++)) - tolower(*(s2++));
        if (cmp != 0) return cmp;
    }
    return 0;
}

addressBookADT newAddressBook() {
    return calloc(1, sizeof(struct addressBookCDT));
}

static tGroup *addGroupRec(tGroup *list, char * groupName, int * result) {
    int cmpRes;
    if (list == NULL || (cmpRes = nonSensitiveStrcmp(list->name, groupName)) > 0) {
        tGroup *new = malloc(sizeof(tGroup));
        new->name = groupName;
        new->next = list;
        new->size = 0;
        new->contacts = NULL;
        *result = 1;
        return new;
    }
    if (cmpRes == 0) return list;
    list->next = addGroupRec(list->next, groupName, result);
    return list;
}

int addGroup(addressBookADT book, const char * groupName) {
    int result = 0;
    book->groups = addGroupRec(book->groups, groupName, &result);
    book->size++;
    return result;
}

static tGroup * searchGroup(tGroup * list, const char * groupName) {
    int cmpRes;
    if (list == NULL || (cmpRes = nonSensitiveStrcmp(list->name, groupName)) > 0) return NULL;
    if (cmpRes == 0) return list;
    return searchGroup(list->next, groupName);
}

static tContactNode * addContactRec(tContactNode * list, tContact contact, int * result) {
    int cmpRes;
    if (list == NULL || (cmpRes = nonSensitiveStrcmp(list->contact.name, contact.name)) > 0) {
        tContactNode *new = malloc(sizeof(tGroup));
        new->contact = contact;
        new->next = list;
        *result = 1;
        return new;
    }
    if (cmpRes == 0) return list;
    list->next = addContactRec(list->next, contact, result);
    return list;
}

int addContact(addressBookADT book, const char * groupName, tContact contact) {
    tGroup * group = searchGroup(book->groups, groupName);
    if (group == NULL) return 0;
    int result = 0;
    group->contacts = addContactRec(group->contacts, contact, &result);
    group->size++;
    return result;
}

void toBeginForGroup(addressBookADT book, const char * groupName) {
    tGroup * group = searchGroup(book->groups, groupName);
    if (group == NULL) return;
    book->currentContact = group->contacts;
}

int hasNextForGroup(addressBookADT book) {
    return book->currentContact != NULL;
}

/* Retorna un contacto, aborta si no hay siguiente */
tContact nextForGroup(addressBookADT book) {
    assert(hasNextForGroup(book));
    tContact contact = book->currentContact->contact;
    book->currentContact = book->currentContact->next;
    return contact;
}

void toBegin(addressBookADT book) {
    book->currentGroup = book->groups;
}

int hasNext(addressBookADT book) {
    return book->currentGroup != NULL;
}

char * next(addressBookADT book) {
    assert(hasNext(book));
    char * name = book->currentGroup->name;
    char * copy = NULL;
    size_t dim = 0;
    while (*name != '\0') {
        if (dim % BLOCK == 0)
            copy = realloc(copy, sizeof(char) * (dim+BLOCK));
        copy[dim++] = *(name++);
    }
    copy = realloc(copy, sizeof(char) * (dim+1));
    copy[dim++] = '\0';
    book->currentGroup = book->currentGroup->next;
    return copy;
}

