#include <stdio.h>
#include <string.h>
#include "hashtable.h"

#define TABLESIZE 1000

int main()
{
	hashtable *table = init_table(TABLESIZE);


	install(table, "key1", "value1");
	install(table, "key2", "value2");
	install(table, "key3", "value3");
	install(table, "key10", "value10");

	printtable(table, TABLESIZE);

	undef(table, "key2");

	printtable(table, TABLESIZE);

	return 0;
}