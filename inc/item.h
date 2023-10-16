#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>
	#include <stdlib.h>
	#include <stdio.h>

	typedef struct item_ ITEM;

	ITEM *item_criar(char* str1, char* str2);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	char* item_get_str1(ITEM *item);
	char* item_get_str2(ITEM *item);
	bool item_set_str1(ITEM *item, char* str1);
	bool item_set_str2(ITEM *item, char* str1);
	int item_compare(ITEM *item1, ITEM* item2);

#endif
