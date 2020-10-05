#ifndef HDR
#define HDR

#include <stdlib.h>

typedef struct nlist *listptr;

typedef struct nlist {
	listptr next;
	char *name;
	char *defn;
} slot;

typedef struct hashtable {
	size_t n_slots;
	listptr *slots;
} hashtable;

hashtable *init_table(size_t);
listptr lookup(hashtable *, char *);
listptr install (hashtable *, char *, char *);
void printtable(hashtable *, int );
int undef(hashtable *, char *);

#endif