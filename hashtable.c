#include <stdio.h>
#include <string.h>
#include "hashtable.h"

#define HASHSIZE 101


hashtable * init_table(size_t n_slots)
{
	struct hashtable *tbl = malloc(sizeof(*tbl));
	tbl->n_slots = n_slots;
	tbl->slots = calloc(n_slots, sizeof(*(tbl->slots)));
	return tbl;
}

unsigned hash (char *s)
{
	unsigned hashval;

	for (hashval=0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval;
}

listptr lookup (hashtable * table, char *s)
{
	listptr np;
	listptr *hashtab = table->slots;

	for (np = hashtab[hash(s) % table->n_slots]; np!=NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

listptr install(hashtable * table, char *name, char * defn)
{
	listptr np;
	listptr *hashtab = table->slots;
	unsigned hashval;

	if((np = lookup(table, name)) == NULL) {
		np = (listptr) malloc(sizeof(*np));
		if (np==NULL || (np->name = strdup(name))==NULL)
			return NULL;

		hashval = hash(name) % table->n_slots;
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

void printtable(hashtable * hashtable, int len)
{
	listptr * table = hashtable->slots;
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

int undef(hashtable * hashtable, char * name)
{
	listptr * table = hashtable->slots;
	unsigned hashval = hash(name);
	listptr p;
	listptr prev = NULL;
	listptr np = NULL;
	for (np = table[hashval % hashtable->n_slots]; np!=NULL; prev=np, np=np->next) {
		if (strcmp(name, np->name)==0) {
			if (prev == NULL) {
				table[hashval % hashtable->n_slots] = np->next;
				free(np);
			}
			else {
				prev->next = np->next;
				free(np);
			}
		}
	}
	return 0;
}