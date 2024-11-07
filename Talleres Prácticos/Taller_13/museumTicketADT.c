#include "museumTicketADT.h"
#include "stdlib.h"
#include <strings.h>
#include <ctype.h>
#include <assert.h>
#define DAYS 366

typedef struct tTicket {
    char * visitor;
    struct tTicket * next;
} tTicket;

typedef tTicket * tTicketList;

typedef struct tDay {
    tTicketList tickets;
    tTicketList current;
    size_t amount;
} tDay;

struct museumTicketCDT {
    tDay days[DAYS];
    size_t total_amount;
};

static int strcmpNoSensitive(char * s1, char * s2) {
    while (*s1 != '\0' || *s2 != '\0') {
        int res =  tolower(*(s1++)) - tolower(*(s2++));
        if (res != 0) return res;
    }
}

museumTicketADT newMuseumTicket(void) {
    return calloc(1, sizeof(struct museumTicketCDT));
}

static tTicketList addTicketRec(tTicketList l, char * visitor, int * added) {
    int cmpRes;
    if (l == NULL || (cmpRes = strcmpNoSensitive(l->visitor, visitor)) > 0) {
        tTicketList new = malloc(sizeof(tTicket));
        new->next = l;
        new->visitor = visitor;
        *added = 1;
        return new;
    }
    if (cmpRes == 0) return l;
    l->next = addTicketRec(l->next, visitor, added);
    return l;
}

int addTicket(museumTicketADT m, size_t dayOfYear,  char * visitor) {
    if (dayOfYear == 0 || dayOfYear >= DAYS) return 0;
    tDay * day = &m->days[dayOfYear-1];
    int added = 0;
    day->tickets = addTicketRec(day->tickets, visitor, &added);
    day->amount+=added;
    m->total_amount+=added;
    return added ? day->amount : 0;
}

int dayTickets(const museumTicketADT m, size_t dayOfYear) {
    if (dayOfYear == 0 || dayOfYear >= DAYS) return -1;
    return m->days[dayOfYear-1].amount;
}

int yearTickets(const museumTicketADT m) {
    return m->total_amount;
}

void toBeginByDay(museumTicketADT m, size_t dayOfYear) {
    assert(dayOfYear != 0 && dayOfYear <= DAYS);
    m->days[dayOfYear-1].current = m->days[dayOfYear-1].tickets;
}

size_t hasNextByDay(museumTicketADT m, size_t dayOfYear) {
    assert(dayOfYear != 0 && dayOfYear <= DAYS);
    return m->days[dayOfYear-1].current != NULL;
}

char * nextByDay(museumTicketADT m, size_t dayOfYear) {
    assert(dayOfYear != 0 && dayOfYear <= DAYS);
    char * aux = m->days[dayOfYear-1].current->visitor;
    m->days[dayOfYear-1].current = m->days[dayOfYear-1].current->next;
    return aux;
}

void freeTickets(tTicketList l) {
    if (l == NULL) return;
    freeTickets(l->next);
    free(l);
}

void freeMuseumTicket(museumTicketADT m) {
    for (size_t i = 0; i < DAYS-1; i++) {
        freeTickets(m->days[i].tickets);
    }
    free(m);
}