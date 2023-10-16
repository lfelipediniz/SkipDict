#include "../inc/item.h"

// Estrutura de um nó do dicionário, que carrega consigo a palavra e seu
// significado
struct item_ {
   char *str1;
   char *str2;
};

ITEM *item_criar(char *str1, char *str2) {
   ITEM *item;

   item = (ITEM *)malloc(sizeof(ITEM));

   if (item != NULL) {
      item->str1 = str1;
      item->str2 = str2;
      return (item);
   }

   return (NULL);
}

bool item_apagar(ITEM **item) {
   if (*item != NULL) {
      free(*item);
      *item = NULL;

      return (true);
   }

   return (false);
}

char *item_get_str1(ITEM *item) {
   if (item != NULL) return (item->str1);
   exit(1);
}

char *item_get_str2(ITEM *item) {
   if (item != NULL) return (item->str2);
   exit(1);
}

bool item_set_str1(ITEM *item, char *str1) {
   if (item != NULL) {
      item->str1 = str1;
      return (true);
   }

   return (false);
}

bool item_set_str2(ITEM *item, char *str2) {
   if (item != NULL) {
      item->str2 = str2;
      return (true);
   }

   return (false);
}

int item_compare(ITEM *item1, ITEM *item2) {
   return (strcmp(item1->str1, item2->str2));
}

void item_imprimir(ITEM *item) {
   if (item != NULL) printf("\n-->item: %s : %s\n", item->str1, item->str2);
}