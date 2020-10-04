#ifndef HDR
#define HDR

#include <stdlib.h>

typedef struct nlist *listptr;

typedef struct nlist {
	listptr next;
	char *name;
	char *defn;
} slot;

listptr * init_table();
listptr lookup(listptr *, char *);
listptr install (listptr *, char *, char *);
void printtable(listptr *, int );

#endif