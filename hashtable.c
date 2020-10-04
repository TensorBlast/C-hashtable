#include <stdio.h>
#include <string.h>
#include "hashtable.h"

#define HASHSIZE 101


listptr * init_table()
{
	listptr *hashtab = (listptr *) calloc(HASHSIZE, sizeof(*hashtab));
	return hashtab;
}

unsigned hash (char *s)
{
	unsigned hashval;

	for (hashval=0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

listptr lookup (listptr * hashtab, char *s)
{
	listptr np;

	for (np = hashtab[hash(s)]; np!=NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

listptr install(listptr * hashtab, char *name, char * defn)
{
	listptr np;

	unsigned hashval;

	if((np = lookup(hashtab, name)) == NULL) {
		np = (listptr) malloc(sizeof(*np));
		if (np==NULL || (np->name = strdup(name))==NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
	{
		free((void*) np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}

void printtable(listptr * table, int len)
{
	listptr p;
	int i =0;
	while (i < len) {
		if (table[i] != NULL) {
			for (p = table[i];p!=NULL;p=p->next) {
				printf("%s\t%s\n", p->name, p->defn);
			}
		}
		i++;
	}
}