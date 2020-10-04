#include <stdio.h>
#include <string.h>
#include "hashtable.h"

#define TABLESIZE 1000

int main()
{
	struct hashtable *table = init_table(TABLESIZE);


	install(table->slots, "key1", "value1");
	install(table->slots, "key2", "value2");
	install(table->slots, "key3", "value3");

	printtable(table->slots, TABLESIZE);

	return 0;
}