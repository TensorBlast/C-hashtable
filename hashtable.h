#ifndef HDR
#define HDR

#include <stdlib.h>

typedef struct nlist *listptr;

typedef struct nlist {
	listptr next;
	char *name;
	char *defn;
} slot;

struct hashtable {
	size_t n_slots;
	listptr *slots;
};

struct hashtable *init_table(size_t);
listptr lookup(listptr *, char *);
listptr install (listptr *, char *, char *);
void printtable(listptr *, int );

#endif