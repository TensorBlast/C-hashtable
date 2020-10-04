#include <stdio.h>
#include <string.h>
#include "hashtable.h"

int main()
{
	listptr * table = init_table();


	install(table, "key1", "value1");
	install(table, "key2", "value2");
	install(table, "key3", "value3");

	printtable(table, 101);

	return 0;
}